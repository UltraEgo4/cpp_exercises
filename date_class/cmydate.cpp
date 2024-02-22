#include <iostream>
#include "cmydate.h"
#include "cmydateexception.h"


int CMyDate::daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

CMyDate::CMyDate() :m_iDay(1), m_iMonth(1), m_iYear(1970) {
}

CMyDate::CMyDate(int year, int month, int day) {
	m_iYear = 1970;
	m_iMonth = 1;
	m_iDay = 1;
	SetYear(year);
	SetMonth(month);
	SetDay(day);
	
	
	

}

CMyDate::~CMyDate() {
}

bool CMyDate::LeapYear(int inYear)
{

	if ((inYear % 4 == 0) && (inYear % 100 != 0) || (inYear % 400 == 0))
	{
		return true;
	}
	return false;
}

void CMyDate::Display() {
	const char* months[] = { "","january", "february", "march", "april", "may", "june",
	"july", "august", "september", "october", "november", "december" };

	std::cout << GetYear() << " " << months[GetMonth()] << " " << GetDay() << ".";

}

int CMyDate::DayOfTheYear() {
	int output = 0;

	if (LeapYear(m_iYear))		//leap year
	{
		daysInMonth[2] = 29;

	}
	for (size_t i = 0; i < GetMonth(); i++)
	{
		output += daysInMonth[i];
	}
	output += GetDay();
	return output;
}

int CMyDate::GetDay() {
	return m_iDay;
}

int CMyDate::GetMonth() {
	return m_iMonth;
}

int CMyDate::GetYear() {
	return m_iYear;
}

void CMyDate::SetDay(int day) {

	if (day < 1)
	{
		throw CMyDateException(CMyDateException::ErrMinDay);
	}
	if (LeapYear(m_iYear))
	{
		daysInMonth[2] = 29;
		if (day > daysInMonth[GetMonth()])
		{
			throw CMyDateException(CMyDateException::ErrMaxDay);
		}
	}
	else
	{
		daysInMonth[2] = 28;
		if (day > daysInMonth[GetMonth()])
		{
			throw CMyDateException(CMyDateException::ErrMaxDay);
		}
	}

	m_iDay = day;
}

void CMyDate::SetMonth(int month) {
	if (month < 1)
	{
		throw CMyDateException(CMyDateException::ErrMinMonth);
	}
	if (month > 12)
	{
		throw CMyDateException(CMyDateException::ErrMaxMonth);
	}
	
	if (m_iDay > daysInMonth[month])
	{
		throw CMyDateException(CMyDateException::ErrUnexpected);
	}
	
	


	m_iMonth = month;
}

void CMyDate::SetYear(int year) {
	if (year < 1970)
	{
		throw CMyDateException(CMyDateException::ErrMinYear);
	}


	if (LeapYear(m_iYear) && !LeapYear(year) && m_iMonth ==2 && m_iDay == 29) { //true, (false)->true,true
		throw CMyDateException(CMyDateException::ErrUnexpected);
	}
	else if (!LeapYear(m_iYear) && LeapYear(year) && m_iMonth == 2 && m_iDay == 29) {
	}
	else if (!LeapYear(year)  && m_iMonth == 2 &&  m_iDay == 29) {
		throw CMyDateException(CMyDateException::ErrUnexpected);
	}
	m_iYear = year;
}



