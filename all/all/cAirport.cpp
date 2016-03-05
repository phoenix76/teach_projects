#include "cAirport.h"

cAirport::cAirport()
{
	m_inFile.open("airport_db.txt");
	if(m_inFile.is_open())
	{
		m_pTempPassenger = new sPassenger;
		sussededOpenFile = true;
		m_maxPassengerNumber = 0;
		int count = 0;
		std::cout << "���� ������ �������.\n"
			<< "--------------------------------------------------------\n\n";
		while(true)
		{
			m_inFile >> m_maxPassengerNumber;
			if(m_inFile.eof())
			{
				if(count == 0)
				{
					m_maxPassengerNumber = 0;
					std::cout << "���� ������ �����.\n"
						<< "--------------------------------------------------------\n\n";
					break;
				}
				else
				{
					std::cout << "������ ���������.\n"
						<< "--------------------------------------------------------\n\n";
					break;
				}
			}
			m_inFile.get();
			std::getline(m_inFile, m_pTempPassenger->destination);
			m_inFile >> m_pTempPassenger->flightNumber;
			m_inFile.get();
			std::getline(m_inFile, m_pTempPassenger->passengerFIO);
			std::getline(m_inFile, m_pTempPassenger->dateOfDeparture);
			std::pair<sPassenger, int> passengerTemp = { *m_pTempPassenger, m_maxPassengerNumber };
			m_passengerList.push_back(passengerTemp);
			count++;
		}
		m_inFile.close();
	}
	else
	{
		std::cout << "���� ������ �� ����� ���� �������. ������!\n"
			<< "--------------------------------------------------------\n\n";
		sussededOpenFile = false;
	}
}
cAirport::~cAirport()
{
	RewriteExitData();
	delete m_pTempPassenger;
}
void cAirport::PrintAllPassengers()
{
	if(!m_passengerList.empty())
	{
		for(auto it = m_passengerList.begin(); it != m_passengerList.end(); it++)
		{
			std::cout << "\n����� ������: " << it->second << '\n';
			std::cout << "����� ����������: " << it->first.destination << '\n'
				<< "����� �����: " << it->first.flightNumber << '\n'
				<< "��� ���������: " << it->first.passengerFIO << '\n'
				<< "���� ������: " << it->first.dateOfDeparture << '\n';
		}
	}
	else
		std::cout << "���� ������ �����.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void cAirport::PrintPassengersByFlightNumber()
{
	int n;
	bool result = false;
	std::cout << "������� ����� ����� ��� �����������: ";
	while(!(std::cin >> n))
	{
		std::cin.clear();
		while(std::cin.get() != '\n');
		std::cout << "������� ���������� ����� �����: ";
	}
	std::cin.get();
	for(auto it = m_passengerList.begin(); it != m_passengerList.end(); it++)
	{
		if(it->first.flightNumber == n)
		{
			std::cout << "\n����� ������: " << it->second << '\n';
			std::cout << "����� ����������: " << it->first.destination << '\n'
				<< "����� �����: " << it->first.flightNumber << '\n'
				<< "��� ���������: " << it->first.passengerFIO << '\n'
				<< "���� ������: " << it->first.dateOfDeparture << '\n';
			result = true;
		}
	}
	if(!result)
		std::cout << "�� ���� ���� ���������� �� ����������������,\n���� ���� �� ����������.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void cAirport::PrintPassengerByName()
{
	bool result = false;
	std::string name;
	std::cout << "������� ��� ��������� ��� �����������: ";
	std::getline(std::cin, name);
	for(auto it = m_passengerList.begin(); it != m_passengerList.end(); it++)
	{
		if(it->first.passengerFIO == name)
		{
			std::cout << "\n����� ������: " << it->second << '\n';
			std::cout << "����� ����������: " << it->first.destination << '\n'
				<< "����� �����: " << it->first.flightNumber << '\n'
				<< "��� ���������: " << it->first.passengerFIO << '\n'
				<< "���� ������: " << it->first.dateOfDeparture << '\n';
			result = true;
		}
	}
	if(!result)
		std::cout << "��������� � ����� ��� ���.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void cAirport::AddPassengerToList()
{
	std::cout << "������� ����� ����������: ";
	std::getline(std::cin, m_pTempPassenger->destination);
	std::cout << "������� ����� �����: ";
	while(!(std::cin >> m_pTempPassenger->flightNumber))
	{
		std::cin.clear();
		while(std::cin.get() != '\n');
		std::cout << "������� ���������� ����� �����: ";
	}
	std::cin.get();
	std::cout << "������� ��� ���������: ";
	std::getline(std::cin, m_pTempPassenger->passengerFIO);
	std::cout << "������� ���� ������ � ������� 01 01 2001 14 56 : ";
	std::string temp;
	std::cin >> m_pTempPassenger->dateOfDeparture;
	m_pTempPassenger->dateOfDeparture += ':';
	std::cin >> temp;
	m_pTempPassenger->dateOfDeparture += temp + ':';
	std::cin >> temp;
	m_pTempPassenger->dateOfDeparture += temp + '\t';
	std::cin >> temp;
	m_pTempPassenger->dateOfDeparture += temp + ':';
	std::cin >> temp;
	m_pTempPassenger->dateOfDeparture += temp;
	std::cin.get();
	std::pair<sPassenger, int> passengerTemp = { *m_pTempPassenger, m_maxPassengerNumber + 1 };
	m_passengerList.push_back(passengerTemp);
	std::cout << "���������.\n"
		<< "--------------------------------------------------------\n\n";
}
void cAirport::DeletePassengersByFlightNumber()
{
	int n;
	bool result = false;
	std::cout << "������� ����� ����� ��� �������� ����������: ";
	while(!(std::cin >> n))
	{
		std::cin.clear();
		while(std::cin.get() != '\n');
		std::cout << "������� ���������� ����� �����: ";
	}
	std::cin.get();
	for(auto it = m_passengerList.begin(); it != m_passengerList.end();)
	{
		if(it->first.flightNumber == n)
		{
			it = m_passengerList.erase(it);
			result = true;
		}
		else
			it++;
	}
	if(result)
		std::cout << "�������.\n";
	else
		std::cout << "�� ���� ���� ���������� �� ����������������,\n���� ���� �� ����������.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void cAirport::DeletePassengerByName()
{
	bool result = false;
	std::string name;
	std::cout << "������� ��� ��� �������� ���������: ";
	std::getline(std::cin, name);
	for(auto it = m_passengerList.begin(); it != m_passengerList.end();)
	{
		if(it->first.passengerFIO == name)
		{
			it = m_passengerList.erase(it);
			result = true;
		}
		else
			it++;
	}
	if(result)
		std::cout << "�������.\n";
	else
		std::cout << "��������� � ����� ��� ���.\n";
	std::cout << "--------------------------------------------------------\n\n";
}
void cAirport::RewriteExitData()
{
	m_outFile.open("airport_db.txt");
	if(m_outFile.is_open())
	{
		for(auto it = m_passengerList.begin(); it != m_passengerList.end(); it++)
		{
			m_outFile << it->second << '\n';
			m_outFile << it->first.destination << '\n';
			m_outFile << it->first.flightNumber << '\n';
			m_outFile << it->first.passengerFIO << '\n';
			m_outFile << it->first.dateOfDeparture << '\n';
		}
		std::cout << "���� ������ ���������. �����.\n"
			<< "--------------------------------------------------------\n\n";
		m_outFile.close();
	}
	else
	{
		std::cout << "���������� ���� ������ ����������, ���� �� ����� ���� ������. ������!\n"
			<< "--------------------------------------------------------\n\n";
	}
}