#include <cstring>
#include <iostream>
#include "cmystring.h"
#include "cmystringexception.h"

unsigned CMyString::m_iCounter = 0;

CMyString::CMyString()
{
	initempty();
	m_iCounter++;
}

CMyString::CMyString(const char* psz)
{
	if (psz == nullptr || psz[0] == '\0')
	{
		m_nDataLength = 0;
		m_nAllocLength = 1;
		m_pchData = new char[m_nAllocLength];
		m_pchData[0] = '\0';
	}
	else
	{
		m_nDataLength = strlen(psz);
		m_nAllocLength = m_nDataLength + 1;
		m_pchData = new char[m_nAllocLength];
		strcpy_s(m_pchData, m_nAllocLength, psz);
	}
	m_iCounter++;
}

CMyString::CMyString(char ch, size_t repeat)
{
	if (ch =='\0')
	{
		throw CMyStringException(CMyStringException::ErrInvalidChar);
	}
 	if (repeat <= 0)
	{
		throw CMyStringException(CMyStringException::ErrCount);
	}
	m_nDataLength = repeat;
	m_nAllocLength = m_nDataLength + 1;
	m_pchData = new char[m_nAllocLength];
	

	for (size_t i = 0; i < repeat; i++)
	{
		m_pchData[i] = ch;
	}
	m_pchData[repeat] = '\0';

	m_iCounter++;
}

CMyString::CMyString(const CMyString& str)
{
	m_nDataLength = str.m_nDataLength;
	m_nAllocLength = str.m_nDataLength + 1;
	m_pchData = new char[m_nAllocLength];

	if (str.m_pchData[0] == '\0')
	{		
		m_pchData[0] = '\0';
	}
	
	strcpy_s(m_pchData, m_nAllocLength, str.m_pchData);
	m_iCounter++;
}

CMyString::~CMyString()
{
	delete[] m_pchData;
	m_pchData = nullptr;
	m_iCounter--;
}

CMyString::CMyString(CMyString&& str) noexcept// move ctr
{
	m_pchData = str.m_pchData;
	m_nDataLength = str.m_nDataLength;
	m_nAllocLength = str.m_nAllocLength;

	str.initempty(); //clear memory, realloc
	m_iCounter++;
}

size_t CMyString::size() const
{
	return m_nDataLength;
}

size_t CMyString::capacity() const
{
	return m_nAllocLength;
}

const char* CMyString::c_str() const
{
	return this->m_pchData;
}

void CMyString::clear()
{
	for (size_t i = 0; i < m_nDataLength; i++)
	{
		m_pchData[i] = '\0';
	}
	m_nDataLength = 0;
}

char CMyString::getat(size_t index) const
{
	if (index >= m_nDataLength || (m_nDataLength == 0 && index == 0) || index < 0)
	{
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	}
	return m_pchData[index];

}

void CMyString::setat(size_t index, char ch)
{
	if (index >= m_nDataLength || (m_nDataLength == 0 && index == 0) ||index < 0)
	{
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	}
	if (ch =='\0')
	{
		throw CMyStringException(CMyStringException::ErrInvalidChar);
	}
	m_pchData[index] = ch;
}

bool CMyString::empty() const
{
	if (m_pchData[0] =='\0')
	{
		return true;
	}
	
	return false;
}

double CMyString::stod()
{
	double output = 0;
	double fraction = 1;
	bool negative = false;
	bool wsEncountered = false;         //flags
	bool signEncountered = false;
	bool dotEncountered = false;
	bool numberEncountered = false;

	while (*m_pchData != '\0') {
		if (*m_pchData == ' ' || *m_pchData == '\n' || *m_pchData == '\t' || *m_pchData == '\f' || *m_pchData == '\a' || *m_pchData == '\r') {
			if (signEncountered || dotEncountered || numberEncountered) {                           //check if <+->,<.>,<number> encountered, if yes then break because cant break order
				break;
			}
			wsEncountered = true;       //set ws flag true for future check
		}
		else if (*m_pchData == '-' || *m_pchData == '+') {
			if (signEncountered || numberEncountered || dotEncountered) {           //check double sign, and check if <number>,<.> encountered because cant break order
				break;
			}
			signEncountered = true;         //set flag

			if (*m_pchData == '-') {                //set negative to multiply output
				negative = true;
			}
		}
		else if (*m_pchData >= '0' && *m_pchData <= '9') {
			if (dotEncountered) {          //if theres decimal point
				fraction /= 10;    // divide the fraction by ten so we get the approriate significant value
				output += (*m_pchData - '0') * fraction;     // calculate the numeric value and multiply it by the fraction and then add it to the output
				numberEncountered = true;           // set flag
			}
			else {
				output = output * 10 + *m_pchData - '0'; // calculate the whole number part
				numberEncountered = true;           //set flag
			}
		}
		else if (*m_pchData == '.') {
			if (dotEncountered) {           //double dot check
				break;
			}
			dotEncountered = true;          //set flag
		}
		else
		{
			break;
		}
		m_pchData++;
	}
	if (negative){         //convert number to negative
		output *= -1;
	}
	return output;
}

void CMyString::display() const
{
	if (m_pchData[0] != '\0')
	{
		std::cout << m_pchData;
	}
	
	
}

void CMyString::initempty()
{
	m_nDataLength = 0;
	m_nAllocLength = 1;
	m_pchData = new char[m_nAllocLength];
	m_pchData[0] = '\0';
}

void CMyString::append(const char* psz, unsigned offset, unsigned count) //s1.append(s2) we are inside s1
{
	if (psz == nullptr || psz[0] == '\0' || m_pchData == psz)
	{
		//leave function
	}
	else if (offset > strlen(psz))
	{
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	}
	else if (count == 0)//|| count > strlen(psz)
	{
		throw CMyStringException(CMyStringException::ErrCount);
	}
	else if (m_nAllocLength - (m_nDataLength + 1) >= strlen(psz)) //ENOUGH SPACE inlcuding space for \0
	{
		if (count > strlen(psz))
		{
			count = strlen(psz);
		}
		for (size_t i = 0; i < count; i++)
		{
			m_pchData[m_nDataLength + i] = psz[offset + i];	//copies chars into buffer, starting point is the \0, so it overwrites
		}
		m_nDataLength += count;
		m_pchData[m_nDataLength] = '\0'; //sets \0 at the end

	}
	else if (m_nAllocLength - (m_nDataLength + 1) < strlen(psz)) // NOT ENOUGH SPACE inlcuding space for \0
	{
		if (count > strlen(psz))
		{
			count = strlen(psz);
		}
		char* temp = new char[m_nDataLength + strlen(psz) + 1];
		strcpy_s(temp, m_nDataLength + strlen(psz) + 1, m_pchData);


		delete[] m_pchData;

		m_nAllocLength = m_nDataLength + count + 1;

		//append
		for (size_t i = 0; i < count; i++)
		{
			temp[m_nDataLength + i] = psz[offset + i];	//copies chars into buffer, starting point is the \0, so it overwrites
		}
		m_nDataLength += count;


		m_pchData = new char[m_nAllocLength];
		for (size_t i = 0; i < m_nDataLength; i++)
		{
			m_pchData[i] = temp[i];
		}
		m_pchData[m_nDataLength] = '\0';
		delete[] temp;

	}

}

CMyString CMyString::substring(size_t pos, size_t len)
{
	if (m_nDataLength == pos || len == 0)
	{
		CMyString output;
		return output;
	}
	if (pos > m_nDataLength)
	{
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	}
	if (m_nDataLength< len || len == ~0)// if length less or length is huge 4<6 or 4 < len = 342423 then copy until end
	{
		//create temp
		CMyString temp;
		delete[] temp.m_pchData;
		temp.m_nDataLength = m_nDataLength - pos;
		temp.m_nAllocLength = m_nDataLength + 1;
		temp.m_pchData = new char[m_nAllocLength];

		for (size_t i = 0; (pos + i) != m_nAllocLength; i++)
		{
			temp.m_pchData[i] = m_pchData[pos + i];
		}
		return temp;
	}
	//default case
		CMyString temp;
		delete[] temp.m_pchData;
		temp.m_nDataLength = len;
		temp.m_nAllocLength = temp.m_nDataLength + 1;
		temp.m_pchData = new char[m_nAllocLength];

		for (size_t i = 0; i < len; i++)
		{
			temp.m_pchData[i] = m_pchData[pos + i];
		}
		temp.m_pchData[temp.m_nDataLength] = '\0';
		return temp;
	
}

void CMyString::shrink_to_fit()
{
	if (m_nAllocLength != m_nDataLength+ 1)
	{
		delete[] m_pchData;
		m_nAllocLength = m_nDataLength + 1;
		m_pchData = new char[m_nAllocLength];
		
	}
	
}

void CMyString::swap(CMyString& str1)
{
	std::swap(*this, str1);
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (m_nAllocLength > str.m_nDataLength) //ENOUGH SPACE inlcuding space for \0
	{
		strcpy_s(m_pchData, m_nAllocLength, str.m_pchData);
		m_nDataLength = str.m_nDataLength;
		return *this;
	}
	if (m_nAllocLength <= str.m_nDataLength) // NOT ENOUGH SPACE inlcuding space for \0
	{
		delete[] m_pchData;

		m_nDataLength = str.m_nDataLength;
		m_nAllocLength = str.m_nAllocLength;
		m_pchData = new char[m_nAllocLength];
		strcpy_s(m_pchData, m_nAllocLength, str.m_pchData);
		return *this;

	}
	return *this;

}

CMyString& CMyString::operator=(CMyString&& str) noexcept
{
	if (this != &str)
	{
		delete[] m_pchData;
		m_pchData = str.m_pchData;
		m_nDataLength = str.m_nDataLength;
		m_nAllocLength = str.m_nAllocLength;

		str.initempty();
	}
	
	return *this;
}

char& CMyString::operator[](size_t nIndex)
{
	if (nIndex >=0 && nIndex < m_nDataLength )
	{
		return m_pchData[nIndex];
	}
	else
	{
		throw CMyStringException(CMyStringException::ErrOutOfRange);
	}
}

bool CMyString::operator==(const CMyString& s1)
{
	if (m_nDataLength == s1.m_nDataLength)
	{
		int i = 0;
		while (i!= m_nDataLength && m_pchData[i] == s1.m_pchData[i])
		{
			i++;
		}
		if (i == m_nDataLength)
		{
			return true;
		}
	}
	return false;
}

CMyString::operator const char* () //c_str() function for the std string
{
	return m_pchData;
}

CMyString& CMyString::operator+=(const CMyString& str)
{
	char* proxy = new char[str.m_nAllocLength];
	strcpy_s(proxy, str.m_nAllocLength, str.m_pchData);
	proxy[str.m_nDataLength] = '\0';
		
	append(proxy);
	delete[] proxy;
	return *this;
}

CMyString& CMyString::operator+=(const char* p)
{
	append(p);
	return *this;
}

CMyString CMyString::operator+(const CMyString& str1)
{
	CMyString temp = *this;
	temp.append(str1.m_pchData);
	return temp;
}

unsigned CMyString::objcount()
{
	return m_iCounter;
}

std::ostream& operator<<(std::ostream& os, CMyString& s)
{
	const char* cstr = s;
	os << cstr;
	return os;
}

bool operator>(const CMyString& s1, const CMyString& s2)
{
	return std::strcmp(s1.m_pchData, s2.m_pchData) > 0;
}

bool operator<(const CMyString& s1, const CMyString& s2)
{
	return std::strcmp(s1.m_pchData, s2.m_pchData) < 0;
}
