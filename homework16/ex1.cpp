// ex1.cpp -- is palindromic string
#include <iostream>
#include <string>

bool is_palindromic(std::string &);

int main()
{
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;

    string str;
    cout << "Enter a string (quit to quit): ";
    while (getline(cin, str) && str != "quit")
    {
	if (is_palindromic(str))
	    cout << str << " is palindromic string\n";
	else
	    cout << str << " isn't palindromic string\n";
	cout << "Enter a string (quit to quit): ";
    }
    return 0;
}

bool is_palindromic(std::string & str)
{
    int i;
    int len = str.size();
    for (i = 0; i < len - i; i++) {
	if (str[i] != str[len -1 - i])
	    return false;
    }
    return true;
}
