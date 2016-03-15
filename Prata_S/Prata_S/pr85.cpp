#include <iostream>

template <typename T> T max(T arr[])
{
	T temp = arr[0];
	for(int i = 1; i < 5; i++)
	{
		if(arr[i] > temp)
			temp = arr[i];
	}
	return temp;
}

int main()
{
	int arr1[5] = { 7, 12, 65, 2, 9 };
	double arr2[5] = { 5.6, 78.98, 4.4, 32.0, 11.3 };
	std::cout << "Max for int: " << max(arr1) << '\n';
	std::cout << "Max for double: " << max(arr2) << '\n';
	std::cin.get();
	return 0;
}