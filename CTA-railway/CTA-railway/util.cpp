#include "util.hpp"

str_mat readcsv(string file_name) {
    str_mat mat;
    ifstream file;
    file.open(file_name);
    string line;
    bool end = false;

    if (!file) {
        cout << file_name << " not existing!\n";
        throw "boom!";
    }

    while (!file.eof()) {
        vector<string> newRow;
        getline(file, line);
        SplitString(line, newRow, ",");
        if (!newRow.empty()) {
            mat.push_back(newRow);
        }
    }
    file.close();
    return mat;
}

void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (pos2 != string::npos)
    {
        // prevent null string
        if(s.substr(pos1, pos2 - pos1).compare("") != 0)
            v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

bool str2bool(string str) {
    if (str.compare("TRUE") == 0 || str.compare("true") == 0 || str.compare("True") == 0)
        return true;
    if (str.compare("FALSE") == 0 || str.compare("false") == 0 || str.compare("False") == 0)
        return false;
    cout << "bool value input error!\n";
    throw "bool value input error";
}