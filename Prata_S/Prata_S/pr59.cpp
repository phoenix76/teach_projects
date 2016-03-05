#include <iostream>
#include <string>

int main()
{
	std::string done = "done";
	std::string word;
	unsigned int count = 0;

	std::cout << "Enter the words, enter \"done\" for stop:" << std::endl;
	std::cin >> word;
	while(word != done)
	{
		std::cin >> word;
		count++;
	}
	std::cout << "You entered " << count << " words." << std::endl;

	system("pause");
	return 0;
}