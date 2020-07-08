// ex5.cpp -- using file record 
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace std;

    ofstream fout;
    vector<string> Mat;
    vector<string> Pat;
    set<string> Total;

    string name;
    cout << "(Mat) Enter a name: <quit to quit>: ";
    while (getline(cin, name) && name != "quit") {
	Mat.push_back(name);
	cout << "(Mat)Enter a name: <quit to quit>: ";
    }
    sort(Mat.begin(), Mat.end());
    for (auto x : Mat)
	cout << x << endl;
    cout << "Done\n";

    cout << "(Pat) Enter a name: <quit to quit>: ";
    while (getline(cin, name) && name != "quit") {
        Pat.push_back(name);
	cout << "Enter a name: <quit>: ";
    }
    sort(Mat.begin(), Mat.end());
    for (auto x : Pat)
	cout << x << endl;
    cout << "Done\n";

    copy(Mat.begin(), Mat.end(), insert_iterator< set<string> > (Total, Total.begin()));
    copy(Pat.begin(), Pat.end(), insert_iterator< set<string> > (Total, Total.end()));

    fout.open("matnpat.dat");
    if (!fout.is_open()) {
        cerr << "Terminated(can't open)\n";
	exit(EXIT_FAILURE);
    }

    for (auto x : Total)
	fout << x << endl;

    return 0;
}
