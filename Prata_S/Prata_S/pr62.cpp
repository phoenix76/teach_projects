#include <iostream>
#include <Windows.h>

const int ARR_SIZE = 10;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double arr[10] = { 0 };
	double sum = 0;
	double average;
	double larger_of_average = 0;
	unsigned short count = 0;

	cout << "Enter double values, maximum ten elements:" << endl;
	while((count < ARR_SIZE) && (cin >> arr[count]))
	{
		sum += arr[count];
		++count;
	}
	cin.clear();
	while(cin.get() != '\n')
		continue;
	average = sum / static_cast<double>(count);
	cout << "Average: " << average << endl;
	for(short i = 0; i < count; i++){
		if(arr[i] > average)
			larger_of_average++;
	}
	cout << "The larger of average count is: " << larger_of_average << endl;
	
	cin.get();
	return 0;
}