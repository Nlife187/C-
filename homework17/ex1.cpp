// ex1.cpp -- using peek()
#include <iostream>

int main()
{
    using namespace std;
    int cnt = 0;
    char ch;
    while (cin.peek() != '$') {
        cin.get(ch);
	cout << ch;
	cnt++;
    }
    cout << endl;
    cout << "Before $ there are " << cnt << " characters\n";
    cout << (char)cin.peek() << endl;

    return 0;
}
