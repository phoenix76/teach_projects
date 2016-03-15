1 Функции с малым количеством кода

2
а. void song(char *name, int times = 1);
б. Никаких
в. Нет, аргументы по умолчанию должны объявляться справа налево

3
void iquote(int arg)
{
	std::cout << '\"' << arg '\"' << std::endl;
}
void iquote(double arg)
{
	std::cout << '\"' << arg '\"' << std::endl;
}
void iquote(std::string arg)
{
	std::cout << '\"' << arg '\"' << std::endl;
}

4
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
а
void show(const box &s)
{
	cout << s.maker << '\n';
	cout << s.height << '\n';
	cout << s.width << '\n';
	cout << s.length << '\n';
	cout << s.volume << '\n';
}
б
void acum(box &s)
{
	s.volume = s.height * s.width * s.length;
}

5
void fill(std::array<double, Seasons> &pref)
{
	using namespace std;
	for(int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}
void show(const std::array<double, Seasons> &dref)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for(int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total expenses : $" << total << endl;
}

6
a
Аргумент по умолчанию
double mass(double density, double volume = 1.0);
Перегрузка
double mass(double density, double volume);
double mass(double density);


б
Перегрузка
void repeat(int num, const char* str);
void repeat(const char *str);

в
Перегрузка
int average(int a, int b);
double average(double a, double b);

г
Это невозможно

7
template <typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

8
template <> box & maxbox<box>(const box &b1, const box &b2)
{
	if(b1.volume > b2.volume)
		return b1;
	else
		return b2;
}

9
v1 - float
v2 - float & or float?
v3 - float &
v4 - int
v5 - double