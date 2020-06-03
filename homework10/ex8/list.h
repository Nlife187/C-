// list.h

#ifndef LIST_H_
#define LIST_H_

#define data_t long
typedef struct node
{
    struct node *next;
    data_t val;
} Item;

class List
{
    private:
	enum {Max = 30};
        Item *head;
	Item *tail;
	int size;
    public:
	List();
	List(data_t val);
	~List();
	void add(Item * node);
	bool isempty();
	bool isfull();
	void visit(void (*pf)(Item &node));
};
void show(Item &node);
#endif
