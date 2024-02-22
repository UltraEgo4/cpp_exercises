#pragma once
#include "cemployee.h"
class CManager : public virtual CEmployee
{
public:
	CManager();
	CManager(const char* nm);
	~CManager();

	void SetSalary(float salary);

	void Input(void);
	float ComputePay(void);
	void Display(void);

private:
	float m_fWeeklySalary;
};

