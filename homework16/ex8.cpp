// ex8 -- using list and set
#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

void Show(string);

int main()
{
    list<string> MatF;
    list<string> PatF;
    set<string> total;
    string friendName;
    cout << "Enter Mat's Friend Name: ";
    while (cin >> friendName && friendName != "quit")
	MatF.push_back(friendName);
    cout << "Enter Pat's Friend Name: ";
    while (cin >> friendName && friendName != "quit")
	PatF.push_back(friendName);
    PatF.sort();
    MatF.sort();
    MatF.merge(PatF);
    copy(MatF.begin(), MatF.end(), 
	insert_iterator<set<string>> (total, total.begin()));
    for (auto x: total)
	cout << x << ' ';
    cout << endl;

    return 0;
}
