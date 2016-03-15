#include <iostream>

template <typename T> T maxn(T arr[], int num)
{
	T temp = arr[0];
	for(int i = 1; i < num; i++)
	{
		if(temp < arr[i])
			temp = arr[i];
	}
	return temp;
}
template <> const char * maxn(const char **pArr, int num)
{
	const char * temp = pArr[0];
	for(int i = 0; i < num - 1; i++)
	{
		if(strlen(pArr[i + 1]) > strlen(pArr[i]))
			temp = pArr[i + 1];
	}
	return temp;
}

int main()
{
	int arr1[6] = { 1, 4, 34, 11, 78, 34 };
	double arr2[4] = { 1.0, 45.5, 67.11, 6.9 };
	const char * arr3[5] = 
	{
		"one",
		"two",
		"three",
		"four",
		"five" };
	std::cout << "maxn for int: " << maxn(arr1, 6) << '\n';
	std::cout << "maxn for double: " << maxn(arr2, 4) << '\n';
	std::cout << "max for char * pointers: " << maxn(arr3, 5) << '\n';
	std::cin.get();
	return 0;
}