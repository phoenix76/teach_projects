#include <iostream>
#include <array>

int main()
{
	float cleoBalance = 100.0f;
	float dafnaBalance = 100.0f;
	short years = 0;

	std::cout << "Year: " << years << "->	" << "Dafna: " << dafnaBalance << "$" << "\tCleo: " << cleoBalance << '$' << std::endl;
	while(dafnaBalance >= cleoBalance)
	{
		dafnaBalance += 10.0f;
		cleoBalance = cleoBalance / 100.0f * 105.0f;
		years++;
		std::cout << "Year: " << years << "->	" << "Dafna: " << dafnaBalance << "$" << "\tCleo: " << cleoBalance << '$' << std::endl;
	}

	std::cout << "Cleo balance is over Dafna balance with " << years << "years\n" << "Dafna balance: " << dafnaBalance << '$' << "\tCleo balance: " << cleoBalance << '$' << std::endl;

	system("pause");
	return 0;
}