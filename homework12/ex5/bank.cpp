// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PRE_HR = 60;

bool newcustomer(double x);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));  // random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PRE_HR * hours;

    double perhour = 1.0;
    double aver;
    while (1)
    {
	Queue line(qs);
        double min_per_cust;
        min_per_cust = MIN_PRE_HR / perhour;
        Item temp;
        long turnaways = 0;
        long customers = 0;
        long served = 0;
        int wait_time = 0;
        long line_wait = 0;
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
	    {
	        if (line.isfull())
		    turnaways++;
	        else
	        {
		    customers++;
		    temp.set(cycle);
		    line.enqueue(temp);
	        }  
	    }
	    if (wait_time <= 0 && !line.isempty())
	    {
	        line.dequeue(temp);
	        wait_time = temp.ptime();
	        line_wait += cycle - temp.when();
	        served++;
	    }
	    if (wait_time > 0)
	        wait_time--;
        }
	aver = double(line_wait) / served;
	cout << "aver_wait: " << aver << endl;
	perhour += 0.1;
	if (aver > 1)
	    break;
    }
    cout << "When the number of cumstomers of perhour equal to " << perhour
	 << ", average waitting time equal to 1 minute.\n"; 
    return 0;
}
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); 
}
