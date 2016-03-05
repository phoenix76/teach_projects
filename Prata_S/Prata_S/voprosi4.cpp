#1
char actor[30];
short betsie[100];
float chuck[13];
long double dipsea[64];

#2
std::array<char, 30>actor;
std::array<short, 100>betsie;
std::array<float, 13>chuck;
std::array<long double, 64>dipsea;

#3
int iar[5] = { 1, 3, 5, 7, 9 };

#4
int even = iar[0] + iar[4];

#5
std::cout << ideas[1] << std::endl;

#6
char charr[] = "cheeseburger";

#7
std::string str = "Waldorf Salad";

#8
struct fish
{
	std::string name;
	int weidth;
	float lenght;
};

#9
fish m_fish = { "forel", 10, 45.8f };

#10
enum Response
{
	Yes = 1, No = 0, Maybe = 2
};

#11
double ted;
double *pted = &ted;
std::cout << *pted << std::endl;

#12
float treacle[10];
float *ptreacle = treacle;
float *pptreacle = &treacle[0];
std::cout << ptreacle[0] << *(ptreacle + 9);

#13
int count;
std::cin >> count;
int *parr = new int[count];
std::vector<int>vec(count);

#14
Выведет адрес первого символа;

#15
fish *pfish = new fish;
getline(cin, pfish->name);

#16
Числовой ввод не пройдет;

#17
#include <vector>
#include <array>
#include <string>

const short lenght = 10;
std::vector<std::string>str1(lenght);
std::array<std::string, lenght>str2;