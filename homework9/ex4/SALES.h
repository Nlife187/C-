// SALES.h
namespace SALES
{
    const int QUARTERS = 4;
    typedef struct 
    {
	double sales[QUARTERS];
	double average;
	double max;
	double min;
    } Sales;
    // copies the lesser of 4 or n items from array ar
    // to the sales member of s and computer and stores the
    // average, maximum, and mininum values of the entered items
    // remaining elements of sales, if any, set to 0
    void setSales(Sales & s, const double ar[], int n);
    // gathers sales for 4 quraters interactively, stores them
    // in the sales member of s and computes an stores the
    // average, maximum, and minimum values
    void setSales(Sales & s);
    // display all information in structure s
    void showSales(const Sales & s);
}

