#pragma once

class CEmployee
{
public:
	CEmployee();
	CEmployee(const char* nm);
	virtual ~CEmployee(); 

	const char* GetName() const;

	virtual void Input(void);
	virtual float ComputePay(void);
	virtual void Display(void); 

	

private:
	char m_szName[30];
	
protected:
	static bool smFlag;

};
bool compareSalary(CEmployee* a, CEmployee* b);

