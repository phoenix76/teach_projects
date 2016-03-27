#include <iostream>

class test
{
public:
	test() { x = 100; }
	friend int operator+ (int x, test &t) { t.x += x; return x; }
	int operator+ (const test &t) { x += t.x; return x; }
	void Show() const { std::cout << x << std::endl; }

private:
	int x;
};

int main()
{
	test t1;
	test t2;
	std::cout << t1 + t2 << '\n';
	t1.Show();
	std::cout << 23 + t2 << '\n';
	t2.Show();
	std::cin.get();
	return 0;
}