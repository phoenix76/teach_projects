#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>

const int matrix_size = 3;

void OutputMatrixToScreen(int(*)[matrix_size], int);										//����� ������� �� �����
void OutputMatrixToFile(int(*)[matrix_size], int, std::ofstream&);							//����� ������� � ����
void RandMatrix(int(*)[matrix_size], int(*)[matrix_size], int, int, int);					//��������� ������ �� ��������� int - int
void ReadMatrixFromKeyboard(int(*)[matrix_size], int);										//������ ������ � ����������
void ReadMatrixFromFile(int(*)[matrix_size], int(*)[matrix_size], int, std::ifstream&);		//������ ������ �� �����
void MultiplyMatrix(int(*)[matrix_size], int(*)[matrix_size], int(*)[matrix_size], int);	//������������ ������

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int m1[matrix_size][matrix_size], m2[matrix_size][matrix_size], finallyMatrix[matrix_size][matrix_size];
	std::ofstream outFile("outputMatrix.txt");
	std::ifstream inFile("inputMatrix.txt");
	if(outFile.is_open() && inFile.is_open())
	{
		char choice;
		std::cout << "������� ��������:\n"
			<< "1. ��������� ������� � ����������\n"
			<< "2. ��������� ������� �� �����\n"
			<< "3. ������������� �������\n"
			<< "Q - �����\n";
		std::cin >> choice;
		while(std::cin.get() != '\n');
		switch(choice)
		{
		case '1':
			std::cout << "��������� ������� #1\n";
			ReadMatrixFromKeyboard(m1, matrix_size);
			std::cout << "��������� ������� #2\n";
			ReadMatrixFromKeyboard(m2, matrix_size);
			MultiplyMatrix(m1, m2, finallyMatrix, matrix_size);
			std::cout << "��������� ������������ ������\n\n";
			OutputMatrixToScreen(finallyMatrix, matrix_size);
			OutputMatrixToFile(finallyMatrix, matrix_size, outFile);
			std::cout << "Done.\n";
			break;

		case '2':
			ReadMatrixFromFile(m1, m2, matrix_size, inFile);
			MultiplyMatrix(m1, m2, finallyMatrix, matrix_size);
			std::cout << "��������� ������������ ������\n\n";
			OutputMatrixToScreen(finallyMatrix, matrix_size);
			OutputMatrixToFile(finallyMatrix, matrix_size, outFile);
			std::cout << "Done.\n";
			break;

		case '3':
			int min, max;
			std::cout << "������� �������� ��������\nMin: ";
			std::cin >> min;
			while(!std::cin)
			{
				std::cin.clear();
				while(std::cin.get() != '\n');
				std::cout << "������� ���������� �������� ��� Min: ";
				std::cin >> min;
			}
			std::cout << "������� Max: ";
			std::cin >> max;
			while(max < min || !std::cin)
			{
				if(!std::cin)
				{
					std::cin.clear();
					while(std::cin.get() != '\n');
					std::cout << "������� ���������� �������� ��� Max: ";
					std::cin >> max;
				}
				else if(max < min)
				{
					std::cout << "������� ��������, ������� ��� Min ��� Max: ";
					std::cin >> max;
				}
			}
			RandMatrix(m1, m2, matrix_size, min, max);
			std::cout << "������� #1\n";
			OutputMatrixToScreen(m1, matrix_size);
			std::cout << "������� #2\n";
			OutputMatrixToScreen(m2, matrix_size);
			MultiplyMatrix(m1, m2, finallyMatrix, matrix_size);
			std::cout << "��������� ������������ ������\n\n";
			OutputMatrixToScreen(finallyMatrix, matrix_size);
			OutputMatrixToFile(finallyMatrix, matrix_size, outFile);
			while(std::cin.get() != '\n');
			std::cout << "Done.\n";
			break;

		case 'Q':
		case 'q':
			std::cout << "Exit.\n";
			while(std::cin.get() != '\n');
			break;
		default:
			while(std::cin.get() != '\n');
			break;
		}
	}
	else
		std::cout << "������ ������� �����. �����.\n";
	std::cin.get();
	return 0;
}
void OutputMatrixToScreen(int (*arr)[matrix_size], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(arr[i][j] >= 0)
			{
				if(arr[i][j] <= 9)
					std::cout << arr[i][j] << "         ";
				else if(arr[i][j] >= 10 && arr[i][j] <= 99)
					std::cout << arr[i][j] << "        ";
				else if(arr[i][j] >= 100 && arr[i][j] <= 999)
					std::cout << arr[i][j] << "       ";
				else if(arr[i][j] >= 1000 && arr[i][j] <= 9999)
					std::cout << arr[i][j] << "      ";
				else if(arr[i][j] >= 10000 && arr[i][j] <= 99999)
					std::cout << arr[i][j] << "     ";
				else if(arr[i][j] >= 100000 && arr[i][j] <= 999999)
					std::cout << arr[i][j] << "    ";
				else if(arr[i][j] >= 1000000)
					std::cout << arr[i][j] << "   ";
			}
			else
			{
				if(arr[i][j] >= -9)
					std::cout << arr[i][j] << "        ";
				else if(arr[i][j] <= -10 && arr[i][j] >= -99)
					std::cout << arr[i][j] << "       ";
				else if(arr[i][j] <= -100 && arr[i][j] >= -999)
					std::cout << arr[i][j] << "      ";
				else if(arr[i][j] <= -1000 && arr[i][j] >= -9999)
					std::cout << arr[i][j] << "     ";
				else if(arr[i][j] <= -10000 && arr[i][j] >= -99999)
					std::cout << arr[i][j] << "    ";
				else if(arr[i][j] <= -100000 && arr[i][j] >= -999999)
					std::cout << arr[i][j] << "   ";
				else if(arr[i][j] <= -1000000)
					std::cout << arr[i][j] << "  ";
			}
		}
		std::cout << "\n\n";
	}
	std::cout << '\n';
}
void OutputMatrixToFile(int (*arr)[matrix_size], int size, std::ofstream &fout)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(arr[i][j] > 0)
			{
				if(arr[i][j] <= 9)
					fout << arr[i][j] << "         ";
				else if(arr[i][j] >= 10 && arr[i][j] <= 99)
					fout << arr[i][j] << "        ";
				else if(arr[i][j] >= 100 && arr[i][j] <= 999)
					fout << arr[i][j] << "       ";
				else if(arr[i][j] >= 1000 && arr[i][j] <= 9999)
					fout << arr[i][j] << "      ";
				else if(arr[i][j] >= 10000 && arr[i][j] <= 99999)
					fout << arr[i][j] << "     ";
				else if(arr[i][j] >= 100000 && arr[i][j] <= 999999)
					fout << arr[i][j] << "    ";
				else if(arr[i][j] >= 1000000)
					fout << arr[i][j] << "   ";
			}
			else
			{
				if(arr[i][j] >= -9)
					fout << arr[i][j] << "        ";
				else if(arr[i][j] <= -10 && arr[i][j] >= -99)
					fout << arr[i][j] << "       ";
				else if(arr[i][j] <= -100 && arr[i][j] >= -999)
					fout << arr[i][j] << "      ";
				else if(arr[i][j] <= -1000 && arr[i][j] >= -9999)
					fout << arr[i][j] << "     ";
				else if(arr[i][j] <= -10000 && arr[i][j] >= -99999)
					fout << arr[i][j] << "    ";
				else if(arr[i][j] <= -100000 && arr[i][j] >= -999999)
					fout << arr[i][j] << "   ";
				else if(arr[i][j] <= -1000000)
					fout << arr[i][j] << "  ";
			}
		}
		fout << "\n\n\n";
	}
}
void RandMatrix(int (*m1)[matrix_size], int(*m2)[matrix_size], int size, int min, int max)
{
	srand((unsigned)time(NULL));
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			//�� ���� ++
			if(min == 0 && max > 0)
			{
				m1[i][j] = rand() % max + 1;
				m2[i][j] = rand() % max + 1;
			}
			//���� ��� �������� �������������
			else if(min > 0 && max > 0)
			{
				m1[i][j] = rand() % (max - min + 1) + min;
				m2[i][j] = rand() % (max - min + 1) + min;
			}
			//�� ������ �� ����
			else if(min < 0 && max == 0)
			{
				m1[i][j] = (rand() % (min * -1 + 1)) * -1;
				m2[i][j] = (rand() % (min * -1 + 1)) * -1;
			}
			//���� ��� �������� �������������
			else if(min < 0 && max < 0)
			{
				m1[i][j] = -((rand() % ((min * -1) - (max * -1) + 1)) + max * -1);
				m2[i][j] = -((rand() % ((min * -1) - (max * -1) + 1)) + max * -1);
			}
			//�� �������������� �� ��������������
			else if(min < 0 && max > 0)
			{
				m1[i][j] = rand() % (max - min + 1) + min;
				m2[i][j] = rand() % (max - min + 1) + min;
			}
		}
	}
}
void ReadMatrixFromKeyboard(int(*arr)[matrix_size], int size)
{
	int temp;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			std::cout << "������� [" << i << "][" << j << "]: ";
			while(!(std::cin >> temp))
			{
				std::cin.clear();
				while(std::cin.get() != '\n');
				std::cout << "������� ���������� �������� ��� �������� [" << i << "][" << j << "]: ";
			}
			arr[i][j] = temp;
		}
	}
	while(std::cin.get() != '\n');
}
void ReadMatrixFromFile(int(*m1)[matrix_size], int (*m2)[matrix_size], int size, std::ifstream &fin)
{
	int temp;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			fin >> temp;
			if(fin.eof() && j != size - 1)
			{
				std::cout << "������ � ����� ������, ��� ���������. �����.\n";
				exit(EXIT_FAILURE);
			}
			else if(fin.fail())
			{
				std::cout << "������ �� ������������� �����������. �����.\n";
				exit(EXIT_FAILURE);
			}
			m1[i][j] = temp;
		}
	}
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			fin >> temp;
			if(fin.eof() && j != size - 1)
			{
				std::cout << "������ � ����� ������, ��� ���������. �����.\n";
				exit(EXIT_FAILURE);
			}
			else if(fin.fail())
			{
				std::cout << "������ �� ������������� �����������. �����.\n";
				exit(EXIT_FAILURE);
			}
			m2[i][j] = temp;
		}
	}
}
void MultiplyMatrix(int(*m1)[matrix_size], int(*m2)[matrix_size], int(*mt)[matrix_size], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			mt[i][j] = 0;
	}
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			for(int k = 0; k < size; k++)
				mt[i][j] += m1[i][k] * m2[k][j];
		}
	}
}