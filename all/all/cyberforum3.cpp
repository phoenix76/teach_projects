#include <iostream>
#include <Windows.h>
#include <ctime>

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int arr[20];
	for(int i = 0; i < 20; i++)
		arr[i] = rand() % 201 - 100;
	int count = 0;
	for(int i = 0; i < 20; i++)
	{
		if(arr[i] == 50)
		{
			std::cout << "������� [" << i << "] ����� 50.\n";
			count++;
		}
	}
	if(count != 0)
		std::cout << "����� ��������� ������ 50: " << count << std::endl;
	else
		std::cout << "��������� ������ 50 ���." << std::endl;
	std::cin.get();
	return 0;
}