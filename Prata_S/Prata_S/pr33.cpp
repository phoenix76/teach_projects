#include <iostream>

int main()
{
	unsigned int degrees, minutes, seconds;

	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	std::cout << "Enter a latitude in degrees, minutes and seconds:" << std::endl;
	std::cout << "First, enter the degrees: ";				std::cin >> degrees;
	std::cout << "Next, enter the minutes af arc: ";		std::cin >> minutes;
	std::cout << "Finally, enter the seconds of arc: ";		std::cin >> seconds;

	std::cout << "\n" << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = "
		<< (float)degrees+(float)minutes / 60.0f + ((float)seconds / 60.0f) / 60.0f << " degrees.\n" << std::endl;

	system("pause");
	return 0;
}