#pragma once
#include "csalesperson.h"
#include "cmanager.h"
class CSalesManager : public CSalesPerson,CManager
{
public:
	CSalesManager();
	CSalesManager(const char* nm);
	~CSalesManager();

	void SetAnnualCommission(float anncomm);

	void Input(void);
	float ComputePay(void);
	void Display(void);

private:
	float m_fAnnualCommission;
};

