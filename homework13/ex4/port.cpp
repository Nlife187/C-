// port.cpp methods
#include <cstring>
#include "port.h"

Port::Port(const char *br, const char * st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strncpy(style, st, 19);
    bottles = b;
}
Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}
Port & Port::operator=(const Port & p)
{
    if (this == &p)
	return *this;
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}
Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}
Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}
void Port::Show() const 
{
    cout << "Brand: " << brand << "\n"
	 << "Kind: " << style << "\n"
	 << "Bottles: " << bottles << "\n";
}
ostream & operator<<(ostream & os, const Port & p)
{
    cout << p.brand << ", " << p.style << ", " << p.bottles <<"\n";
    return os;
}

VintagePort::VintagePort() : Port()
{
    nickname = new char[1];
    nickname[0] = '\0';
}
VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "none", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == & vp)
	return *this;
    delete [] nickname; 
    VintagePort::operator=(vp);
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}
void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year;
}
ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (Port &) vp;
    os << vp.nickname << ", " << vp.year << endl;
    return os;
}
