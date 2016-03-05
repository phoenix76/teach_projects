/*#include <iostream>

void calculate(double, double, double(*pf[])(double, double));

double sum(double, double);
double subtract(double, double);
double multiply(double, double);
double division(double, double);

int main()
{
	double(*pfunc[4])(double, double) = { sum, subtract, multiply, division };
	double a, b;
	std::cout << "Enter operands, q to quit:\n";
	while(std::cin >> a >> b)
	{
		calculate(a, b, pfunc);
		std::cout << '\n' << "Enter operands, q to quit:\n";
	}
	std::cin.clear();
	while(std::cin.get() != '\n');
	std::cin.get();
	return 0;
}
void calculate(double a, double b, double(*pf[])(double, double))
{
	std::cout << "Sum of integers: " << (*pf[0])(a, b) << '\n';
	std::cout << "Substract of integers: " << (*pf[1])(a, b) << '\n';
	std::cout << "Multiply of integers: " << (*pf[2])(a, b) << '\n';
	std::cout << "Division of integers: " << (*pf[3])(a, b) << '\n';
}
double sum(double a, double b)
{
	return a + b;
}
double subtract(double a, double b)
{
	return a - b;
}
double multiply(double a, double b)
{
	return a * b;
}
double division(double a, double b)
{
	return a / b;
}*/


#include <iostream>

double calculate(double, double, double(*pf)(double, double));

double sum(double, double);
double subtract(double, double);
double multiply(double, double);
double division(double, double);

int main()
{
	double a, b;
	std::cout << "Enter operands, q to quit:\n";
	while(std::cin >> a >> b)
	{
		std::cout << "Sum of arguments: " << calculate(a, b, sum) << '\n';
		std::cout << "Substract of arguments: " << calculate(a, b, subtract) << '\n';
		std::cout << "Multiply of arguments: " << calculate(a, b, multiply) << '\n';
		std::cout << "Divison of arguments: " << calculate(a, b, division) << '\n';
		std::cout << '\n' << "Enter operands, q to quit:\n";
	}
	std::cin.clear();
	while(std::cin.get() != '\n');
	std::cin.get();
	return 0;
}
double calculate(double a, double b, double(*pf)(double, double))
{
	return pf(a, b);
}
double sum(double a, double b)
{
	return a + b;
}
double subtract(double a, double b)
{
	return a - b;
}
double multiply(double a, double b)
{
	return a * b;
}
double division(double a, double b)
{
	return a / b;
}