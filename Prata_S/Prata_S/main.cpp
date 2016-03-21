#include <iostream>
#include "golf.h"
const int LEN = 3;

void setgolf(golf &g, const char *name, int hc);
int setgolf(golf &g);
void handicap(golf &g, int hc);
void showgolf(const golf &g);

int main()
{
	golf arr[LEN];
	char temp[40];
	int tempHc;
	std::cout << "Enter name of golf 1: ";
	std::cin.getline(temp, 40);
	std::cout << "Enter a handicap of golf 1: ";
	std::cin >> tempHc;
	while(std::cin.get() != '\n');
	setgolf(arr[0], temp, tempHc);
	if(!setgolf(arr[1]))
		exit(EXIT_FAILURE);
	else
		setgolf(arr[2]);
	showgolf(arr[0]);
	showgolf(arr[1]);
	showgolf(arr[2]);

	std::cout << "Enter a handicap: ";
	std::cin >> tempHc;
	while(std::cin.get() != '\n');
	handicap(arr[2], tempHc);
	showgolf(arr[2]);

	std::cin.get();
	return 0;
}