// stack.cpp
#include "stack.h"

Stack::Stack(int n)
{
    pitems = new Item[n];
    size = n;
    top = -1;
}
Stack::Stack(const Stack & st)
{
    size = st.size;
    pitems = new Item[size];
    for (int i = 0; i <= st.top; i++)
	pitems[i] = st.pitems[i];
    top = st.top;
}
Stack::~Stack()
{
    delete [] pitems;
}
bool Stack::isempty() const
{
    return top == -1;
}
bool Stack::isfull() const
{
    return size == top + 1;
}
bool Stack::push(const Item & item)
{
    if (isfull())
	return false;
    pitems[++top] = item;
    return true;
}
bool Stack::pop(Item & item)
{
    if (isempty())
	return false;
    item = pitems[top--];
    return true;
}
Stack & Stack::operator=(const Stack & st)
{
    if (this == &st)
	return *this;
    delete [] pitems;
    size = st.size;
    pitems = new Item[size];
    for (int i = 0; i <= st.top; ++i)
	pitems[i] = st.pitems[i];
    top = st.top;
    return *this;
}

