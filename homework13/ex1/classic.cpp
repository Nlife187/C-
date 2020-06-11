// classic.cpp
#include <iostream>
#include <cstring>
#include "classic.h"
using namespace std;

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    strncpy(performers, s1, 49);
    strncpy(label, s2, 19);
    selections = n;
    playtime = x;
}
Cd::Cd(const Cd & d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0;
}
Cd::~Cd() {};
void Cd::Report() const
{
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}
Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
	return *this;
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const char * m, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
    strncpy(major, m, 49);
}
Classic::Classic(const char * m, const Cd & d) : Cd(d)
{
    strncpy(major, m, 49);
}
Classic::Classic() : Cd() { }
void Classic::Report() const
{
    Cd::Report();
    cout << "Major: " << major << endl;
}
Classic & Classic::operator=(const Classic & cc)
{
    if (this == &cc)
	return *this;
    Cd::operator=(cc);
    strcpy(major, cc.major);
    return *this;
}
