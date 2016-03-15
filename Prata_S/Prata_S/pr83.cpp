#include <iostream>
#include <string>
#include <cctype>

const std::string & to_upper_func(std::string &);

int main()
{
	std::string temp;
	std::cout << "Enter a string (q to quit): ";
	std::getline(std::cin, temp);
	while(temp != "q")
	{
		std::cout << to_upper_func(temp) << std::endl;
		std::cout << "Next string: ";
		std::getline(std::cin, temp);
	}
	std::cout << "Bye!\n";
	std::cin.get();
	return 0;
}
const std::string & to_upper_func(std::string &str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if(std::isalnum(str[i]) && std::islower(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return str;
}