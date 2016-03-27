#include <iostream>
#include "MyList.h"

int main()
{
	CMyList lst;
	CPlorg pl1("Plorg1", 100);
	CPlorg pl2("Plorg2", 200);
	CPlorg pl3("Plorg3", 300);
	lst + &pl1;
	lst + &pl2;
	lst + &pl3;
	lst.GetItem(2)->ShowData();
	lst.GetItem(2)->ChangeCI(500);
	lst.GetItem(2)->ShowData();
	lst.operator-();
	lst.GetItem(2);

	std::cin.get();
	return 0;
}