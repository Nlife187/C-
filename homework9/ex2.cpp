// statci.cpp -- using a statci local variable
#include <iostream>
#include <string>

void strcout(const std::string &);

int main(void)
{
    using namespace std;
    string str;
    getline(cin, str);
    cout << "Enter a line:\n";
    while (str != "")
    {
	
	strcout(str);
	cout << "Enter next line (empty line to quit):\n";
	getline(cin, str);
    }
}
void strcout(const std::string & str)
{
    using namespace std;
    static int total = 0;
    int count = 0;

    cout << "\"" << str << "\" contains ";
    int i = 0;
    while (str[i])
    {
	count++;
	i++;
    }
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
