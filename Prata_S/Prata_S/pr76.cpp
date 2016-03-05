#include <iostream>

int Fill_Array(double[], int);
void Show_Array(const double[], int);
void Reverse_Array(double[], int);

int main()
{
	double *data;
	int size, realSize;
	std::cout << "Enter the size of data array: ";
	std::cin >> size;
	while(std::cin.fail())
	{	
			std::cin.clear();
			while(std::cin.get() != '\n');
			std::cout << "Enter the correct size: ";
			std::cin >> size;
	}
	data = new double[size];
	realSize = Fill_Array(data, size);
	Reverse_Array(data, realSize);
	Show_Array(data, realSize);
	delete[] data;

	std::cin.get();
	return 0;
}
int Fill_Array(double data[], int maxSize)
{
	int count = 0;
	std::cout << "Enter the numbers, maximum " << maxSize << " elements:\n";
	while(count < maxSize)
	{
		std::cin >> data[count];
		if(!std::cin)
		{
			std::cin.clear();
			while(std::cin.get() != '\n');
			break;
		}
		count++;
	}
	return count;
}
void Show_Array(const double data[], int size)
{
	for(int i = 0, count = 0; i < size; i++)
	{
		if(count == 10)
		{
			std::cout << "\n\n";
			count = 0;
		}
		std::cout << data[i] << '\t';
		count++;
	}
}
void Reverse_Array(double data[], int size)
{
	double temp;
	for(int begin = 1, end = size - 2; begin < end; begin++, end--)
	{
		temp = data[begin];
		data[begin] = data[end];
		data[end] = temp;
	}
}