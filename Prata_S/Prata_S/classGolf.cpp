#define _CRT_SECURE_NO_WARNINGS
#include "classGolf.h"
#include <iostream>

CGolf::CGolf(const char *name, int hc)
{
	strcpy(m_fullname, name);
	m_handicap = hc;
}
void CGolf::SetGolf()
{
	char temp[LEN];
	int thc;
	std::cout << "Enter a name: ";
	std::cin.getline(temp, LEN);
	std::cout << "Enter a handicap: ";
	std::cin >> thc;
	std::cin.get();
	*this = CGolf(temp, thc);
}
void CGolf::Handicap(int val)
{
	if(val >= 0)
		m_handicap = val;
	else
		std::cout << "Handicap can't be a negative value.\n";
}
void CGolf::Show() const
{
	std::cout << "Name: " << m_fullname << '\n' << "Handicap: " << m_handicap << std::endl;
}