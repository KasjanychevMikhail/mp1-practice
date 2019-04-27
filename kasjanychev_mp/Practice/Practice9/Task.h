#pragma once
#include "Date.h"
#include "Time.h"
#include <string>
using namespace std;

class Task
{
protected:
	string des;
	Date date;
public:
	Task();
	virtual ~Task();
	virtual void Print() = 0;
	Date GetDate();
};

class Type1 :public Task
{
public:
	Type1();
	Type1(string _des, Date dat);
	~Type1();
	void Print()const;
};

class Type2 :public Task
{
private:
	Time time;
	int dur;
public:
	Type2();
	Type2(string _des, Date dat, Time t, int d);
	~Type2();
	void Print()const;
};