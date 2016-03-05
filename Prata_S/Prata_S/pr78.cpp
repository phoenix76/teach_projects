/*#include <iostream>

const int Seasons = 4;
void fill_array(const char *[], double[]);
void show(const char *[], double[]);

int main()
{
	const char *seasons[Seasons] = { "Spring", "Summer", "Fall", "Winter" };
	double expenses[Seasons];
	fill_array(seasons, expenses);
	show(seasons, expenses);
	std::cin.get();
	return 0;
}
void fill_array(const char **seasons, double data[])
{
	for(int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << seasons[i] << " expenses: ";
		std::cin >> data[i];
	}
	while(std::cin.get() != '\n');
}
void show(const char **seasons, double data[])
{
	double total = 0.0;
	std::cout << "EXPENSES\n";
	for(int i = 0; i < Seasons; i++)
	{
		std::cout << seasons[i] << ": $" << data[i] << '\n';
		total += data[i];
	}
	std::cout << "Total: $" << total << std::endl;
}*/

#include <iostream>

const int Seasons = 4;
struct sExpenses
{
	double data[Seasons];
};
void fill_array(const char *[], sExpenses*);
void show(const char *[], sExpenses);

int main()
{
	const char *seasons[Seasons] = { "Spring", "Summer", "Fall", "Winter" };
	sExpenses expenses;
	fill_array(seasons, &expenses);
	show(seasons, expenses);
	std::cin.get();
	return 0;
}
void fill_array(const char **seasons, sExpenses *obj)
{
	for(int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << seasons[i] << " expenses: ";
		std::cin >> obj->data[i];
	}
	while(std::cin.get() != '\n');
}
void show(const char **seasons, sExpenses obj)
{
	double total = 0.0;
	std::cout << "EXPENSES\n";
	for(int i = 0; i < Seasons; i++)
	{
		std::cout << seasons[i] << ": $" << obj.data[i] << '\n';
		total += obj.data[i];
	}
	std::cout << "Total: $" << total << std::endl;
}