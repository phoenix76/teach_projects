#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
int main(int argc, char** argv) {
	int n, b;
	cout << "Vvedite n" << endl;
	cin >> n;
	int *array = new int[n];
	for(int i = 0; i<n; i++)
	{
		cout << "Enter Massiv [" << i << "]" << endl;
		cin >> array[i];
	}
	cout << "Vvedite b" << endl;
	cin >> b;
	for(int i = 0; i<n; i++)
	{
		if(b == array[i])
		{
			cout << "V massive est' iskomoe znachenie " << array[i] << endl;
			break;
		}
		else if(i == (n - 1))
			cout << "V massive net znachenie ravnogo " << b << endl;
	}
	delete[] array;
	_getch();
	return 0;
}