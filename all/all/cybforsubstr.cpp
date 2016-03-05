#include <iostream>
using namespace std;
void insertComma(const char *str1, const char *str2, char **p);
int NumberOfStrings;
int main()
{
	cout << endl << " THIS PROGRAM CHANGES ENTRIES STRING (str1) ON ENTRIES (str2)." << endl << endl;
	cout << " Enter number of strings: ";
	cin >> NumberOfStrings;
	cout << endl;
	if(NumberOfStrings < 1)
	{
		cout << " You have entered incorrect value!" << endl << endl;
		system("PAUSE");
		return 0;
	}
	else
	{
		char str1[256];
		char str2[256];
		char **p = new char*[NumberOfStrings];
		for(int i = 0; i < NumberOfStrings; i++)
		{
			p[i] = new char[256];
			cout << " Enter " << i + 1 << " string: ";
			cin >> p[i];
		}
		cout << endl;
		getchar();
		cout << " Enter string which needs to be changed (str1): ";
		cin.getline(str1, 255);
		cout << " Enter string which it is needs to change (str2): ";
		cin.getline(str2, 255);
		cout << endl;
			insertComma(str1, str2, p);
		delete[] * p;
		cout << endl;
		system("PAUSE");
		return 0;
	}
}

void insertComma(const char *str1, const char *str2, char **p)
{
	for(int i = 0; i < NumberOfStrings; i++)
	{
		char *find = p[i];
		char temp[500];
		bool cont = true;
		strcpy_s(temp, p[i]);
		while(cont)
		{
			p[i] = strstr(find, str1);
			if(!(p[i]))
				cont = false;
			else
			{
				strncpy_s(temp, 255, temp, (int)p[i] - (int)find);
				strcat_s(temp, str2);
				strcat_s(temp, p[i] + strlen(str1));
				strcpy_s(find, 255, temp);
			}
		}
		cout << " String " << i + 1 << " after changes: " << temp << endl;
	}
}
