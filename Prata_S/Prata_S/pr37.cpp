#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float l;
	std::cout << "Введите расход:\n";
	std::cin >> l;

	float mil = 62.14f / (l / 3.875f);
	std::cout << "Расход составляет: " << mil << " миль на галлон." << std::endl;

	system("pause");
	return 0;
}