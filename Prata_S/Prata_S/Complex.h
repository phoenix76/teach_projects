#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

class CComplex
{
public:
	CComplex();
	CComplex(double a, double b);

	CComplex operator+(const CComplex &obj) const;
	CComplex operator-(const CComplex &obj) const;
	CComplex operator*(const CComplex &obj) const;
	CComplex operator~() const;

	friend CComplex operator*(double n, const CComplex &obj);
	friend std::ostream & operator<<(std::ostream &os, const CComplex &obj);
	friend std::istream & operator>>(std::istream &is, CComplex &obj);

private:
	double x;
	double y;
};

#endif