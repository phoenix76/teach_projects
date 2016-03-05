#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float l, km;

	std::cout << "Введите литры и километры:" << std::endl;
	std::cin >> l >> km;

	std::cout << "Расход равен: " << l / km * 100.0f << " литров на 100км." << std::endl;

	system("pause");
	return 0;
}