#include <iostream>

int main()
{
	unsigned long long worldPopulation;
	unsigned long long USPopulation;

	std::cout << "Enter the world's population: ";		std::cin >> worldPopulation;
	std::cout << "Enter the population of the US: ";	std::cin >> USPopulation;

	std::cout << "The population of the US is " << (long double)USPopulation / ((long double)worldPopulation / 100.0) 
		<< "% of the world population." << std::endl;

	system("pause");
	return 0;
}