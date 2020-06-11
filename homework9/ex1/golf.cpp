// golf.cpp -- definition the function in golf.h
#include <iostream>
#include "golf.h"

void setgolf(golf & g, char * name, int hc)
{
    int i = 0;
    while (*name)
	g.fullname[i++] = *name++;
    g.handicap = hc;
}
int setgolf(golf & g)
{
    using namespace std;
    char name[Len];
    int hc;
    cout << "Enter golf's name: ";
    cin.getline(name, Len);
    cout << "Enter golf' handicap: ";
    while (!(cin >> hc))
    {
	cin.clear();
	while (cin.get() != '\n')
	    continue;
	cout << "Enter the right value: ";
    }
    int i = 0;
    while (name[i])
    {
	g.fullname[i] = name[i];
	i++;
    }
    g.handicap = hc;
    if (g.fullname)
	return 1;
    else
	return 0;
}
void handicap(golf & g, int hc)
{
    g.handicap = hc;
}
void showgolf(const golf & g)
{
    using namespace std;
    cout << "name: " << g.fullname;
    cout << ", handicap: " <<  g.handicap << endl;
}
