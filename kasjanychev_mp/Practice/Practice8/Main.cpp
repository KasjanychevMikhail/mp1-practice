#include "Matrix.h"
#include <iostream>
using namespace std;

void main()
{
	int m, n;
	cout << "Vvedite razmernost";
	cin >> n >> m;
	Matrix a = Matrix(n, m);
	cout << "Vvedite razmernost";
	cin >> n >> m;
	Matrix b = Matrix(n, m);
	Matrix c;

	cout << "a + b" << endl;
	try
	{
		c = a + b;
	}
	catch (char* er)
	{
		cout << er;
	}

	cout << "a - b" << endl;
	try
	{
		c = a - b;
	}
	catch (char* er)
	{
		cout << er;
	}

	cout << "a * b" << endl;
	try
	{
		c = a * b;
	}
	catch (char* er)
	{
		cout << er;
	}

	cout << "a + 5";
	c = a + 5;

	cout << "a - 3";
	c = a - 3;

	cout << "a * 1.5";
	c = a * 1.5;

	try
	{
		cout << "c[0] = " << *c[0];
	}
	catch (char* er)
	{
		cout << er;
	}

	try
	{
		*c[0] = 10;
		cout << "c[0] = 10 = " << *c[0];
	}
	catch (char* er)
	{
		cout << er;
	} cin >> n;
}