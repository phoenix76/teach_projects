#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inFile("cppcode.txt");
	std::ofstream outFile("scanresult.txt");

	if(inFile.is_open() && outFile.is_open())
	{
		int a = 0, b = 0;
		char temp;
		while(!inFile.eof())
		{
			inFile.get(temp);
			if(temp == '(')
				a++;
			else if(temp == ')')
				b++;
		}
		if(a == b)
			outFile << "Good.";
		else
			outFile << "Bad.";
	}
	else
		std::cout << "Error open file.\n";
	inFile.close();
	outFile.close();
	std::cout << "Done.";
	std::cin.get();
	return 0;
}