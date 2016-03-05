#include <iostream>

int main()
{
	unsigned int quantity;
	int dot;

	std::cout << "Enter the quantity of the lines: ";
	std::cin >> quantity;
	dot = quantity;

	for(int i = 1; i <= quantity; i++)
	{
		for(int k = quantity - i; k > 0; k--)
			std::cout << '.';
		for(int k = i; k > 0; k--)
			std::cout << '*';
		std::cout << '\n';
	}

	system("pause");
	return 0;
}