#include <iostream>
#include <array>

int main()
{
	const char *months[] =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	int price[3][13] = { 0 };
	int all = 0;
	int year = 2012;

	for(int i = 0; i < 3; i++)
	{
		for(int k = 0; k < 12; k++)
		{
			std::cout << "Enter the price for " << months[k] << " month of " << year << " year: ";
			std::cin >> price[i][k];
			price[i][12] += price[i][k];
		}
		year++;
		all += price[i][12];
	}

	year = 2012;
	for(int i = 0; i < 3; i++, year++)
		std::cout << "Sell books of " << year << " year is: " << price[i][12] << " exmp." << std::endl;

	std::cout << "Count of books for the all time is " << all << " exmp." << std::endl;

	system("pause");
	return 0;
}