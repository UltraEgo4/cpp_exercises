
#include <string>
#include <iostream>
#include <algorithm>

#include "menu.h"
#include "cwageemployee.h"
#include "csalesperson.h"
#include "cmanager.h"
#include "csalesmanager.h"



Menu::Menu() : ctr(0)
{
    for (int i = 0; i < MAXTEST; ++i) {
        employees[i] = nullptr;
    }
}

Menu::~Menu()
{
    for (int i = 0; i < MAXTEST; ++i) {
        delete employees[i];
    }
}

void Menu::mainMenu()
{
    int input = 0;
    do
    {
        std::cout << "***************" << "\n1. Input" << "\n2. List"
          << "\n3. Payment"
          << "\n4. List sorted by decreasing payment, average payment" << "\n5. Exit\n";
std::cin >> input;

    } while (input< 1 || input > 5);
    
    switch (input) {
    case 1:
        subMenu();
        break;
    case 2:
        printList();
        break;
    case 3:
        printSalary();
        break;
    case 4:
        printSortedList();
        break;
    case 5:
        break;
    }

}

void Menu::subMenu()
{
    if (ctr == MAXTEST)
    {
        std::cout << "Not enough space, restart the program!";
        mainMenu();
    }
    int input = 0;
    do
    {
        std::cout << "***************" << "\n1.Wage Employee" << "\n2.Sales Person"
            << "\n3.Manager"
            << "\n4.Sales Manager" << "\n5.Vissza\n";
        std::cin >> input;
    } while (input < 1 || input > 5);

    switch (input) {
    case 1:
        employees[ctr] = new CWageEmployee();
        employees[ctr]->Input();
        break;
    case 2:
        employees[ctr] = new CSalesPerson();
        employees[ctr]->Input();
        break;
    case 3:
        employees[ctr] = new CManager();
        employees[ctr]->Input();
        break;
    case 4:
        employees[ctr] = new CSalesManager();
        employees[ctr]->Input();
        break;
    case 5:
        break;
    }
    ctr++;
    mainMenu();
}

void Menu::printList()
{
    if (ctr != 0)
    {
        for (size_t i = 0; i < ctr; i++)
        {
            employees[i]->Display();
            std::cout << "\n";
        }
    }
    else
    {
        std::cout << "The list is empty!" << "\n";
    }
    
    mainMenu();
}

void Menu::printSalary()
{
    std::string input;
    std::cout << "Name: ";
    std::cin >> input;

    bool matchFlag = false;
    if (ctr != 0)
    {
        for (size_t i = 0; i < ctr; i++)
        {
            if (employees[i]->GetName() == input)
            {
                std::cout << "Name: " << input << "\t" << "Salary: " << employees[i]->ComputePay() << "\n";
                matchFlag = true;
                break;
            }
        }

    }
    if (!matchFlag)
    {
        std::cout << "No element with give name!" << "\n";
    }

    mainMenu();
}

void Menu::printSortedList()
{
    if (ctr != 0)
    {
        CEmployee* tempArray[MAXTEST];
        for (size_t i = 0; i < ctr; i++)
        {
            tempArray[i] = employees[i];
        }
        std::sort(tempArray, tempArray + ctr, compareSalary);

        float sum = 0;
        for (size_t i = 0; i < ctr; i++)
        {
            float salary = tempArray[i]->ComputePay();
            std::cout << i << ".Pay: " << salary << "\t";
            sum += salary;
            tempArray[i]->Display();
            std::cout << "\n";
        }
        std::cout << "Average: " << sum / ctr << "\n";
    }
    else
    {
        std::cout << "The list is empty!" << "\n";
    }
    mainMenu();
}

