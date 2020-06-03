// ex3 -- static buffer and dynamic buffer
#include <iostream>
#include <cstring>
const int BUF = 100;
static char buffer[BUF]; //infile linkage

struct chaff
{
    char dross[20];
    int slag;
};

void getdata(chaff *, int );
void showstrt(const chaff *, int);

int main(void)
{
    using namespace std;
    chaff *buffer1 = new chaff[2];
    chaff *buffer2 = new(buffer) chaff[2];
    getdata(buffer1, 2);
    cout << endl;
    getdata(buffer2, 2);
    cout << "&buffer1 = " << (void *) buffer1 << endl;
    cout << "&buffer2 = " << (void *) buffer2 << endl;
    showstrt(buffer1, 2);
    showstrt(buffer2, 2);

    return 0;
}
void getdata(chaff * buffer, int size)
{
    using namespace std;
    int i = 0;
    while (i < size)
    {
        char dross[20];
	int slag;
        cout << "Enter the dross: ";
	cin.get(dross, 20);
        while(!cin)
	{
	    cin.clear();
	    while (cin.get() != '\n')
		continue;
	    cout << "Enter the dross again: ";
	    cin.get(dross, 20);
	}
        strcpy(buffer[i].dross, dross);
	cout << "Enter the slag: ";
	cin >> slag;
	while (!cin)
	{
	    cin.clear();
	    while (cin.get() != '\n')
		continue;
	    cout << "Enter the slag agian: ";
	    cin >> slag;
	}
	while (cin.get() != '\n')
	   continue;
	buffer[i].slag = slag;
	i++;
    }
}
void showstrt(const chaff * buffer, int size)
{
    using namespace std;
    int i;
    for (i = 0; i < size; ++i)
    {
	cout << "dross: " << buffer[i].dross;
	cout << ", slag: " << buffer[i].slag << "\n";
    }
}
