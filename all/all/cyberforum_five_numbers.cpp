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
			std::cout << "----------Выберите действие----------\n";
			std::cout << "1. Вывести весь список.\n"
				<< "2. Вывести пассажиров по номеру рейса.\n"
				<< "3. Вывести пассажира по ФИО.\n"
				<< "4. Добавить пассажира в список.\n"
				<< "5. Удалить пассажиров по номеру рейса.\n"
				<< "6. Удалить пассажира по ФИО.\n"
				<< "7. Выход.\n" << std::endl;
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
				std::cout << "Недопустимая команда. Ошибка!\n\n";
				break;
			}
		}
	}
	delete air;
	std::cin.get();
	return 0;
}