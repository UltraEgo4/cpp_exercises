#pragma once
#include "cemployee.h"
#define MAXTEST 5

class Menu
{
public:
	Menu();
	~Menu();

	void mainMenu();
	void subMenu();

	void printList();
	void printSalary();
	void printSortedList();


private:
	CEmployee* employees[MAXTEST];
	int ctr;
};

