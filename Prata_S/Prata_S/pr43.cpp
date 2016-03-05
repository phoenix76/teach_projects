#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main()
{
	char firstName[50];
	char lastName[50];
	char finalStr[100];

	std::cout << "Enter you first name: ";
	std::cin.getline(firstName, 50);
	std::cout << "Enter you last name: ";
	std::cin.getline(lastName, 50);

	std::strcpy(finalStr, lastName);
	std::strcat(finalStr, ", ");
	std::strcat(finalStr, firstName);

	std::cout << "Here's the information in a single string: " << finalStr << std::endl;

	system("pause");
	return 0;
}