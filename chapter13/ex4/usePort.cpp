// usePort.cpp
#include "port.h"

int main()
{
    Port p1 = Port("Gallo", "tawny", 20);
    p1.Show();
    VintagePort p2 = VintagePort("vintii", 99, "Massgy", 1980);
    p2.Show();
    cout << endl << p1;
    cout << endl << p2;
    return 0;
}
