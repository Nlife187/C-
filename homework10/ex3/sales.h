// sales.h

namespace SALES
{
    class Sales
    {
        private:
	    enum {QUARTERS = 4};
	    double sales[QUARTERS];
	    double average;
	    double max;
	    double min;
	public:	    
       	    Sales(double[], int);
	    Sales();
	    ~Sales();
	    void showSales() const;
    };
};
