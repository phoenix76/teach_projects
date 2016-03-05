#include <iostream>

long double process(double, double);

int main()
{
	double cards1, cards2, choices1, choices2;
	std::cout << "Enter the number of cards one and number of choices:\n";
	std::cin >> cards1 >> choices1;
	std::cout << "Enter the number of cards two and number of choices:\n";
	std::cin >> cards2 >> choices2;
	std::cout << "Your chance for win one in " << process(cards1, choices1) * process(cards2, choices2) << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}

long double process(double cards, double choices)
{
	long double result = 1.0;
	long double n;
	unsigned p;
	for(n = cards, p = choices; p > 0; n--, p--)
		result = result * n / p;
	return result;
}