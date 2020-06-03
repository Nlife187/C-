// useCow.cpp
#include <iostream>
#include "cow.h"

int main()
{
    using std::cin;
    using std::cout;
    char ho[40];
    char name[20];
    cout << "Enter your name: ";
    cin.get(name, 20);
    while (cin)
    {
	if (cin.get() != '\n')
	    continue;
	break;
    }
    cout << "Enter the hobby:\n";
    cin.get(ho, 40);
    while (cin)
    {
	if (cin.get() != '\n')
	    continue;
	break;
    }
    Cow cow1;
    Cow cow2(name, ho, 130);
    Cow cow3 = cow2;
    cow1 = cow3;
    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();

    return 0;
}
