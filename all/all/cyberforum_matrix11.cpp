#include <iostream>
#include <ctime>

const int arr_size = 11;
const int max_size = 1000;
void func(const int [][arr_size]);

int main()
{
	srand((unsigned int)time(NULL));
	int matrix[arr_size][arr_size];
	for(int i = 0; i < arr_size; i++)
	{
		for(int n = 0; n < arr_size; n++)
			matrix[i][n] = rand() % 2000 - 1000;
	}
	func(matrix);
	std::cin.get();
	return 0;
}
void func(const int data[][arr_size])
{	
	for(int index = 0; index < arr_size; index++)
	{
		int min = max_size;
		for(int line = 0; line < arr_size; line++)
		{
			if(data[line][index] >= 0 && data[line][index] < min)
				min = data[line][index];
		}
		std::cout << "Min positive number in column #" << index + 1 << ": " << min << std::endl;
	}
	std::cout << '\n' << "Done.\n";
}