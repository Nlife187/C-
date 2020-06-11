// useStack.cpp 
#include <iostream>
#include "stack.h"

int main()
{
    using namespace std;
    Stack stack1;
    Stack stack2(20);
    Item value;
    char ch;
    while (!stack1.isfull())
    {
	cout << "Enter your operation: p)push P)pop; q)quit: ";
	cin >> ch;
	cin.get();
	if (ch == 'p')
	{
	    cout << "Enter the value: ";
	    while (!(cin >> value))
 	    {
	        cin.clear();
	        while (cin.get() != '\n')
		    continue;
	        cout << "Enter again: ";
	    }
	    while (cin.get() != '\n')
	        continue;
	    stack1.push(value);
	}
	else if (ch == 'P')
	{
	    if (stack1.isempty())
	    {
		cout << "stack is empty, can't pop\n";
	    }
	    else
	    {
	        stack1.pop(value);
	        cout << value << " popped\n";
	    }
	}
	else if (ch == 'q')
	    break;
    }
    stack2 = stack1;
    while (!stack2.isempty())
    {
	stack2.pop(value);
	cout << value << " ";
    }
    cout << endl;

    return 0;
}
