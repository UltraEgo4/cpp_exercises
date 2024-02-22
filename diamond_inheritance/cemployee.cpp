#include "cemployee.h"
#include <iostream>

bool CEmployee::smFlag = false;


CEmployee::CEmployee() : m_szName("")
{
}

CEmployee::CEmployee(const char* nm)
{	
	strcpy_s(m_szName, strlen(m_szName), nm);
}

CEmployee::~CEmployee()
{
}

const char* CEmployee::GetName() const
{
	return m_szName;
}

void CEmployee::Input(void)
{

	if (!smFlag) {
		std::cout << "Name:";
		std::cin >> m_szName;
		smFlag = false;
	}
}

float CEmployee::ComputePay(void)
{
	return 0.0f;
}

void CEmployee::Display(void)
{
	if (!smFlag) {
		std::cout << "Name: " << GetName() << "\t";
		smFlag = false;
	}
	
}

bool compareSalary(CEmployee* a,CEmployee* b)
{
	return a->ComputePay() > b->ComputePay();
}

