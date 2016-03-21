#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "golf.h"

void setgolf(golf &g, const char *name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}
int setgolf(golf &g)
{
	std::cout << "Enter a name: ";
	std::cin.getline(g.fullname, 40);
	std::cout << "Enter handicap: ";
	std::cin >> g.handicap;
	while(std::cin.get() != '\n');
	if(!g.fullname)
		return  1;
	else
		return 0;
}
void handicap(golf &g, int hc)
{
	g.handicap = hc;
}
void showgolf(const golf &g)
{
	std::cout << "Name: " << g.fullname << std::endl;
	std::cout << "Handicap: " << g.handicap << std::endl;
}