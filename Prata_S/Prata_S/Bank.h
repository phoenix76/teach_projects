#ifndef _BANK_H_
#define _BANK_H_

#include <string>

class Bank
{
public:
	Bank();
	Bank(const std::string &name, int idNumber, double startBalance);
	~Bank();

	void Show() const;
	void Add(double value);
	void Withdraw(double value);

private:
	std::string m_name;
	int m_id;
	double m_balance;
};

#endif