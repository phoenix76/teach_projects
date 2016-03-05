#include <iostream>

double Average(double, double);

int main()
{
	double x, y;
	while(true)
	{
		std::cout << "Enter the two value:" << std::endl;
		std::cin >> x >> y;
		while(!std::cin)
		{
			std::cin.clear();
			while(std::cin.get() != '\n');
			std::cout << "Please enter the correct numbers:\n";
			std::cin >> x >> y;
		}
		if(x == 0.0 || y == 0.0)
			break;
		std::cout << "Average is: " << Average(x, y) << "\n\n";
	}

	std::cin.get();
	std::cin.get();
	return 0;
}

double Average(double x, double y)
{
	return 2.0 * x * y / (x + y);
}