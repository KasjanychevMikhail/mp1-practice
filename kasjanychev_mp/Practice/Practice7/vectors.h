#pragma once
#include <iostream>
using namespace std;
class Vectors
{
private:
	int s;
	double *arr;
public:
	Vectors();
	Vectors(int x);
	Vectors(const Vectors& vct);
	~Vectors();
	Vectors operator+ (const Vectors & temp) const;
	Vectors operator- (const Vectors & temp) const;
	double operator* (const Vectors & temp) const;
	Vectors operator+ (double temp) const;
	Vectors operator- (double temp) const;
	Vectors operator* (double temp) const;
	const Vectors& operator= (const Vectors & temp);
	const double& operator[] (int i) const;
	double& operator[] (int i);
	double Lenght() const;
	Vectors& operator+= (const Vectors & temp);
	Vectors& operator-= (const Vectors & temp);
	Vectors& operator*= (double temp);
	bool operator== (const Vectors& temp) const;
	bool operator!= (const Vectors& temp) const;
	
	friend istream& operator>> (istream& in, Vectors& temp)
	{
		for (int i = 0; i < temp.s; i++)
			in >> temp.arr[i];
		return in;
	}

	friend ostream& operator<< (ostream& out, const Vectors& v)
	{
		for (int i = 0; i < v.s; i++)
			out << v[i] << " ";
		return out;
	}
};