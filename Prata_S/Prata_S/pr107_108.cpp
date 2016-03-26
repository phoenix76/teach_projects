#include <iostream>
#include "MyList.h"

int main()
{
	CMyList lst;
	CPlorg pl1("Plorg1", 100);
	CPlorg pl2("Plorg2", 200);
	CPlorg pl3("Plorg3", 300);
	lst.Push(&pl1);
	lst.Push(&pl2);
	lst.Push(&pl3);
	lst.GetItem(2)->ShowData();
	lst.GetItem(2)->ChangeCI(500);
	lst.GetItem(2)->ShowData();
	lst.Pop();
	lst.GetItem(2);

	std::cin.get();
	return 0;
}