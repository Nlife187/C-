// string2.cpp -- String class methods
#include <cstring>
#include "string2.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}
String::String(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}
String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
String::String(const String & st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}
String::~String()
{
    --num_strings;
    delete[] str;
}
void String::stringlow()
{
    int i = 0;
    while(str[i])
    {
	str[i] = tolower(str[i]);
	i++;
    }
}
void String::stringup()
{
    int i = 0;
    while(str[i])
    {
	str[i] = toupper(str[i]);
	i++;
    }
}
int String::has(const char ch) const
{
    int count = 0, i = 0;
    while(str[i++])
    {
	if (str[i] == ch)
	    ++count;
    }
    return count;
}
String & String::operator=(const String & st)
{
    if (this == &st)
	return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}
String & String::operator=(const char *s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}
String & String::operator+(const String & st)
{
    int len1, len2;
    len1 = strlen(str);
    len2 = strlen(st.str);
    char *strplus = new char[len1 + len2 + 1];
    strcpy(strplus, str);
    strcat(strplus, st.str);
    delete [] str;
    str = strplus;
    return *this;
}
char & String::operator[](int i)
{
    return str[i];
}
const char & String::operator[](int i) const
{
    return str[i];
}
bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}
bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
	st = temp;
    while (is && is.get() != '\n')
	continue;
    return is;
}
String operator+(const char * str, const String & st)
{
    String temp = str;
    temp = temp + st;
    return temp;
}
