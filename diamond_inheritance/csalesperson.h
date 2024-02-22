#pragma once
#include "cwageemployee.h"
class CSalesPerson : public CWageEmployee
{
public:
	CSalesPerson();
	CSalesPerson(const char* nm);
	~CSalesPerson();

	void SetCommision(float comm);
	void SetSales(float sales);


	void Input(void);
	float ComputePay(void);
	void Display(void);

private:
	float m_fCommission; 
	float m_fSalesMade;
};

