#include <iostream>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float l;
	std::cout << "������� ������:\n";
	std::cin >> l;

	float mil = 62.14f / (l / 3.875f);
	std::cout << "������ ����������: " << mil << " ���� �� ������." << std::endl;

	system("pause");
	return 0;
}