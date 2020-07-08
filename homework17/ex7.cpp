#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

using namespace std;
 
class Store
{
private:
    ofstream & out;
public:
    Store(ofstream & fout) : out(fout) {}
    void operator() (const string &str)
    {    
	size_t len = str.size();
	out.write((char *)&len, sizeof(size_t));
	out.write(str.data(), len);
    }
};

void ShowStr(const string &str);
void GetStrs(ifstream &is, vector<string> &vistr);

int main()
{
    vector<string> vostr;
    string temp;

    cout << "Enter string (empty line to quit): \n";
    while (getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}
 
void ShowStr(const string &str)
{
    cout << str << '\n';
}
 
void GetStrs(ifstream &in, vector<string> &vistr)
{
    string temp;
    size_t len;
    while (in.read((char *)&len, sizeof(size_t)))
    {
	char str[len];
	in.read(str, len);
	temp = str;
	vistr.push_back(temp);
    }
}

