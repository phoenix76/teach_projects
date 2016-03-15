#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

struct stringy
{
	char *str;
	int st;
};

void set(stringy &s, const char *source);
void show(const char *str, int num = 1);
void show(const stringy &s, int num = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	delete[] beany.str;
	show("Done!");

	std::cin.get();
	return 0;
}
void set(stringy &s, const char *source)
{
	s.str = new char[strlen(source) + 1];
	strcpy(s.str, source);
	s.st = strlen(s.str) + 1;
}
void show(const char *str, int num)
{
	while(num)
	{
		std::cout << str << '\n';
		num--;
	}
	std::cout << '\n';
}
void show(const stringy &s, int num)
{
	while(num)
	{
		std::cout << s.str << '\n';
		num--;
	}
	std::cout << '\n';
}