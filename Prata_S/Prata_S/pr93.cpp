#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <new>

struct chaff
{
	char dross[20];
	int slag;
};

int main()
{
	char buf[48];
	std::cout << "Adress buf: " << (void*)buf << '\n';
	chaff *pchaff = new(buf)chaff[2];
	std::cout << "Adress pchaff: " << pchaff << '\n';
	strcpy(pchaff[0].dross, "struct one");
	pchaff[0].slag = 10;
	strcpy(pchaff[1].dross, "struct two");
	pchaff[1].slag = 20;
	std::cout << pchaff[0].dross << ' ' << pchaff[0].slag << std::endl;
	std::cout << pchaff[1].dross << ' ' << pchaff[1].slag << std::endl;

	std::cin.get();
	return 0;
}