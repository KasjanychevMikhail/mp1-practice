#pragma once
#include <iostream>
using namespace std;

template <typename T, int maxsize>
class mContainer
{
private:
	T* arr;
	int n;
public:
	mContainer();
	mContainer(int x);
	mContainer(const mContainer& temp);
	~mContainer();

	bool IsFull() const;
	bool IsEmpty() const;

	int Find(T a) const;
	void Add(T a);
	void Remove(T a);
	T* operator[](int i);

	void Print() const;
	void Fill();
};

template <typename T, int maxsize>
mContainer<T, maxsize>::mContainer()
{
	n = 0;
	arr = new T*[maxsize];
}

template <typename T, int maxsize>
mContainer<T, maxsize>::mContainer(const mContainer& temp)
{
	n = temp.n;
	arr = new T[maxsize];
	for (int i = 0; i < n; i++)
		arr[i] = temp.arr[i];
}

template <typename T, int maxsize>
mContainer<T, maxsize>::~mContainer()
{
	delete arr;
	n = 0;
}
template <typename T, int maxsize>
bool mContainer<T, maxsize>::IsFull() const
{
	return(n == maxsize);
}
template <typename T, int maxsize>
bool mContainer<T, maxsize>::IsEmpty() const
{
	return(n == 0);
}
template <typename T, int maxsize>
int mContainer<T, maxsize>::Find(T a) const
{

}
template <typename T, int maxsize>
void mContainer<T, maxsize>::Add(T a)
{

}
template <typename T, int maxsize>
void mContainer<T, maxsize>::Remove(T a)
{

}