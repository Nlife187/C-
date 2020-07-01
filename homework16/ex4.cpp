// ex4 -- reduce array using unique()
#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);


int main()
{
    long ar[7] = {3, 4, 1, 6, 3, 2, 1};
    int num;
    num = reduce(ar, 7);
    std::cout << num << " elements left in ar\n";

    return 0;
}

int reduce(long ar[], int n)
{
    int i;
    std::sort(ar, ar + n);
    long * last = std::unique(ar, ar + n);
    for (i = 0; i < n; i++)
	if (ar + i == last)
	    break;
        else
	    std::cout << ar[i] << ' ';
    std::cout << '\n';
    
    return i; 
}
