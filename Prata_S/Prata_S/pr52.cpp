#include <iostream>
#include <array>

int main()
{
	const short arsize = 101;
	std::array<long double, arsize>factorials;

	factorials[1] = factorials[0] = 1.0;
	for(int i = 2; i < arsize; i++)
		factorials[i] = i * factorials[i - 1];

	for(int i = 0; i < arsize; i++)
		std::cout << i << "! = " << factorials[i] << std::endl;

	system("pause");
	return 0;
}