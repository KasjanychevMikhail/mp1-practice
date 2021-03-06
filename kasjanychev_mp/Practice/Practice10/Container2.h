#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Container<T*>
{
private:
	T** arr;
	int size;
	int max;
	void DopPam(int a);
public:
	Container();
	Container(int _size);
	Container(const Container& temp);
	~Container();

	bool IsFull()const;
	bool IsEmpty()const;

	int Find(T a)const;
	void Add(T a);
	void Remove(T a);
	T& operator[](int i);
	const T& operator[](int i)const;

	friend istream& operator>>(istream&, Container& c)
	{
		for (int i = 0; i < c.n; i++)
			in >> c[i];
		return in;
	}

	friend ostream& operator<<(ostream & out, const Container & c)
	{
		for (int i = 0; i < c.n; i++)
			out << c[i] << " ";
		return out;
	}
};

template <typename T>
Container<T*>::Container()
{
	size = 0;
	max = 0;
}

template <typename T>
Container<T*>::Container(int _size)
{
	max = _size;
	size = 0;
	arr = new T*[max];
}

template <typename T>
Container<T*>::Container(const Container& temp)
{
	size = temp.size;
	max = temp.max;
	arr = new T*[max];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new T;
		*arr[i] = temp.*arr[i];
	}
}

template <typename T>
Container<T*>::~Container()
{
	for (int i = 0; i < size; i++)
		delete arr[i];
	delete arr;
	size = 0;
	max = 0;
}

template <typename T>
bool Container<T*>::IsFull()const
{
	return (size == max);
}

template <typename T>
bool Container<T*>::IsEmpty()const
{
	return (size == 0);
}

template <typename T>
int Container<T*>::Find(T a)const
{
	for (int i = 0; i < size; i++)
		if (*arr[i] == a)
			return i;
	return -1;
}

template <typename T>
void Container<T*>::Add(T a)
{
	if (this->IsFull())
		this->DopPam(1);
	arr[size] = new T;
	*arr[size++] = a;
}

template <typename T>
void Container<T*>::Remove(T temp)
{
	if (this->IsEmpty())
		throw "Container is empty";
	int j = Find(temp);
	if (j == -1)
		throw "No elem";
	delete arr[j];
	arr[j] = arr[size - 1];
	delete arr[--size];
}

template <typename T>
void Container<T*>::DopPam(int a)
{
	max += a;
	T** temp = new T*[max];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	arr = temp;
}

template <typename T>
T& Container<T*>::operator[](int i)
{
	if ((i < 0) || (i >= size))
		throw "Out of Range";
	return *arr[i];
}

template <typename T>
const T& Container<T*>::operator[](int i)const
{
	if ((i < 0) || (i >= size))
		throw "Out of Range";
	return *arr[i];
}

template <typename T>
void Container<T*>::Print()const
{
	for (int i = 0; i < size; i++)
	{
		cout << *arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void Container<T*>::Fill(int _size)
{
	T a;
	for (int i = 0; i < _size; i++)
	{
		cin >> a;
		this->Add(a);
	}
}