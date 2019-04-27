#include "Task.h"
#include <iostream>
using namespace std;

Task::Task()
{
	des = "";
	date = Date();
}

Task::~Task()
{
	des.clear();
	date.~Date();
}

Date Task::GetDate()
{
	return date;
}

Type1::Type1()
{
	des = "";
	date = Date();
}
Type1::Type1(string _des, Date dat)
{
	des = _des;
	date = Date(dat);
}
Type1::~Type1()
{
	des.clear();
	date.~Date();
}
void Type1::Print()const
{
	cout << des;
}
Type2::Type2()
{
	des = "";
	date = Date();
	time = Time();
	dur = 0;
}
Type2::Type2(string _des, Date dat, Time t, int d)
{
	des = _des;
	date = Date(dat);
	time = Time(t);
	dur = d;
}
Type2::~Type2()
{
	des.clear();
	date.~Date();
	time.~Time();
	dur = 0;
}
void Type2::Print()const
{
	time.Print();
	cout << des << " durations: " << dur;
}