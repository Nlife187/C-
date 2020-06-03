// stack.h

#ifndef STACK_H_
#define STACK_H_

typedef struct
{
    char fullname[35];
    double payment;
} customer;

class Stack
{
    private:
	enum {Max = 100};
	customer Customers[Max];
	int top;
        double total;
    public:
	Stack();
	~Stack();
	bool isempty() const;
	bool isfull() const;
	void push(const customer &);
	void pop(customer &);	
};

#endif
