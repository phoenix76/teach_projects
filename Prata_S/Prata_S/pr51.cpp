#include <iostream>

int main()
{
	int a = 0, b = 0, sum = 0;
	std::cout << "Enter two integers:\n";
	std::cin >> a >> b;

	for(; a <= b; a++)
	{
		sum += a;
	}

	std::cout << "Sum is: " << sum << std::endl;

	system("pause");
	return 0;
}