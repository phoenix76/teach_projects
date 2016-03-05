#include <iostream>
#include <fstream>

struct sPerson
{
	char name[50];
	double amount;
};

int main()
{
	std::ifstream inFile;
	int count, patrons = 0, greatPatrons = 0;
	inFile.open("pr69.txt");
	if(!inFile.is_open())
	{
		std::cout << "File is missing. Exit." << std::endl;
		exit(EXIT_FAILURE);
	}
	inFile >> count;
	inFile.get();
	sPerson *persons = new sPerson[count];
	for(int i = 0; i < count; i++)
	{
		inFile.getline(persons[i].name, 50);
		inFile >> persons[i].amount;
		inFile.get();
		persons[i].amount >= 10000.0 ? greatPatrons++ : patrons++;
	}
	std::cout << "Patrons: \n";
	if(patrons == 0)
		std::cout << "none\n\n";
	else
	{
		for(int i = 0; i < count; i++)
		{
			if(persons[i].amount < 10000.0)
			{
				std::cout << persons[i].name << '\t' << persons[i].amount << std::endl;
			}
		}
	}
	std::cout << '\n';
	std::cout << "Great Patrons: \n";
	if(greatPatrons == 0)
		std::cout << "none\n\n";
	else
	{
		for(int i = 0; i < count; i++)
		{
			if(persons[i].amount >= 10000.0)
			{
				std::cout << persons[i].name << '\t' << persons[i].amount << std::endl;
			}
		}
	}
	delete[] persons;
	std::cin.get();
	return 0;
}