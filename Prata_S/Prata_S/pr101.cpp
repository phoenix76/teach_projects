#include "Bank.h"
#include <iostream>
int main()
{
	Bank clients[3] =
	{
		{ "Scott Meyers", 1013, 2500.0 },
		Bank(),
		{ "Donald Knut", 54321, 10034.0 }
	};
	for(int i = 0; i < 3; i++)
		clients[i].Show();
	std::cout << "Init a empty Bank object clients[1]\n";
	clients[1] = Bank("Stiv Djobs", 3422, 1390.5);
	clients[1].Show();
	clients[0].Add(1000.0);
	clients[2].Withdraw(1240.7);
	std::cout << "Clients after of change balances:\n";
	for(int i = 0; i < 3; i++)
		clients[i].Show();

	std::cin.get();
	return 0;
}