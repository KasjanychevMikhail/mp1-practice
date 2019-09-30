#pragma once
#include "vectors.h"
#include <iostream>
using namespace std;
void main()
{
	Vectors v1(3);
	Vectors v2(3);
	cin >> v2;
	Vectors v3(3);
	cin >> v3;
	try
	{
		v1 = v3 + v2;
		cout << "v1 = v2 + v1" << endl;
	}
	catch (const char* A)
	{
		cout << A << endl;
	}
	cout << v1 << endl << v2 << endl << v3 << endl;

	try
	{
		v1 = v3 - v2;
		cout << "v1 = v2 - v1" << endl;
	}
	catch (const char* A)
	{
		cout << A << endl;
	}
	cout << v1 << endl;

	v2 -= 5;
	cout << "v2 -= 5" << endl;
	cout << v2 << endl;

	v2 += 10;
	cout << "v2 += 10" << endl;
	cout << v2 << endl;

	v2 *= 1.5;
	cout << "v2 *= 1.5" << endl;
	cout << v2 << endl;

	v1 = v3 + 1.0;
	cout << "v1 = v3 + 1.0" << endl;
	cout << v1 << endl;

	double x;
	try
	{
		x = v2 * v3;
	}
	catch (char* er)
	{
		cout << er;
	}
	cout << "a * b = " << x;

	try
	{
		x = v2.Lenght();
	}
	catch (char* er)
	{
		cout << er;
	}
	cout << "c.len = " << x;

	try
	{
		cout << "c[0] = " << v2[0];
	}
	catch (char* er)
	{
		cout << er;
	}

	try
	{
		v2[0] = 10;
		cout << "c[0] = 10 = " << v2[0];
	}
	catch (char* er)
	{
		cout << er;
	}
}