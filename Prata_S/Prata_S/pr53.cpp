#include <iostream>
#include <array>

int main()
{
	int i, sum = 0;

	std::cout << "Enter integers:\n";
	std::cin >> i;
	while(i != 0)
	{
		sum += i;
		std::cout << "Sum is: " << sum << std::endl;
		std::cin >> i;
	}
	std::cout << "Sum is: " << sum << std::endl;

	system("pause");
	return 0;
}