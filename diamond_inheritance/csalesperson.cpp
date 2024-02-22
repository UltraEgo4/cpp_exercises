#include "csalesperson.h"
#include <iostream>

CSalesPerson::CSalesPerson() : CWageEmployee(), m_fCommission(0.0f), m_fSalesMade(0.0f)
{
}

CSalesPerson::CSalesPerson(const char* nm):CWageEmployee(nm)
{
	m_fCommission = 0;
	m_fSalesMade = 0;
}

CSalesPerson::~CSalesPerson()
{
}

void CSalesPerson::SetCommision(float comm)
{
	m_fCommission = comm;
}

void CSalesPerson::SetSales(float sales)
{
	m_fSalesMade = sales;
}

void CSalesPerson::Input(void)
{
	CWageEmployee::Input();
	std::cout << "Commission: ";
	std::cin >> m_fCommission;
	std::cout << "Sales Made: ";
	std::cin >> m_fSalesMade;

}

float CSalesPerson::ComputePay(void)
{
	return CWageEmployee::ComputePay() + m_fCommission * m_fSalesMade;
}

void CSalesPerson::Display(void)
{
	CWageEmployee::Display();
	std::cout << "Commission: " << m_fCommission << "\t" << "Sales Made: " << m_fSalesMade << "\t";

}
