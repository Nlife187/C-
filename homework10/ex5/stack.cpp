// stack.cpp
#include <iostream>
#include "stack.h"

Stack::Stack()
{
    top = 0;
    total = 0.0;
}
Stack::~Stack()
{
    std::cout << "Bye~\n" << "total: " << total << '\n';
}
bool Stack::isempty() const
{
    return top == 0;
}
bool Stack::isfull() const
{
    return top == Max;
}
void Stack::push(const customer & C)
{
    if (top == Max)
    {
	std::cout << "Stack is full\n";
	return;
    } 
    Customers[top++] = C;
    return;
}
void Stack::pop(customer & C)
{
    if (top > 0)
    {
	C = Customers[--top];
	total += C.payment;
	return;
    }
    else
	return;
}



