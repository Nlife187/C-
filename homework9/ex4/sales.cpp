// sales.cpp -- definition functions
#include <iostream>
#include "SALES.h"

namespace SALES
{
    using std::cout;
    using std::cin;

    void setSales(Sales & s, const double ar[], int n)
    {
	if (n >= 4)
	    n = 4;
	if (n < 1)
	    return;
	int i;
	for(i = 0; i < n; ++i)
	    s.sales[i] = ar[i];
	double total = s.sales[0];
	double max = s.sales[0];
	double min = s.sales[0];
	for(i = 1; i < n; ++i)
	{
	    if (ar[i] > max)
		max = ar[i];
	    else if (ar[i] < min)
		min = ar[i];
	    total += ar[i];
	}
	s.average = total / n;
	s.max = max;
	s.min = min;
    }
    void setSales(Sales & s)
    {
	using namespace std;
	int i;
	double sale;
	double total = 0;
	double max = 0;
	double min = 0;
	for (i = 0; i < 4; ++i)
	{
	    cout << "Enter the sale: ";
	    while (!(cin >> sale))
	    {
		cin.clear();
		while (cin.get() != '\n')
		    continue;
		cout << "Enter the right sale: ";
	    }
	    while(cin.get() != '\n')
		continue;
	    s.sales[i] = sale;
	    total += sale;
	    if (i == 0)
	    {
		min = sale;
		max = sale;
	    }
	    if (sale < min)
		min = sale;
	    if (sale > max)
		max = sale;
	}
	s.average = total / 4;
	s.max = max;
	s.min = min;
    }
    void showSales(const Sales & s)
    {
	using std::cout;
	int i;
	for (i = 0; i < 4; ++i)
	    cout << "sales[" << i << "] = " << s.sales[i] << " ";
	cout << "\n";
	cout << "average = " << s.average << "\n";
	cout << "max = " << s.max << "\n";
	cout << "min = " << s.min << "\n";
    }
}
