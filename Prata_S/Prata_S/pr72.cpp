#include <iostream>

const int SIZE = 10;
void Input(double[], int*);
double Average(const double[], int);
void Show(const double[], int);

int main()
{
	int count = 0;
	double arr[SIZE];

	Input(arr, &count);
	if(count > 0)
	{
		Show(arr, count);
		std::cout << "Average: " << Average(arr, count);
	}

	std::cin.get();
	return 0;
}

void Input(double arr[], int *count)
{
	std::cout << "Enter the numbers, enter -1 to quit: " << std::endl;
	for(int i = 0; i < SIZE; i++)
	{
		std::cin >> arr[i];
		while(!std::cin)
		{
			std::cin.clear();
			while(std::cin.get() != '\n');
			std::cout << "Please enter the correct number:";
			std::cin >> arr[i];
		}
		if(arr[i] == -1.0)
			break;
		(*count)++;
	}
	std::cout << '\n';
	std::cin.get();
}

double Average(const double arr[], int count)
{
	double result = 0;
	for(int i = 0; i < count; i++)
		result += arr[i];
	return result / count;
}

void Show(const double arr[], int count)
{
	for(int i = 0; i < count; i++)
		std::cout << arr[i] << '\t';
	std::cout << '\n';
}