#1
���������������� ���, �����������, � ������������ ������������ ������.
���������� ������ � ������-�����.
#2
����������� private ������. � �������� ���������� ������������ ������ ������ ������ ��� �������������� � �������.
#3
����� �������� ������������ ������������� �����, ������ - ��� ��������� ������.
���������� ������ ������� ����� ���, �� �� ������� ������� ������.
#4
������� ����������� ����� ������������ ������.
#5
class Bank
{
public:
	Bank(const std::string &nm, int id, double balance = 100.0);
	void ShowInfo() const;
	void Add(double money);
	void Withdraw(double money);

private:
	std::string name;
	int number;
	double balance;
};
#6
������������ ���������� ��� �������� �������, ����������� ��� �����������.
#7
Bank::Bank(const std::string &nm, int id, double bal)
{
	name = nm;
	number = id;
	balance = bal;
}