// Mgolf.cpp -- tesing function 
#include <iostream>
#include "golf.h"

int main(void)
{
    using namespace std;
    golf ann;
    // using first setgolf
    setgolf(ann, (char *)"Ann Birdfree", 24);
    showgolf(ann);
    // using overloading setgolf
    setgolf(ann);
    showgolf(ann);
    // using handicap to change the int value;
    handicap(ann, 10);
    showgolf(ann);
    return 0;
}
