#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>

Person::Person(const std::string &ln, const char *fn)
{
	lname = ln;
	strcpy(fname, fn);
}
void Person::Show() const
{
	std::cout << lname << ' ' << fname << std::endl;
}
void Person::FormalShow() const
{
	std::cout << fname << ' ' << lname << std::endl;
}
