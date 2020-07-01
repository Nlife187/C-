// ex5 -- reduce array using unique()
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template <class Type>
int reduce(Type ar[], int n);


int main()
{
    long ar1[7] = {3, 4, 1, 6, 3, 2, 1};
    string ar2[7] = {"you", "and", "me", "me", "and", "him", "ok"};
    int num;
    num = reduce(ar1, 7);
    std::cout << num << " elements left in ar\n";
    num = reduce(ar2, 7);
    std::cout << num << " elements left in ar\n";

    return 0;
}

template <class Type>
int reduce(Type ar[], int n)
{
    int i;
    std::sort(ar, ar + n);
    Type * last = std::unique(ar, ar + n);
    for (i = 0; i < n; i++)
	if (ar + i == last)
	    break;
        else
	    std::cout << ar[i] << ' ';
    std::cout << '\n';
    
    return i; 
}
