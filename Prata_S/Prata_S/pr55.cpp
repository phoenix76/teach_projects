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
	int price[13] { 0 };

	for(int i = 0; i < 12; i++)
	{
		std::cout << "Enter book count for " << months[i] << ": ";
		std::cin >> price[i];
		price[12] += price[i];
	}

	std::cout << "Count of books for the year is " << price[12] << " exmp." << std::endl;

	system("pause");
	return 0;
}