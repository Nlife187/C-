// randwalk.cpp --using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>    // rand(), srand() prototype
#include <ctime>      // time() prototype
#include <fstream>
#include "vector.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    ofstream fout;
    fout.open("randwalk.txt");
    if (!fout.is_open())
    {
        cout << "can't open randwalk.txt\n";
	cout << "Program terminating.\n"; 
	exit(EXIT_FAILURE);
    }
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
	max = 0;
	min = target;
	cout << "Enter step length: ";
	if (!(cin >> dstep))
	    break;
	fout.precision(3);
	fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
	while (result.magval() < target)
	{
	    fout << steps << ": " << result << endl;
	    direction = rand() % 360;
	    step.reset(dstep, direction, Vector::POL);
	    result = result + step;
	    steps++;
	}
	fout << "After " << steps << " steps, the subject "
	     << "has the following location:\n";
	fout << result << endl;
	result.polar_mode();
	fout << " or\n" << result << endl;
	fout << "Maximum "
	fout << "Average outward distance per step = "
	     << result.magval()/steps << endl;
	steps = 0;
	result.reset(0.0, 0.0);
	cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
	continue;
    return 0;
}
