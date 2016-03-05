#2

a) void ignor();
b) float tofu(int);
c) double mpg(double, double);
d) long summation(long[], int);
e) double doctor(const char*);
f) void ofcourse(boss);
j) char * plot(map*);

#3

void process(int arr[], int size, int val) {
	for(int i = 0; i < size; i++)
		arr[i] = val;
}

#4

void processPtr(double * const begin, double * const end, int val) {
	double *tmp = begin;
	while(tmp < end)
	{
		*tmp = val;
		tmp++;
	}
}

#5

double func(const double * arr, int n)
{
	double max = arr[0];
	for(int i = 1; i < n; i++)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}

#6

//ѕередаютс€ по значению, не требуетс€, т.к. не измен€ют исходные данные

#7

//”казатель на строку, строкова€ константа, массив char

#8

int replace(char *str, char c1, char c2)
{
	int count = 0;
	while(*str)
	{
		if(*str == c1)
		{
			*str = c2;
			count++;
		}
		str++;
	}
	return count;
}

#9

//¬ пером случае, происходит разыменование строковой константы, что эквивалентно const char * str = "pizza";	*str[0];
//¬о втором, так же разыменование константы и доступ к третьему элементу char str[] = "taco"; str[2];

#10

func(glitz s);
func(glitz); //value

func(glitz *s);
func(&glitz); //reference

#11

int judge(int (*pf)(const char*));

#12

struct applicant
{
	char name[30];
	int credit_ratings[3];
};

void showToValue(applicant s)
{
	std::cout << s.name << '\n';
	for(int i = 0; i < 3; i++)
		std::cout << s.credit_ratings[i] << '\n';
}

void showToReference(const applicant *sPtr)
{
	std::cout << sPtr->name << '\n';
	for(int i = 0; i < 3; i++)
		std::cout << sPtr->credit_ratings[i] << '\n';
}

#13

void f1(applicant *ptr);
const char * f2(const applicant *a1, const applicant *a2);

void (*p1)(applicant *) = f1;
typedef const char * (*p2)(const applicant*, const applicant*);

void (*ap[5])(applicant*);

p2 arr[10];
p2 (*ppfun)[10] = &arr;