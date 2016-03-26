#ifndef _MOVE_H_
#define _MOVE_H_

class CMove
{
public:
	CMove(double = 0, double b = 0);
	void ShowMove() const;
	const CMove & Add(const CMove &m);
	void Reset(double a = 0, double b = 0);

private:
	double x;
	double y;
};

#endif