#include "Plorg.h"

#include <iostream>

CPlorg::CPlorg(const std::string &name, int CI) { m_name = name;	m_CI = CI; }
void CPlorg::ChangeCI(int val) { m_CI = val; }
void CPlorg::ShowData() const { std::cout << "Name: " << m_name << "\nContentment index: " << m_CI << std::endl; }