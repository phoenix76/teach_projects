#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float l, km;

	std::cout << "������� ����� � ���������:" << std::endl;
	std::cin >> l >> km;

	std::cout << "������ �����: " << l / km * 100.0f << " ������ �� 100��." << std::endl;

	system("pause");
	return 0;
}