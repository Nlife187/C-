// ex7.cpp -- create lotto()
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> Lotto(int , int);

int main()
{
    vector<int> winners;
    winners = Lotto(51, 6);
    for (auto x : winners)
	cout << x << ' ';
    cout << endl;

    return 0;
}

vector<int> Lotto(int total, int number)
{
    srand(time(0));
    int i;
    vector<int> winners;
    vector<int> pool;
    for (i = 0; i < total; i++)
	pool.push_back(i + 1);
    for (i = 0; i < number; i++)
    {
	int randNumber = rand() % pool.size();
	winners.push_back(pool[randNumber - 1]);
	pool.erase(pool.begin() + randNumber - 1, pool.begin() + randNumber);
    }

    return winners;
}
