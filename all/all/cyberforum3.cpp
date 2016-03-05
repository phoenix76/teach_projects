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
			std::cout << "Ёлемент [" << i << "] равен 50.\n";
			count++;
		}
	}
	if(count != 0)
		std::cout << "¬сего элементов равных 50: " << count << std::endl;
	else
		std::cout << "Ёлементов равных 50 нет." << std::endl;
	std::cin.get();
	return 0;
}