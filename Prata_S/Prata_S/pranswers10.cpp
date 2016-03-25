#1
Пользовательский тип, абстрактный, с возможностью инкапсуляции данных.
Содержащий методы и данные-члены.
#2
Посредством private секции. В открытом интерфейсе присутствуют только методы нужные для взаимодействия с классом.
#3
Класс является определяемым пользователем типом, объект - это экземпляр класса.
Объявление класса создает новый тип, но не создает объекта класса.
#4
Функции разделяются всеми экземплярами класса.
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
Конструкторы вызываются при создании объекта, деструкторы при уничтожении.
#7
Bank::Bank(const std::string &nm, int id, double bal)
{
	name = nm;
	number = id;
	balance = bal;
}