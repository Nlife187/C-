// ex9.cpp -- using list and vector 
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iterator>

const int SIZE = 100000;

int main()
{
    using namespace std;

    srand(time(0));
    vector<int> vi0(SIZE);
    int i;
    for (i = 0; i < SIZE; i++)
	vi0[i] = rand() % 100;
    
    vector<int> vi(SIZE);
    list<int> li(SIZE);
    copy(vi0.begin(), vi0.end(), vi.begin());
    copy(vi0.begin(), vi0.end(), li.begin());
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "Sort vector: " << (double) (end - start) / CLOCKS_PER_SEC << " seconds" << endl;
 
    start = clock();
    li.sort();
    end = clock();
    cout << "Sort list: " << (double) (end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    copy(vi0.begin(), vi0.end(), li.begin());
    li.sort();
    copy(li.begin(), li.end(), vi.begin());
    end = clock();
    cout << "Copy Sort Copy: " << (double) (end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
