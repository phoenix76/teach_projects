#include <iostream>
#include <cwctype>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char ch;
	std::cout << "Enter the data to processing:\n";
	while(std::cin.get(ch) && ch != '@')
	{
		if(std::iswdigit(ch))
			continue;
		else
		{
			if(std::iswlower(ch))
				std::cout << (char)std::towupper(ch);
			else if(std::iswupper(ch))
				std::cout << (char)std::towlower(ch);
			else
				std::cout << ch;
		}
	}
	std::cin.get();
	std::cout << "Data processing is finished.\n";

	std::cin.get();
	return 0;
}