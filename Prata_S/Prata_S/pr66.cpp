#include <iostream>

struct sPatrons
{
	char name[100];
	double donation;
};

int main()
{
	int count, patrons = 0, greatPatrons = 0;
	std::cout << "Please enter count of patrons: ";
	while(true)
	{
		if(std::cin >> count && count > 0)
			break;
		
		if(std::cin.fail())
		{
			std::cin.clear();
			while(std::cin.get() != '\n')
				continue;
			std::cout << "Enter the correct value: ";
			continue;
		}
		if(count <= 0)
		{
			std::cout << "Enter the correct value: ";
			continue;
		}
	}
	while(std::cin.get() != '\n');
	sPatrons *memberList = new sPatrons[count];
	for(int i = 0; i < count; i++)
	{
		std::cout << "Enter name of patron #" << i + 1 << ": ";
		std::cin.getline(memberList[i].name, 100);
		std::cout << "Enter the money: ";
		while(true)
		{
			if(std::cin >> memberList[i].donation && memberList[i].donation > 0)
				break;
			if(std::cin.fail())
			{
				std::cin.clear();
				while(std::cin.get() != '\n');
				std::cout << "Enter the correct value: ";
				continue;
			}
			if(memberList[i].donation <= 0)
			{
				std::cout << "Enter the correct value: ";
				continue;
			}
		}
		while(std::cin.get() != '\n');
		memberList[i].donation >= 10000.0 ? greatPatrons++ : patrons++;
	}

	std::cout << "\n\nPatrons:\n";
	if(patrons == 0)
		std::cout << "none";
	else
	{
		for(int i = 0; i < count; i++)
		{
			if(memberList[i].donation < 10000.0)
				std::cout << memberList[i].name << '\t' << memberList[i].donation << '\n';
		}
	}
	std::cout << "\n\nGreat Patrons:\n";
	if(greatPatrons == 0)
		std::cout << "none\n";
	else
	{
		for(int i = 0; i < count; i++)
		{
			if(memberList[i].donation >= 10000.0)
				std::cout << memberList[i].name << '\t' << memberList[i].donation << '\n';
		}
	}
	delete[] memberList;
	std::cin.get();
	return 0;
}