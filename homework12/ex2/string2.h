// string2.h -- fixed and augmented string class definition

#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
#include <cctype>
using std::ostream;
using std::istream;

class String
{
    private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;   // cin input limit
    public:
	String(const char *s);
	String();
	String(const String &); // copy constructor
	~String();
	int length() const { return len; }
	void stringlow();
	void stringup();
	int has(const char) const;
	
	String & operator=(const String &);
	String & operator=(const char *);
	String & operator+(const String &);
	char & operator[](int i);
	const char & operator[](int i) const;

	friend bool operator<(const String &st1, const String & st2);
	friend bool operator>(const String &st1, const String & st2);
	friend bool operator==(const String &st1, const String & st2);
	friend ostream & operator<<(ostream & os, const String &st);
	friend istream & operator>>(istream & is, String & st);
	friend String operator+(const char *, const String &);
	static int HowMany();
};

#endif
