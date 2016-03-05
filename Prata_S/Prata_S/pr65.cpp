#include <iostream>

double result(double);

int main()
{
	double val;
	std::cout.precision(4);
	std::cout << "Enter the salary: ";
	std::cin >> val;
	while(!std::cin.fail() && val >= 0)
	{
		std::cout << "Your tax: " << result(val) << "\n\n";
		std::cout << "Enter the salary: ";
		std::cin >> val;
	}
	if(std::cin.fail())
		std::cin.clear();
	while(std::cin.get() != '\n')
		continue;
	std::cin.get();
	return 0;
}

double result(double salary)
{
	if(salary <= 5000.0)
		return 0.0;
	else if(salary > 5000.0 && salary <= 15000.0)
		return (salary - 5000.0) * 0.10;
	else if(salary > 15000.0 && salary <= 35000.0)
		return 10000.0 * 0.10 + (salary - 15000.0) * 0.15;
	else
		return 10000.0 * 0.10 + 20000.0 * 0.15 + (salary - 35000.0) * 0.20;
}