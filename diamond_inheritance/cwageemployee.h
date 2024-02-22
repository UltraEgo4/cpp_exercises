#pragma once
#include "cemployee.h"
class CWageEmployee : public virtual CEmployee
{
public:
	CWageEmployee();
	CWageEmployee(const char* nm);
	~CWageEmployee();

	void SetWage(float wg);
	void SetHours(float hrs);

	void Input(void);
	float ComputePay(void);
	void Display(void);

private:
	float m_fWage;
	float m_fHours;
};

