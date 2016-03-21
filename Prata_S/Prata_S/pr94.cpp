#include <iostream>
#include "nmsales.h"

int main()
{
	SALES::Sales objects[2];
	double arr[2][4] = { { 10.0, 43.23, 11.9, 23.6 }, { 45.11, 45.76, 54.8, 23.76 } };
	SALES::set_sales(objects[0], &arr[0][0], 4);
	SALES::set_sales(objects[1], &arr[1][0], 4);
	SALES::show_sales(objects[0]);
	SALES::show_sales(objects[1]);
	
	std::cin.get();
	return 0;
}