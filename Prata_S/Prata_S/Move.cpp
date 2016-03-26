#include "Move.h"
#include <iostream>

CMove::CMove(double a, double b)
{
	x = a;
	y = b;
}
void CMove::ShowMove() const
{
	std::cout << "X: " << x << "\nY: " << y << std::endl;
}
const CMove & CMove::Add(const CMove &m)
{
	x += m.x;
	y += m.y;
	return *this;
}
void CMove::Reset(double a, double b)
{
	x = a;
	y = b;
}