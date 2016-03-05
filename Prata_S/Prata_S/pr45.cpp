#include <iostream>

struct sCandyBar
{
	char name[100];
	float weidth;
	int callories;
};
int main()
{
	sCandyBar candy = { "Moncha Munch", 2.3f, 350 };

	std::cout << candy.name << '\n' << candy.weidth << '\n' << candy.callories << std::endl;

	system("pause");
	return 0;
}