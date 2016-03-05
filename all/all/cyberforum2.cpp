#include <iostream>

int main()
{
	bool codes[256] = { false };
	char str[300] = "";
	std::cout << "Enter string\n";
	std::cin.getline(str, 300);
	for(int i = 0; str[i] != '\0'; i++)
		if(!codes[(int)str[i]])
			codes[(int)str[i]] = true;
	for(int i = 0; i < 256; i++)
		if(codes[i])
			std::cout << "String contained a symbol: " << (char)i << std::endl;
	std::cin.get();
	return 0;
}