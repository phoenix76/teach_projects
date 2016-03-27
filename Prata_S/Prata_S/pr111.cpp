#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand((unsigned)time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream fout("vect.txt");
	cout << "Enter target distance (q to quit): ";
	while(cin >> target)
	{
		cout << "Enter step length: ";
		if(!(cin >> dstep))
			break;
		fout << "Target distanse: " << target << ", Step Size: " << dstep << endl;
		while(result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			fout << steps << ": " << result << endl;
		}
		fout << "After " << steps << " steps, the subject has the following location:\n";
		fout << result << endl;
		result.polar_mode();
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while(cin.get() != '\n');
	cin.get();
	return 0;
}