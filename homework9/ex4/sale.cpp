// sale.cpp
#include <iostream>
#include "SALES.h"

int main()
{
    using namespace SALES;
    using std::cout;
    using std::cin;
    using std::endl;
    Sales S1, S2;
    double ar[6] = {1, 2, 3, 4, 5, 6};
    setSales(S1, ar, 5);
    showSales(S1);
    setSales(S2);
    showSales(S2);

    return 0;
}
