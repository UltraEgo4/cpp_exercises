#pragma once
class CMyDate
{
public:
	CMyDate();
	CMyDate(int year, int month, int day);
	~CMyDate();

	bool LeapYear(int inYear);

	void Display();
	int DayOfTheYear();
	int GetDay();
	int GetMonth();
	int GetYear();
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);


private:
	static int daysInMonth[];

	int m_iDay;
	int m_iMonth;
	int m_iYear;

};

