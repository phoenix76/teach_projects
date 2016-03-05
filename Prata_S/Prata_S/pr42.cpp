#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string name, desert;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	std::cout << "Enter your favotite desert: ";
	std::getline(std::cin, desert);
	std::cout << "I have some delicious " << desert << " for you, " << name << '.' << std::endl;

	system("pause");
	return 0;
}