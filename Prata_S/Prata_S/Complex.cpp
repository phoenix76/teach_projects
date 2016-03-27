#include "Complex.h"

CComplex::CComplex()
{
	x = y = 0.0;
}
CComplex::CComplex(double a, double b)
{
	x = a;
	y = b;
}
CComplex CComplex::operator+(const CComplex &obj) const
{
	return CComplex(x + obj.x, y + obj.y);
}
CComplex CComplex::operator-(const CComplex &obj) const
{
	return CComplex(x - obj.x, y - obj.y);
}
CComplex CComplex::operator*(const CComplex &obj) const
{
	return CComplex(x * obj.x - y * obj.y, x * obj.y + y * obj.x);
}
CComplex CComplex::operator~() const
{
	return CComplex(x, -y);
}
CComplex operator*(double n, const CComplex &obj)
{
	return CComplex(n * obj.x, n * obj.y);
}
std::ostream & operator<<(std::ostream &os, const CComplex &obj)
{
	os << '(' << obj.x << ", " << obj.y << "i)";
	return os;
}
std::istream & operator>>(std::istream &is, CComplex &obj)
{
	std::cout << "x: ";
	is >> obj.x;
	if(is)
	{
		std::cout << "y: ";
		is >> obj.y;
		while(is.get() != '\n');
	}
	return is;
}