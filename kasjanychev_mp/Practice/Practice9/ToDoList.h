#pragma once
#include "Task.h"

class ToDoList
{
private:
	Task** list;
	int n;
public:
	ToDoList();
	ToDoList(int n);
};