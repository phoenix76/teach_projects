#include <iostream>
#include <string>

void strcount(const std::string & str);

int main()
{
	std::string temp = "";
	std::cout << "Enter a line (empty line to quit): ";
	while(true)
	{
		std::getline(std::cin, temp);
		if(temp == "")
			break;
		strcount(temp);
		std::cout << "Enter a next line: ";
	}
	std::cout << "Bye.\n";
	return 0;
}

void strcount(const std::string &str)
{
	static int total = 0;
	int count = 0;
	std::cout << "\"" << str << "\"" << " contains " << str.length() << " characters.\n";
	total += str.length();
	std::cout << total << " characters total.\n";
}