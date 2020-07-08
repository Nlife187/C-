// ex3.cpp -- copy file
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    using namespace std;
    ifstream fin;
    ofstream fout;
    
    if (argc == 1 || argc == 2) {
        cout << "Enter " << argv[0] << "<filename1> <filename2>\n";
	exit(0);
    }

    fin.open(argv[1], ios_base::in);
    fout.open(argv[2], ios_base::out | ios_base::trunc);

    if (!fin.is_open()) {
        cerr << "Can't open file " << argv[1] << endl;
	cerr << "Program terminated.\n";
	fin.clear();
	exit(EXIT_FAILURE);
    }
    if (!fout.is_open()) {
        cerr << "Can't open file " << argv[2] << endl;
	cerr << "Program terminated.\n";
	fout.clear();
	exit(EXIT_FAILURE);
    }
    char ch;
    while (fin.read(&ch, sizeof ch))
	fout.write(&ch, sizeof ch);

    fin.close();
    fout.close();
    cout << "Done.\n";
    return 0;
}
