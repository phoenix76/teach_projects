#include <iostream>
int counter = 0;
void f(const char *, int flag = 0);

int main()
{
	const char *str = "This is string";
	f(str);
	f(str, counter);
	f(str, counter);
	f(str, counter);

	std::cin.get();
	return 0;
}
void f(const char *str, int flaf)
{
	if(flaf == 0)
	{
		std::cout << str << "\n\n";
		counter++;
	}
	else
	{
		for(int i = 0; i < counter; i++)
			std::cout << str << "\n";
		std::cout << '\n';
		counter++;
	}
}