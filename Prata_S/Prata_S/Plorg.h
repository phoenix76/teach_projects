#ifndef _PLORG_H_
#define _PLORG_H_

#include <string>

class CPlorg
{
public:
	CPlorg() { m_name = "Plorga"; m_CI = 50; }
	CPlorg(const std::string &name, int CI);

	void ChangeCI(int val);
	void ShowData() const;


private:
	std::string m_name;
	int m_CI;
};

#endif