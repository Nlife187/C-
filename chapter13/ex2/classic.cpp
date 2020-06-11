// classic.cpp
#include <iostream>
#include <cstring>
#include "classic.h"
using namespace std;

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    int len1, len2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    performers = new char[len1 + 1];
    label = new char[len2 + 1];
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
Cd::Cd(const Cd & d)
{
    int len1 = strlen(d.performers);
    int len2 = strlen(d.label);
    performers = new char[len1 + 1];
    label = new char[len2 + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::Cd()
{
    performers = new char[1];
    label = new char[1];
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0;
}
Cd::~Cd() 
{
    cout << "delete " << performers << " ";
    delete [] performers;
    cout << "delete " << label << endl;
    delete [] label;
}
void Cd::Report() const
{
    cout << "Performers: " << performers << " ";
    cout << "Label: " << label << " ";
    cout << "Selections: " << selections << " ";
    cout << "Playtime: " << playtime << endl;
}
Cd & Cd::operator=(const Cd & d)
{
    if (this == &d)
	return *this;
    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const char * m, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
    major = new char[strlen(m) + 1];
    strcpy(major, m);
}
Classic::Classic(const char * m, const Cd & d) : Cd(d)
{
    major = new char[strlen(m) + 1];
    strcpy(major, m);
}
Classic::Classic() : Cd()
{
    major = new char[1];
    major[0] = '\0';
}
Classic::~Classic()
{
    cout << "delete major " << major << endl;
    delete [] major;
}
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
    delete [] major;
    major = new char[strlen(cc.major) + 1];
    strcpy(major, cc.major);
    return *this;
}

