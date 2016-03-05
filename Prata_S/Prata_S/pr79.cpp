#include <iostream>
using namespace std;

const int SLEN = 30;
struct Student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(Student pa[], int n);
void display1(Student st);
void display2(const Student *ps);
void display3(const Student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while(cin.get() != '\n');
	Student *ptr_stu = new Student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for(int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		cout << endl;
		display2(&ptr_stu[i]);
		cout << endl;
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done.\n";
	cin.get();
	return 0;
}
int getinfo(Student pa[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		cout << "Enter the info for student #" << (i + 1) << ":\n";
		cout << "Name: ";
		cin.getline(pa[i].fullname, SLEN);
		if(!(*(pa[i].fullname)))
		{
			return i;
			break;
		}
		cout << "Hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "OOP level: ";
		cin >> pa[i].ooplevel;
		while(cin.get() != '\n');
	}
	return i;
}
void display1(Student st)
{
	cout << "display1() called.\n";
	cout << "Name: " << st.fullname << '\n';
	cout << "Hobby: " << st.hobby << '\n';
	cout << "OOP level: " << st.ooplevel << '\n';
}
void display2(const Student *ps)
{
	cout << "display2() called.\n";
	cout << "Name: " << ps->fullname << '\n';
	cout << "Hobby: " << ps->hobby << '\n';
	cout << "OOP level: " << ps->ooplevel << '\n';
}
void display3(const Student pa[], int n)
{
	cout << "display3 called.\n";
	for(int i = 0; i < n; i++)
	{
		cout << "Info for student #" << (i + 1) << ":\n";
		cout << "Name: " << pa[i].fullname << '\n';
		cout << "Hobby: " << pa[i].hobby << '\n';
		cout << "OOP level: " << pa[i].ooplevel << '\n';
		cout << endl << endl;
	}
}