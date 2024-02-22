#include "csalesmanager.h"
#include <iostream>



CSalesManager::CSalesManager() : CSalesPerson(), m_fAnnualCommission(0.0f)
{
}

CSalesManager::CSalesManager(const char* nm) : CSalesPerson(nm)
{
	m_fAnnualCommission = 0;
}

CSalesManager::~CSalesManager()
{
}

void CSalesManager::SetAnnualCommission(float anncomm)
{
	m_fAnnualCommission = anncomm;
}

void CSalesManager::Input(void)
{

	CSalesPerson::Input();
	CEmployee::smFlag = true;
	CManager::Input();
	std::cout << "Annual Commission: ";
	std::cin >> m_fAnnualCommission;
	CEmployee::smFlag = false;
	
}

float CSalesManager::ComputePay(void)
{
	return CSalesPerson::ComputePay() + CManager::ComputePay() + m_fAnnualCommission;
}

void CSalesManager::Display(void)
{
	CSalesPerson::Display();
	CEmployee::smFlag = true;
	CManager::Display();
	std::cout << "Annual Commission: " << m_fAnnualCommission << "\t";
	CEmployee::smFlag = false;
	
}


