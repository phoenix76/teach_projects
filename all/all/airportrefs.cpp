#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>

struct sPassenger
{
	std::string destination;
	int flightNumber;
	std::string passengerFIO;
	std::string dateOfDeparture;
};
typedef std::vector<std::pair<sPassenger, int>> passenger_list;

bool DB_Init(std::ifstream &, passenger_list &);
void DB_RewriteBeforeExit(std::ofstream &,const passenger_list &);

void PrintAllPassengers(const passenger_list &);
void PrintPassengersByFlightNumber(const passenger_list &, int);
void PrintPassengerByName(const passenger_list &, const std::string &);
void AddPassengerToList(const sPassenger &, passenger_list &);
void DeletePassengersByFlightNumber(passenger_list &, int);
void DeletePassengerByName(passenger_list &, const std::string &);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream inFile;
	std::ofstream outFile;
	std::string temp = "";
	sPassenger passengerTmp;
	passenger_list passList;
	int flightNumber;
	int ch;
	if(DB_Init(inFile, passList))
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
				PrintAllPassengers(passList);
				break;
			case 2:
				int n;
				std::cout << "Введите номер рейса для отображения: ";
				while(!(std::cin >> n))
				{
					std::cin.clear();
					while(std::cin.get() != '\n');
					std::cout << "Введите корректный номер рейса: ";
				}
				std::cin.get();
				PrintPassengersByFlightNumber(passList, n);
				break;
			case 3:
				std::cout << "Введите имя пассажира для отображения: ";
				std::getline(std::cin, temp);
				PrintPassengerByName(passList, temp);
				break;
			case 4:
				std::cout << "Введите пункт назначения: ";
				std::getline(std::cin, passengerTmp.destination);
				std::cout << "Введите номер рейса: ";
				while(!(std::cin >> passengerTmp.flightNumber))
				{
					std::cin.clear();
					while(std::cin.get() != '\n');
					std::cout << "Введите корректный номер рейса: ";
				}
				std::cin.get();
				std::cout << "Введите ФИО пассажира: ";
				std::getline(std::cin, passengerTmp.passengerFIO);
				std::cout << "Введите дату вылета в формате 01 01 2001 14 56 : ";
				std::cin >> passengerTmp.dateOfDeparture;
				passengerTmp.dateOfDeparture += ':';
				std::cin >> temp;
				passengerTmp.dateOfDeparture += temp + ':';
				std::cin >> temp;
				passengerTmp.dateOfDeparture += temp + '\t';
				std::cin >> temp;
				passengerTmp.dateOfDeparture += temp + ':';
				std::cin >> temp;
				passengerTmp.dateOfDeparture += temp;
				std::cin.get();
				AddPassengerToList(passengerTmp, passList);
				break;
			case 5:
				std::cout << "Введите номер рейса для удаления пассажиров: ";
				while(!(std::cin >> flightNumber))
				{
					std::cin.clear();
					while(std::cin.get() != '\n');
					std::cout << "Введите корректный номер рейса: ";
				}
				std::cin.get();
				DeletePassengersByFlightNumber(passList, flightNumber);
				break;
			case 6:
				std::cout << "Введите ФИО для удаления пассажира: ";
				std::getline(std::cin, temp);
				DeletePassengerByName(passList, temp);
				break;
			case 7:
				DB_RewriteBeforeExit(outFile, passList);
				loop = false;
				break;
			default:
				std::cout << "Недопустимая команда. Ошибка!\n\n";
				std::cin.clear();
				while(std::cin.get() != '\n');
				break;
			}
		}
	}



	std::cin.get();
	return 0;
}

bool DB_Init(std::ifstream &ifs, passenger_list &list)
{
	ifs.open("airport_db.txt");
	if(ifs.is_open())
	{
		sPassenger tempPassenger;
		unsigned maxPassengerNumber = 0;
		int count = 0;
		std::cout << "База данных открыта.\n"
			<< "--------------------------------------------------------\n\n";
		while(true)
		{
			ifs >> maxPassengerNumber;
			if(ifs.eof())
			{
				if(count == 0)
				{
					maxPassengerNumber = 0;
					std::cout << "База данных пуста.\n"
						<< "--------------------------------------------------------\n\n";
					break;
				}
				else
				{
					std::cout << "Данные загружены.\n"
						<< "--------------------------------------------------------\n\n";
					break;
				}
			}
			ifs.get();
			std::getline(ifs, tempPassenger.destination);
			ifs >> tempPassenger.flightNumber;
			ifs.get();
			std::getline(ifs, tempPassenger.passengerFIO);
			std::getline(ifs, tempPassenger.dateOfDeparture);
			std::pair<sPassenger, int> passengerTemp = { tempPassenger, maxPassengerNumber };
			list.push_back(passengerTemp);
			count++;
		}
		ifs.close();
		return true;
	}
	else
	{
		std::cout << "База данных не может быть открыта. Ошибка!\n"
			<< "--------------------------------------------------------\n\n";
		return false;
	}
}
void DB_RewriteBeforeExit(std::ofstream &ofs, const passenger_list &list)
{
	ofs.open("airport_db.txt");
	if(ofs.is_open())
	{
		for(auto it = list.begin(); it != list.end(); it++)
		{
			ofs << it->second << '\n';
			ofs << it->first.destination << '\n';
			ofs << it->first.flightNumber << '\n';
			ofs << it->first.passengerFIO << '\n';
			ofs << it->first.dateOfDeparture << '\n';
		}
		std::cout << "База данных обновлена. Выход.\n"
			<< "--------------------------------------------------------\n\n";
		ofs.close();
	}
	else
	{
		std::cout << "Обновление базы данных невозможно, файл не может быть открыт. Ошибка!\n"
			<< "--------------------------------------------------------\n\n";
	}
}
void PrintAllPassengers(const passenger_list & list)
{
	if(!list.empty())
	{
		for(auto it = list.begin(); it != list.end(); it++)
		{
			std::cout << "\nНомер билета: " << it->second << '\n';
			std::cout << "Пункт назначения: " << it->first.destination << '\n'
				<< "Номер рейса: " << it->first.flightNumber << '\n'
				<< "ФИО пассажира: " << it->first.passengerFIO << '\n'
				<< "Дата вылета: " << it->first.dateOfDeparture << '\n';
		}
	}
	else
		std::cout << "База данных пуста.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void PrintPassengersByFlightNumber(const passenger_list &list, int number)
{
	bool result = false;
	for(auto it = list.begin(); it != list.end(); it++)
	{
		if(it->first.flightNumber == number)
		{
			std::cout << "\nНомер билета: " << it->second << '\n';
			std::cout << "Пункт назначения: " << it->first.destination << '\n'
				<< "Номер рейса: " << it->first.flightNumber << '\n'
				<< "ФИО пассажира: " << it->first.passengerFIO << '\n'
				<< "Дата вылета: " << it->first.dateOfDeparture << '\n';
			result = true;
		}
	}
	if(!result)
		std::cout << "На этот рейс пассажиров не зарегистрировано,\nлибо рейс не существует.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void PrintPassengerByName(const passenger_list &list, const std::string &name)
{
	bool result = false;
	for(auto it = list.begin(); it != list.end(); it++)
	{
		if(it->first.passengerFIO == name)
		{
			std::cout << "\nНомер билета: " << it->second << '\n';
			std::cout << "Пункт назначения: " << it->first.destination << '\n'
				<< "Номер рейса: " << it->first.flightNumber << '\n'
				<< "ФИО пассажира: " << it->first.passengerFIO << '\n'
				<< "Дата вылета: " << it->first.dateOfDeparture << '\n';
			result = true;
		}
	}
	if(!result)
		std::cout << "Пассажира с таким ФИО нет.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void AddPassengerToList(const sPassenger &passenger, passenger_list &list)
{
	std::pair<sPassenger, int> temp = { passenger, list.back().second + 1 };
	list.push_back(temp);
	std::cout << "Добавлено.\n"
		<< "--------------------------------------------------------\n\n";
}
void DeletePassengersByFlightNumber(passenger_list &list, int number)
{
	bool result = false;
	for(auto it = list.begin(); it != list.end();)
	{
		if(it->first.flightNumber == number)
		{
			it = list.erase(it);
			result = true;
		}
		else
			it++;
	}
	if(result)
		std::cout << "Удалено.\n";
	else
		std::cout << "На этот рейс пассажиров не зарегистрировано,\nлибо рейс не существует.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void DeletePassengerByName(passenger_list &list, const std::string & name)
{
	bool result = false;
	for(auto it = list.begin(); it != list.end();)
	{
		if(it->first.passengerFIO == name)
		{
			it = list.erase(it);
			result = true;
		}
		else
			it++;
	}
	if(result)
		std::cout << "Удалено.\n";
	else
		std::cout << "Пассажира с таким ФИО нет.\n";
	std::cout << "--------------------------------------------------------\n\n";
}