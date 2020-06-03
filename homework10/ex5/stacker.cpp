// stacker.cpp
#include <iostream>
#include "stack.h"
#include <cctype>

int main()
{
    using namespace std;
    customer Ar[5] = {
	{"A", 20},
	{"B", 39},
	{"C", 20},
	{"D", 10},
	{"E", 33}
    };
    Stack st;
    char ch;
    int i;
    customer cus;
    cout << "Enter chioce: P(Push) p(pop) q(quit)";
    while (cin >> ch && toupper(ch) != 'Q')
    {
	while (cin.get() != '\n')
	    continue;
	if (!isalpha(ch))
	{
	    cout << '\a';
	    continue;
	}
	switch(ch)
	{
	    case 'P': cout << "which number: ";
		      while(!(cin>>i) || i > 5)
		      {
			  cin.clear();
			  while(cin.get() != '\n')
			      continue;
			  cout << "try again: ";
		      }
		      if (st.isfull())
			  cout << "Stack  already full\n";
		      else
			  st.push(Ar[i-1]);
		      break;
	    case 'p': if (st.isempty())
			  cout << "Stack already empty\n";
		      else
		      {
			  st.pop(cus);
			  cout << "cus " << cus.fullname << " popped;\n";
		      }
		      break;
	}
        cout << " P to Push, p to pop, q to quit;\n";
    }
    return 0;
}
