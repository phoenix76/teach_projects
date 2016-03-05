#include <iostream>

const unsigned short strsize = 100;
struct sBop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

int main()
{
	char ch;
	sBop persons[4] =
	{
		{ "Don Braiyan", "cpp programmer", "Don_CPP", 0 },
		{ "Alex Frau", "DirectX developer", "Graphics_Monster", 2 },
		{ "Frank Bauman", "Sound master", "Sounder", 1 },
		{ "Stanly Horn", "Designer", "Paint_master", 2 }
	};

	std::cout << "Benevolent Order of Programers Report\n";
	std::cout << "a. display by name      b. display by title\n";
	std::cout << "c. display by bopname   d. display by preference\nq. quit" << std::endl;
	std::cout << "Enter you choice: ";
	while(std::cin >> ch && ch != 'q')
	{
		switch(ch)
		{
		case 'a':
		case 'A':
		{
					for(int i = 0; i <= 3; i++)
						std::cout << persons[i].fullname << '\n';
					std::cout << "Next choice: ";
					break;
		}
		case 'b':
		case 'B':
		{
					for(int i = 0; i <= 3; i++)
						std::cout << persons[i].title << '\n';
					std::cout << "Next choice: ";
					break;
		}
		case 'c':
		case 'C':
		{
					for(int i = 0; i <= 3; i++)
						std::cout << persons[i].bopname << '\n';
					std::cout << "Next choice: "; 
					break;
		}
		case 'd':
		case 'D':
		{
					for(int i = 0; i <= 3; i++)
					{
						if(persons[i].preference == 0)
							std::cout << persons[i].fullname << '\n';
						else if(persons[i].preference == 1)
							std::cout << persons[i].title << '\n';
						else
							std::cout << persons[i].bopname << '\n';
					}
					std::cout << "Next choice: ";
					break; 
		}
		default:
		{
				   std::cin.clear();
				   while(std::cin.get() != '\n')
					   continue;
				   std::cout << "Enter the correct choice: ";
				   break;
		}
		}
	}


	std::cin.get();
	std::cin.get();
	return 0;
}