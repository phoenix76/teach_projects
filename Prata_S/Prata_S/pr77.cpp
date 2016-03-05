#include <iostream>

const int Max = 5;

double * fill_array(double arr[], int limit);
void show_array(const double *begin, const double *end);
void revalue(double r, double *begin, double *end);

int main()
{
	using namespace std;
	double properties[Max];
	double *endPtr = fill_array(properties, Max);
	show_array(properties, endPtr);
	if((properties + 1) != endPtr)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while(!(cin >> factor))
		{
			cin.clear();
			while(cin.get() != '\n');
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, endPtr);
		show_array(properties, endPtr);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}
double * fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	double *ptr = ar;
	for(int i = 0; i < limit; i++, ptr++)
	{
		cout << "Enter the property #" << (i + 1) << ": ";
		cin >> temp;
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n');
			cout << "Bad input; Input process terminated.\n";
			break;
		}
		else if(temp < 0)
			break;
		ar[i] = temp;
	}
	return ptr++;
}
void show_array(const double *begin, const double *end)
{
	using namespace std;
	int i = 1;
	for(const double *pbegin = begin; pbegin < end; pbegin++, i++)
	{
		cout << "Property #" << i << ": $";
		cout << *pbegin << endl;
	}
}
void revalue(double r, double *begin, double *end)
{
	for(double *pbegin = begin; pbegin < end; pbegin++)
		*pbegin *= r;
}