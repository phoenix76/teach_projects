#include <iostream>
#include "nmsales.h"

namespace SALES
{
	void set_sales(Sales &s, const double arr[], int n)
	{
		for(int i = 0; i < n; i++)
			s.sales[i] = arr[i];
		double min = s.sales[0];
		double max = s.sales[0];
		s.average = (s.sales[0] + s.sales[1] + s.sales[2] + s.sales[3]) / n;
		for(int i = 1; i < n; i++)
		{
			if(min > s.sales[i])	min = s.sales[i];
			if(max < s.sales[i])	max = s.sales[i];
		}
		s.min = min; s.max = max;
	}
	void show_sales(const Sales &s)
	{
		std::cout << "Quarters:\n";
		for(int i = 0; i < quarters; i++)
			std::cout << "For quarter " << i + 1 << ": " << s.sales[i] << '\n';
		std::cout << "Average: " << s.average << '\n';
		std::cout << "Max: " << s.max << '\n';
		std::cout << "Min: " << s.min << "\n\n";
	}
}