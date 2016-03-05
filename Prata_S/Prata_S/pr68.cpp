#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inFile;
	int symbolsCount = 0;
	char ch;
	inFile.open("myfile.txt");
	if(!inFile.is_open())
	{
		std::cout << "Error open file";
		exit(EXIT_FAILURE);
	}
	while(!inFile.fail())
	{
		inFile.get(ch);
		if(ch == '\n' || ch == '\t')
			continue;
		else
			symbolsCount++;
	}
	if(inFile.eof())
		std::cout << "Reached file succeded, end file." << std::endl;
	else if(inFile.fail())
		std::cout << "Read stop, file is missing." << std::endl;
	else
		std::cout << "Read stop with unknown error." << std::endl;
	std::cout << "Symbols count in file is: " << symbolsCount << std::endl;

	std::cin.get();
	return 0;
}