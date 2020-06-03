// sales.cpp
#include <iostream>
#include "sales.h"

using namespace SALES;

Sales::Sales(double ar[], int n)
{
    if (n >= QUARTERS)
	n = QUARTERS;
    int len = 0;
    while (ar[len])
	len++;
    if (n > len)
	n = len;
    int i;
    double total = 0;
    double M = ar[0];
    double m = ar[0];
    for (i = 0; i < n; ++i)
    {
	sales[i] = ar[i];
	if (ar[i] > M)
	    M = ar[i];
	if (ar[i] < m)
	    m = ar[i];
	total += ar[i];
    }
    while (i < QUARTERS)
	sales[i++] = 0;
    max = M;
    min = m;
    average = total / n;
}
Sales::Sales()
{
    using namespace std;
    int i;
    double val;
    double total = 0;
    for (i = 0; i < QUARTERS; ++i)
    {
	cout << "Enter the value of sales[" << i
	     <<"]:";
	while(!(cin >> val))
	{
	    cin.clear();
	    while(cin.get() != '\n')
		continue;
	    cout << "Enter again: ";
	}
	while (cin.get() != '\n')
	    continue;
	sales[i] = val;
	if (i == 0)
	{
	    min = val;
	    max = val;
	}
	else
	{
	    if (val > max)
	        max = val;
	    if (val < min)
		min = val;
	}
	total += val;
    }
    average = total / QUARTERS;
}
Sales::~Sales()
{
    std::cout << "Bye!\n";
}
void Sales::showSales() const
{
    using namespace std;
    int i = 0;
    while (i < QUARTERS)
    {
	cout << sales[i] << " ";
	i++;
    }
    cout << endl;
    cout << "average: " << average
	 << ", Max: " << max
	 << ", Min: " << min << endl;
}
