#ifndef _CGOLF_H_
#define _CGOLF_H_

class CGolf
{
public:
	CGolf() {}
	CGolf(const char *name, int hc);

	void SetGolf();
	void Handicap(int hc);
	void Show() const;

private:
	static const int LEN = 40;
	char m_fullname[LEN];
	int m_handicap;
};

#endif