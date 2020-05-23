// list.cpp
#include <iostream>
#include "list.h"

List::List()
{
    head = new Item;
    size = 0;
}
List::List(data_t val)
{
    head = new Item;
    head->val = val;
    head->next = NULL;
    tail = head;
    size = 1;
}
List::~List()
{
    std::cout << "Bye!\n";
}
void List::add(Item *node)
{
    if (size == 0)
	tail = head = node;
    else if (size == 1)
    {
	tail = node;
	head->next = tail;
    }
    else
    {
	Item *temp = node;
	tail->next = temp;
	tail = temp;
    }
    size += 1;
}
bool List::isempty()
{
    return size == 0;
}
bool List::isfull()
{
    return size == Max;
}
void show(Item &node)
{
    using namespace std;
    cout << node.val << endl;
}
void List::visit(void (*pf)(Item &node))
{
    using namespace std;
    int i = 0;
    Item *node = head;
    while(node)
    {
	i++;
	cout << "#" << i << " ";
	show(*node);
	node = node->next;
    }
}
