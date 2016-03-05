#include <iostream>

/*
int main()
{
	int arr[10] = { 1, 23, 0, 933, 0, 54, 23, 0, 12 };
	int count = 0;
	for(int i = 0; i < 10; i++)
	{
		if(arr[i] == 0)
			count++;
	}
	std::cout << count << std::endl;
	std::cin.get();
	return 0;
}

int main()
{
	int arr[10] = { 1, 23, 0, 933, 0, 54, 23, 0, 12 };
	int sum = 0;
	for(int i = 0; i < 10; i++)
	{
		if(arr[i] > 0)
			sum += arr[i];
	}
	std::cout << sum << std::endl;
	std::cin.get();
	return 0;
}
int main()
{
	int arr[10] = { 1, 23, 0, 933, 0, 54, 23, 0, 12 };
	int max = arr[9], count = 9;
	for(int i = 9; i >= 0; i--)
	{
		if(arr[i] > max)
		{
			max = arr[i];
			count = i;
		}
	}
	std::cout << "Max is " << max << " in position " << count << std::endl;
	std::cin.get();
	return 0;
}
*/
int main()
{
	int arr[10] = { 1, 23, 0, 933, 0, 54, 23, 0, 12 };
	int min = arr[0], count = 0;
	for(int i = 0; i < 10; i++)
	{
		if(arr[i] <= min)
		{
			min = arr[i];
			count = i;
		}
	}
	std::cout << "Min is " << min << " in position " << count << std::endl;
	std::cin.get();
	return 0;
}