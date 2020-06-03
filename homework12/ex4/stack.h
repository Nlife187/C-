// stack.h
#ifndef STACK_H_
#define STACK_H_
typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};  // constant specific to class
    Item * pitems;    // holds stack items
    int size;         // number of elements in stack
    int top;          // index of top stack item
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator=(const Stack & st);
};

#endif
