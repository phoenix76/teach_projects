#include <iostream>
#include <array>

struct car
{
	char name[100];
	unsigned int year;
};

int main()
{
	unsigned short count;
	unsigned short numberOfAuto = 1;
	std::cout << "Count of auto? ";
	std::cin >> count;

	car *cars = new car[count];

	for(int i = 0; i < count; i++, numberOfAuto++)
	{
		std::cout << "Auto #" << numberOfAuto << ':' << std::endl;
		std::cout << "Name: ";
		std::cin >> cars[i].name;
		std::cout << "Year: ";
		std::cin >> cars[i].year;
	}

	std::cout << "This is your collection:\n";
	for(int i = 0; i < count; i++)
	{
		std::cout << cars[i].year << ' ' << cars[i].name << std::endl;
	}

	system("pause");
	return 0;
}