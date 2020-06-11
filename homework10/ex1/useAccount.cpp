// useAccount.cpp
#include <iostream>
#include <cctype>
#include "account.h"

int main()
{
    using namespace std;
    std::string name;
    std::string account;
    Account Ac {"Lee", "334412"};
    float money;
    char ch;
    cout << "Mune:\n"
	 << "A)save    W)withdraw\n"
	 << "S)show    Q)quit\n"
	 << ">> "; 
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
	    case 'A':
	    case 'a': cout << "Enter money you want to save:";
		      cin >> money;
		      Ac.save(money);
		      break;
	    case 'W':
	    case 'w':
		      cout << "Enter money you want to withdraw:";
		      cin >> money;
		      Ac.withdraw(money);
		      break;
	    case 's':
	    case 'S':
		      Ac.show();
		      break;
	}
	cout << "choice: ";
    }
    cout << "Bye!\n";
    return 0;
}
