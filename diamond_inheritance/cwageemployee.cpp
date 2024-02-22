#include "cwageemployee.h"
#include <iostream>

CWageEmployee::CWageEmployee() : CEmployee(), m_fWage(0.0f),m_fHours(0.0f)
{
}

CWageEmployee::CWageEmployee(const char* nm) :CEmployee(nm)
{
	m_fWage = 0;
	m_fHours = 0;
}

CWageEmployee::~CWageEmployee()
{
}

void CWageEmployee::SetWage(float wg)
{
	m_fWage = wg;
}

void CWageEmployee::SetHours(float hrs)
{
	m_fHours = hrs;
}

void CWageEmployee::Input(void)
{
	CEmployee::Input();
	std::cout << "Wage: ";
	std::cin >> m_fWage;
	std::cout << "Hours: ";
	std::cin >> m_fHours;

}

float CWageEmployee::ComputePay(void)
{
	return m_fWage * m_fHours;
}

void CWageEmployee::Display(void)
{
	CEmployee::Display();
	std::cout << "Wage: " << m_fWage << "\t" << "Hours: " << m_fHours << "\t";

}
