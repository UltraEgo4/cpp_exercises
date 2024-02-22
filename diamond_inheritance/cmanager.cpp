#include "cmanager.h"
#include <iostream>

CManager::CManager() : CEmployee(),m_fWeeklySalary(0.0f)
{
}

CManager::CManager(const char* nm) : CEmployee(nm)
{
	m_fWeeklySalary = 0;
}

CManager::~CManager()
{
}

void CManager::SetSalary(float salary)
{
	m_fWeeklySalary = salary;
}

void CManager::Input(void)
{
	CEmployee::Input();
	std::cout << "Weekly Salary: ";
	std::cin >> m_fWeeklySalary;

}

float CManager::ComputePay(void)
{
	return m_fWeeklySalary;
}

void CManager::Display(void)
{
	CEmployee::Display();
	std::cout << "Weekly Salary: " << m_fWeeklySalary << "\t";

}
