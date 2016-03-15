#include <iostream>

struct CandyBar
{
	char name[40];
	double weidth;
	int callories;
};
void process(CandyBar &bar, const char * str = "Millenium Munch", double weidth = 2.85, int callories = 350);
void show(const CandyBar &bar);

int main()
{
	CandyBar candy;
	process(candy);
	show(candy);
	std::cout << '\n';
	process(candy, "Rafaello", 4.2, 600);
	show(candy);

	std::cin.get();
	return 0;
}
void process(CandyBar &bar, const char *str, double weidth, int callories)
{
	int i = 0;
	while(str[i])
	{
		bar.name[i] = str[i];
		i++;
	}
	bar.name[i] = '\0';
	bar.weidth = weidth;
	bar.callories = callories;
}
void show(const CandyBar &bar)
{
	std::cout << "Name: " << bar.name << '\n';
	std::cout << "Weidth: " << bar.weidth << '\n';
	std::cout << "Callories: " << bar.callories << std::endl;
}