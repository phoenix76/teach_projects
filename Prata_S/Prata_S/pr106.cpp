#include "Move.h"
#include <iostream>

int main()
{
	CMove m1;
	CMove m2(50.0, 100.0);
	CMove m3(200.0, 500.0);
	m1.ShowMove();
	m2.ShowMove();
	m3.ShowMove();
	m1 = m3.Add(m2);
	m1.ShowMove();
	m3.Reset();
	m3.ShowMove();

	std::cin.get();
	return 0;
}