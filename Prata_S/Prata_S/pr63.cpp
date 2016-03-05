#include <iostream>

int main()
{
	char ch;
	bool flag = true;
	std::cout << "Please enter one of the following choices:\n"
		<< "c)carnivore   p)pianist\n"
		<< "t)tree        g)game" << std::endl;
	while(flag == true && std::cin.get(ch))
	{
		switch(ch)
		{
		case 'c':
		case 'C':
		{
					flag = false;
					std::cout << "You entered carnivore!\n";
					break;
		}
		case 'p':
		case 'P':
		{
					flag = false;
					std::cout << "You entered pianist!\n";
					break;
		}
		case 't':
		case 'T':
		{
					flag = false;
					std::cout << "You entered tree!\n";
					break;
		}
		case 'g':
		case 'G':
		{
					flag = false;
					std::cout << "You entered game!\n";
					break;
		}
		default:
		{
				   std::cin.clear();
				   while(std::cin.get() != '\n')
					   continue;
				   std::cout << "Please enter a c, p, t or g:";
				   break;
		}
		}
	}

	std::cin.get();
	std::cin.get();
	return 0;
}