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
	arr = new double[vct.raz];
	s = vct.raz;
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
	if (s != temp.raz)
		throw "Size";
	Vectors
}