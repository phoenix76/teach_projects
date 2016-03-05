#include <Windows.h>
#include "cAirport.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cAirport *air = new cAirport;
	int ch;
	if(air->sussededOpenFile)
	{
		bool loop = true;
		while(loop)
		{
			std::cout << "----------�������� ��������----------\n";
			std::cout << "1. ������� ���� ������.\n"
				<< "2. ������� ���������� �� ������ �����.\n"
				<< "3. ������� ��������� �� ���.\n"
				<< "4. �������� ��������� � ������.\n"
				<< "5. ������� ���������� �� ������ �����.\n"
				<< "6. ������� ��������� �� ���.\n"
				<< "7. �����.\n" << std::endl;
			std::cout << ">> ";
			std::cin >> ch;
			std::cin.get();
			switch(ch)
			{
			case 1:
				air->PrintAllPassengers();
				break;
			case 2:
				air->PrintPassengersByFlightNumber();
				break;
			case 3:
				air->PrintPassengerByName();
				break;
			case 4:
				air->AddPassengerToList();
				break;
			case 5:
				air->DeletePassengersByFlightNumber();
				break;
			case 6:
				air->DeletePassengerByName();
				break;
			case 7:
				loop = false;
				break;
			default:
				std::cout << "������������ �������. ������!\n\n";
				break;
			}
		}
	}
	delete air;
	std::cin.get();
	return 0;
}