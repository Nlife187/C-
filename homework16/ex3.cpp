// ex3.cpp -- using filein to input
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

int main()
{
    using namespace std;

    ifstream fin;
    string filename;
    cout << "Enter a file: ";
    getline(cin, filename);
    fin.open(filename, ios::in);
    if (!fin.is_open()) {
        cout << "Some wrong with " << filename << endl;
	cout << "Program terminated.\n";
	exit(EXIT_FAILURE);
    }
    vector<string> wordlist;
    string word;
    while (fin >> word)
	wordlist.push_back(word);
    cout << "Now we have " << wordlist.size() << " words\n";

    srand(time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    while (play == 'y')
    {
	string target = wordlist[rand() % 26];
	int length = target.size();
	string attempt(length, '-');
	string badchars;
	int guesses = 6;
	cout << "Guess my secret word. It has " << length
	     << " letters, and you guess\n"
	     << "one letter at a time. Your get " << guesses
	     << " wrong guesses.\n";
	cout << "Your word: " << attempt << endl;
	while (guesses > 0 && attempt != target)
	{
	    char letter;
	    cout << "Guess a letter: ";
	    cin >> letter;
	    if (badchars.find(letter) != string::npos
		|| attempt.find(letter) != string::npos) 
	    {
	        cout << "You already guesses that. Try again.\n";
		continue;
	    }
	    unsigned long loc = target.find(letter);
	    if (loc == string::npos)
	    {
		cout << "Oh, bad guess!\n";
		--guesses;
		badchars += letter;
	    }
	    else
	    {
		cout << "Good guess!\n";
		attempt[loc] = letter;
		loc = target.find(letter, loc + 1);
		while (loc != string::npos)
		{
		    attempt[loc] = letter;
		    loc = target.find(letter, loc + 1);
		}
	    }
	    cout << "Your word: " << attempt << endl;
	    if (attempt != target)
	    {
		if (badchars.length() > 0)
		    cout << "Bad choices: " << badchars << endl;
		cout << guesses << " bad guesses left\n";
	    }
	}
	if (guesses > 0)
	    cout << "That's right!\n";
	else
	    cout << "Sorry, the word is " << target << ".\n";
	cout << "Will you play another? <y/n> ";
	cin >> play;
	play = tolower(play);
    }
    cout << "Bye\n";
    
    return 0;
}
