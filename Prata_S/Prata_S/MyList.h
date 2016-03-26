#ifndef _MYLIST_H_
#define _MYLIST_H_
#include "Plorg.h"

typedef CPlorg Item;
class CMyList
{
public:
	CMyList() { top = 0; }
	void Push(Item*);
	void Pop();
	Item *GetItem(unsigned short);
	bool IsEmpty() const;
	bool IsFull() const;

private:
	static const int LIMIT = 10;
	Item *stack[LIMIT];
	unsigned short top;
};

#endif