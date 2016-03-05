#include <iostream>

long double Factorial(int);

int main()
{
	int fact;
	std::cin >> fact;
	std::cout << Factorial(fact);

	std::cin.get();
	std::cin.get();
	return 0;
}

long double Factorial(int n)
{
	if(n == 1)
		return 1.0;
	return Factorial(n - 1) * n;
}