#include "Container1.h"
#include "Container2.h"
#include <iostream>
using namespace std;

void main()
{
	Container1<int> C1(5, 10);
	try
	{
		C1.Fill();
	}
	catch (char* er)
	{
		cout << er << endl;
	}
	try
	{
		C1.Add(5);
	}
	catch (char* er)
	{
		cout << er << endl;
	}
	try
	{
		C1.Print();
	}
	catch (char* er)
	{
		cout << er << endl;
	}
	try
	{
		C1.Remove(1);
	}
	catch (char* er)
	{
		cout << er << endl;
	}
	try
	{
		C1.Print();
	}
	catch (char* er)
	{
		cout << er << endl;
	}
	
}