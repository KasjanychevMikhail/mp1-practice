#pragma once
#include "vectors.h"
#include <iostream>
#include <math.h>
using namespace std;

Vectors::Vectors()
{
	arr = NULL;
	s = 0;
}

Vectors::Vectors(int x)
{
	arr = new double[x];
	s = x;
}

Vectors::Vectors(const Vectors& vct)
{
	arr = new double[vct.s];
	s = vct.s;
	for (int i = 0; i < s; i++)
		arr[i] = vct.arr[i];
}

Vectors::~Vectors()
{
	delete[] arr;
	s = 0;
}

Vectors Vectors::operator+ (const Vectors & temp) const
{
	if (s != temp.s)
		throw "Size";
	Vectors rez(temp);
	for (int i = 0; i < s; i++)
		rez.arr[i] += arr[i];
	return rez;
}

Vectors Vectors::operator- (const Vectors & temp) const
{
	if (s != temp.s)
		throw "Size";
	Vectors rez(*this);
	for (int i = 0; i < s; i++)
		rez.arr[i] -= temp.arr[i];
	return rez;
}
double Vectors::operator* (const Vectors & temp) const
{
	if (s != temp.s)
		throw "Size";
	double rez = 0;
	for (int i = 0; i < s; i++)
		rez += arr[i] * temp.arr[i];
	return rez;
}
Vectors Vectors::operator+ (double temp) const
{
	Vectors rez(*this);
	for (int i = 0; i < s; i++)
		rez.arr[i] += temp;
	return rez;
}
Vectors Vectors::operator- (double temp) const
{
	Vectors rez(*this);
	for (int i = 0; i < s; i++)
		rez.arr[i] -= temp;
	return rez;
}
Vectors Vectors::operator* (double temp) const
{
	Vectors rez(*this);
	for (int i = 0; i < s; i++)
		rez.arr[i] *= temp;
	return rez;
}
const Vectors& Vectors::operator= (const Vectors & temp)
{
	delete[] arr;
	s = temp.s;
	arr = new double[s];
	for (int i = 0; i < s; i++)
		arr[i] = temp.arr[i];
	return *this;
}
const double& Vectors::operator[] (int i)const
{
	if ((i < 0) || (i >= s))
		throw "El";
	return arr[i];
}
double& Vectors::operator[] (int i)
{
	if ((i < 0) || (i >= s))
		throw "El";
	return arr[i];
}
double Vectors::Lenght()const
{
	double rez = 0;
	for (int i = 0; i < s; i++)
		rez += arr[i] * arr[i];
	rez = sqrt(rez);
	return rez;
}
Vectors& Vectors::operator+= (const Vectors & temp)
{
	if (s != temp.s)
		throw "Size";
	for (int i = 0; i < s; i++)
		arr[i] += temp.arr[i];
	return *this;
}
Vectors& Vectors::operator-= (const Vectors & temp)
{
	if (s != temp.s)
		throw "Size";
	for (int i = 0; i < s; i++)
		arr[i] -= temp.arr[i];
	return *this;
}
Vectors& Vectors::operator*= (double temp)
{
	for (int i = 0; i < s; i++)
		arr[i] *= temp;
	return *this;
}
bool Vectors::operator== (const Vectors& temp) const
{

	if (s != temp.s) return false;
	int f = 0;
	for (int i = 0; i < s; i++)
	{
		if (arr[i] != temp.arr[i]) f = 1;
	}
	if (f == 1) return false;
	return true;
}
bool Vectors::operator!= (const Vectors& temp) const
{
	if (s != temp.s) return true;
	int f = 0;
	for (int i = 0; i < s; i++)
	{
		if (arr[i] != temp.arr[i]) f = 1;
	}
	if (f == 1) return true;
	return false;
}