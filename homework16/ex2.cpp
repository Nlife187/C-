// ex2.cpp -- is palindromic string
#include <iostream>
#include <string>
#include <cctype>

bool is_palindromic(const std::string &);
std::string transform(const std::string &);

int main()
{
    using std::string;
    using std::cout;
    using std::endl;
    using std::cin;

    string str, temp;
    cout << "Enter a string (quit to quit): ";
    while (getline(cin, str) && str != "quit")
    {
	temp = transform(str);
	if (is_palindromic(str))
	    cout << temp << " is palindromic string\n";
	else
	    cout << temp << " isn't palindromic string\n";
	cout << "Enter a string (quit to quit): ";
    }
    return 0;
}

bool is_palindromic(const std::string & str)
{
    int i;
    int len = str.size();
    for (i = 0; i < len - i; i++) {
	if (str[i] != str[len -1 - i])
	    return false;
    }
    return true;
}

std::string transform(const std::string & str)
{
    int len = str.size();
    int i;
    std::string temp;
    for (i = 0; i < len; i++) {
        if (isalpha(str[i]) || isalnum(str[i])) 
	    temp += tolower(str[i]);
    }
    return temp;
}
