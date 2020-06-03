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

    double perhour = 5;
    double aver1, aver2, aver;
    aver1 = 0;
    aver2 = 0;
    while (1)
    {
	Queue line1(qs);
	Queue line2(qs);
        double min_per_cust;
        min_per_cust = MIN_PRE_HR / perhour;
        Item temp;
        long turnaways = 0;
        long customers = 0;
        long served1 = 0;
	long served2 = 0;
        int wait_time1 = 0;
	int wait_time2 = 0;
        long line_wait1 = 0;
	long line_wait2 = 0;
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))
	    {
	        if (line1.isfull() && line2.isfull())
		    turnaways++;
	        else
	        {
		    customers++;
		    temp.set(cycle);
		    if (line1.queuecount() == line2.queuecount() && wait_time1 < wait_time2)
			line1.enqueue(temp);
		    else if (line1.queuecount() < line2.queuecount())
			line1.enqueue(temp);
		    else
			line2.enqueue(temp);
	        }  
	    }
	    if (wait_time1 <= 0 && !line1.isempty())
	    {
	        line1.dequeue(temp);
	        wait_time1 = temp.ptime();
	        line_wait1 += cycle - temp.when();
	        served1++;
	    }
	    if (wait_time2 <= 0 && !line2.isempty())
	    {
		line2.dequeue(temp);
		wait_time2 = temp.ptime();
		line_wait2 += cycle - temp.when();
		served2++;
	    }
	    if (wait_time1 > 0)
	        wait_time1--;
	    if (wait_time2 > 0)
		wait_time2--;
        }
	if (served1 == 0)
	    aver1 = 0;
	else if (served2 == 0)
	    aver2 = 0;
	else
	{
	    aver1 = double(line_wait1) / served1;
	    aver2 = double(line_wait2) / served2;
	}
	cout << "aver1: " << aver1 << ", served1: " << served1 << '\t';
	cout << "aver2: " << aver2 << ", served2: " << served2 << endl;
	perhour += 0.5;
	aver = ((aver1 * served1) + (aver2 * served2)) / (served1 + served2);
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
