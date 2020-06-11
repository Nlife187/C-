// lister.cpp
#include <iostream>
#include "list.h"
#include <cctype>
#define Size sizeof(Item)

const int BUF = Size * 30;
void assign(Item *);
static char buffer[BUF]; 

int main()
{
    using namespace std;
    List A_list;
    char ch;
    cout << "Enter your choice: a) add; v) visit q) quit ";
    int i = 0;
    while (cin >> ch && toupper(ch) != 'Q')
    {
	Item *node = new(buffer + Size * i) Item;
	cout << "node addrees = " << (void *) node << endl;
	while(cin.get() != '\n')
	    continue;
	if (!isalpha(ch))
	{
	    cout << '\a';
	    continue;
	}
	switch(ch)
	{
	    case 'a':
	    case 'A': assign(node);
		      A_list.add(node);
		      break;
	    case 'v':
	    case 'V': A_list.visit(show);
		      break;
	}
	i++;
	cout << "Enter your choice: a) add v) visit q) quit ";
    }
    return 0;
}
void assign(Item *node)
{
    using namespace std;
    cout << "Enter the value:";
    data_t val;
    while(!(cin >> val))
    {
	cin.clear();
	while (cin.get() != '\n')
	    continue;
	cout << "Enter again: ";
    }
    while(cin.get() != '\n')
	continue;
    node->val = val;
}
