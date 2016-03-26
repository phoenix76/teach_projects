#include "MyList.h"
#include <iostream>

void CMyList::Push(Item *p)
{
	if(top < 9)
	{
		stack[top] = p;
		top++;
	}
	else
		std::cout << "List is full.\n";
}
void CMyList::Pop()
{
	if(top != 0)
	{
		stack[top] = nullptr;
		top--;
	}
	else
		std::cout << "List is empty.\n";
}
Item *CMyList::GetItem(unsigned short n)
{
	if(top >= n - 1)
		return stack[n - 1];
	else
		std::cout << "This element is not found.\n";
}
bool CMyList::IsEmpty() const { return top == 0; }
bool CMyList::IsFull() const { return top == 9; }