#ifndef _CAIRPORT_H_
#define _CAIRPORT_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct sPassenger
{
	std::string destination;
	int flightNumber;
	std::string passengerFIO;
	std::string dateOfDeparture;
};

typedef std::vector<std::pair<sPassenger, int>> passengerList;

class cAirport
{
public:
	cAirport();
	~cAirport();

	void PrintAllPassengers();
	void PrintPassengersByFlightNumber();
	void PrintPassengerByName();
	void AddPassengerToList();	
	void DeletePassengersByFlightNumber();
	void DeletePassengerByName();
	void RewriteExitData();
	bool sussededOpenFile;

private:
	passengerList m_passengerList;
	sPassenger *m_pTempPassenger;
	std::ifstream m_inFile;
	std::ofstream m_outFile;
	int m_maxPassengerNumber;
};

#endif