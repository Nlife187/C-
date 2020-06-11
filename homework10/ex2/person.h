// person.h
#include <string>

#ifndef PERSON_H_
#define PERSON_H_

class Person
{
    private:
	static const LIMIT = 25;
	std::string lname;
	char fname[LIMIT];
    public:
	Person() {lname = "", fname[0] = '\0'; }
	Person(const std::string & ln, const char * fn = "Heyyou");
	void Show() const; // firstname lastname format
	void FormalShow() const; // lastname, firstname format
};
