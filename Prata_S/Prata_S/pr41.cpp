#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cctype>
#include <Windows.h>

struct sStudent
{
	char *firstName;
	char *lastName;
	unsigned short age;
	char grade;
};

char* StringProcessing(unsigned short);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	sStudent student;
	student.firstName = StringProcessing(1);
	student.lastName = StringProcessing(2);
	std::cout << "������� ������: ";
	std::cin.get(student.grade);
	std::cin.get();
	std::cout << "������� ��� �������: ";
	std::cin >> student.age;

	std::cout << "���: " << student.lastName << ',' << student.firstName << std::endl;
	if(student.grade == '�')
		std::cout << "������: " << 'B' << std::endl;
	if(student.grade == '�')
		std::cout << "������: " << 'A' << std::endl;
	std::cout << "�������: " << student.age << std::endl;

	delete student.firstName;
	delete student.lastName;

	system("pause");
	return 0;
}

char* StringProcessing(unsigned short inputType)
{
	char tempStr[100];
	if(inputType == 1)
		std::cout << "������� ���: ";
	if(inputType == 2)
		std::cout << "������� �������: ";
	std::cin.getline(tempStr, 99);
	char *tempPtr = new char[std::strlen(tempStr) + 1];
	std::strcpy(tempPtr, tempStr);
	return tempPtr;
}