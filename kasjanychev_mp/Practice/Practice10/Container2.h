#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Container2
{
private:
	T** arr;
	int size;
	int max;
public:
	Container2();
	Container2(int _size);
	Container2(const Container2& temp);
	~Container2();

	bool IsFull()const;
	bool IsEmpty()const;

	int Find(T a)const;
	void Add(T a);
	void Remove(T a);
	void DopPam(int a);
	T* operator[](int i);

	void Print()const;
	void Fill();
};

template <typename T>
Container2<T>::Container2()
{
	size = 0;
	arr = new T*[max];
}

template <typename T>
Container2<T>::Container2(int _size)
{
	size = _size;
	arr = new T*[max];
	for (int i = 0; i < size; i++)
		arr[i] = new T;
}

template <typename T>
Container2<T>::Container2(const Container2& temp)
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
Container2<T>::~Container2()
{
	for (int i = 0; i < size; i++)
		delete arr[i];
	delete arr;
	size = 0;
	max = 0;
}

template <typename T>
bool Container2<T>::IsFull()const
{
	return (size == max);
}

template <typename T>
bool Container2<T>::IsEmpty()const
{
	return (size == 0);
}

template <typename T>
int Container2<T>::Find(T a)const
{
	for (int i = 0; i < size; i++)
		if (*arr[i] == a)
			return i;
	return -1;
}

template <typename T>
void Container2<T>::Add(T a)
{
	if (this->IsFull())
		throw "Container is full";
	arr[size] = new T;
	*arr[size] = a;
	size++;
}

template <typename T>
void Container2<T>::Remove(T temp)
{
	if (this->IsEmpty())
		throw "Container is empty";
	int j = Find(temp);
	if (j == -1)
		throw "No elem";
	*arr[j] = *arr[size - 1];
	delete arr[size - 1];
	size--;
}

template <typename T>
void Container2<T>::DopPam(int a)
{
	T** temp = new T*[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = new T;
		*temp[i] = *arr[i];
		delete arr[i];
	}
	delete arr;
	max += a;
	arr = new T*[max];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new T;
		*arr[i] = *temp[i];
		delete temp[i];
	}
	delete temp;
}

template <typename T>
T * Container2<T>::operator[](int i)
{
	if ((i < 0) || (i >= size))
		throw "Out of Range";
	return arr[i];
}

template <typename T>
void Container2<T>::Print()const
{
	if (this->IsEmpty())
		throw "Container is empty";
	for (int i = 0; i < size; i++)
	{
		cout << *arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void Container2<T>::Fill()
{
	if (this->IsEmpty())
		throw "Container is empty";
	for (int i = 0; i < size; i++)
	{
		cin >> *arr[i];
	}
}