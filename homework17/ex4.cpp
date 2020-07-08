// ex4.cpp -- joint two file

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    using namespace std;

    ifstream fin1;
    ifstream fin2;
    ofstream fout;

    if (argc < 4) {
        cerr << "Enter " << argv[0] << " <filename1>"
	     << " <filename2> <filename3>\n";
	exit(0);
    }
    fin1.open(argv[1]);
    fin2.open(argv[2]);
    fout.open(argv[3]);

    if (!fin1.is_open() || !fin2.is_open() || !fout.is_open()) {
        cerr << "Can't open file\n";
	cerr << "Terminated.\n";
	exit(EXIT_FAILURE);
    }
    char ch;
    while (fin1.get(ch)) {
        if (ch == '\n') {
	    fout << ' ';
	    while (fin2.get(ch)) {
	        if (ch == '\n')
		    break;
		fout << ch;
	    }
	}
	fout << ch;
    }
    while (fin2.get(ch))
	fout << ch;

    cout << "Done\n";
    fin1.close();
    fin2.close();
    fout.close();

    return 0;
}
