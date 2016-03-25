#include "classGolf.h"
#include <iostream>

int main()
{
	std::cout << "Creating an empty object CGolf():\n";
	CGolf one = CGolf();
	one.Show();
	std::cout << "Creating the initialize object:\n";
	CGolf two = { "Two object", 120 };
	two.Show();
	std::cout << "Test SetGolf():\n";
	one.SetGolf();
	one.Show();
	std::cout << "Test Handicap():\n";
	two.Handicap(150);
	two.Show();

	std::cin.get();
	return 0;
}