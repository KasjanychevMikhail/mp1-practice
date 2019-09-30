#pragma once
#include <iostream>
using namespace std;
class Matrix
{
private:
	int cols, rows;
	double* arr;
public:
	Matrix();
	Matrix(int x, int y);
	Matrix(const Matrix& mat);
	~Matrix();

	Matrix operator+(const Matrix& mat) const;
	Matrix operator-(const Matrix& mat) const;
	Matrix operator*(const Matrix& mat) const;
	Matrix& operator+ (double x);
	Matrix& operator- (double x);
	Matrix& operator* (double x);

	double* operator[] (int i) const;
	const Matrix& operator=(const Matrix& mat);
	bool operator== (const Matrix& m) const;

	friend istream& operator>>(istream& in, Matrix& m)
	{
		for (int i = 0; i < (m.cols * m.rows); i++)
			in >> m.arr[i];
		return in;
	}

	friend ostream& operator<<(ostream &out, const Matrix& m)
	{
		for (int i = 0; i < (m.cols * m.rows); i++)
		{
			out << m.arr[i] << " ";
			if (i % m.rows == (m.rows - 1))
				out << endl;
		}
		return out;
	}
};
