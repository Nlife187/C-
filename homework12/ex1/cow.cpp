// cow.cpp
#include <iostream>
#include <cstring>
#include "cow.h"

using std::cout;

Cow::Cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
    int len1 = strlen(nm);
    len1 = len1 < 20 ? len1 : 19;
    strncpy(name, nm, len1);
    int len2 = strlen(ho);
    hobby = new char[len2 + 1];
    strcpy(hobby, ho);
    weight = wt;
}
Cow::Cow(const Cow & c)
{
    strcpy(name, c.name);
    int len;
    len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
Cow::~Cow()
{
    cout << "delete hobby ";
    delete [] hobby;
    cout << "Bye!\n";
}
Cow & Cow::operator=(const Cow & c)
{
    if (this == &c)
	return *this;
    strcpy(name, c.name);
    delete [] hobby;
    int len;
    len = strlen(c.name);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}	
void Cow::ShowCow() const
{
    int len = strlen(name);
    cout << "name: ";
    for (int i = 0; i < len; ++i)
        cout << name[i];
    cout << '\n';
    cout << "Name's address: " << (void *)name << '\n';
    cout << "Hobby: " << hobby << '\n';
    cout << "Hobby's address: " << (void *)hobby << '\n';
    cout << "Weight: " << weight << '\n';
    cout << "Weight's address: " << (void *)&weight << '\n';
}
