#include "Bank.h"
#include <iostream>

Bank::Bank()
{
	m_name = "No name";
	m_id = 0;
	m_balance = 0.0;
}
Bank::~Bank()
{
}
Bank::Bank(const std::string &name, int id, double startBalance)
{
	m_name = name;
	m_id = id;
	if(startBalance >= 0)
		m_balance = startBalance;
	else
		m_balance = 0;
}
void Bank::Show() const
{
	std::cout << "Name: " << m_name << '\n'
		<< "Client ID: " << m_id << '\n'
		<< "Current balance: " << m_balance << std::endl;
}
void Bank::Add(double value)
{
	if(value > 0)
		m_balance += value;
}
void Bank::Withdraw(double value)
{
	if(m_balance >= value)
		m_balance -= value;
	else
		std::cout << "You don't have that mush money! Transaction aborted.\n";
}