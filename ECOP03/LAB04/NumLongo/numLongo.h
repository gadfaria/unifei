#ifndef NUMLONGO_H
#define NUMLONGO_H
#define T_NUM 30

#include <iostream>

using namespace std;

class NumLongo
{
private:
	int num[T_NUM];

public:
	static int count;
	NumLongo();
	~NumLongo();

	void operator+(NumLongo &);
	void operator-(NumLongo &);

	int operator>(NumLongo &);
	int operator<(NumLongo &);
	int operator!=(NumLongo &);
	int operator==(NumLongo &);
	int operator>=(NumLongo &);
	int operator<=(NumLongo &);

	friend istream &operator>>(istream &in, NumLongo &numT);
	friend ostream &operator<<(ostream &out, NumLongo &numT);
};

#endif
