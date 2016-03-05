#include <iostream>
#include <cctype>
#include <cstring>

int main()
{
	char dest[30];
	int vowels = 0, consonants = 0, others = 0;
	std::cout << "Enter words (q to quit)\n";
	std::cin >> dest;
	while(dest[0] != 'q' && dest[0] != 'Q')
	{
		if(std::isalpha(dest[0]))
		{
			switch(dest[0])
			{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				vowels++;
				break;
			default:
				consonants++;
				break;
			}
		}
		else
		{
			others++;
		}
		std::cin >> dest;
	}
	while(std::cin.get() != '\n');
	std::cout << vowels << " words beginning with vowels\n";
	std::cout << consonants << " words beginning with consonants\n";
	std::cout << others << " others" << std::endl;

	std::cin.get();
	return 0;
}