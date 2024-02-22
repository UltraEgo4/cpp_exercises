#include "cname.h"
#include <string.h>
#include "cnameexception.h"
#include <iostream>
#include <iomanip>

#include <crtdbg.h>


static unsigned char dataArray[MAXNAMES * sizeof(CName)];// whole allocated memory, this is what has blocks each block is sizeof(CName) size
static bool isEmptyArray[MAXNAMES];//false means its empty

CName::CName() : m_szName("")
{
}

CName::CName(const char* s)
{
	if (!s)
	{
		throw CNameException(CNameException::ErrNullPtr);
	}
	if (strlen(s) > MAXNAME)
	{
		throw CNameException(CNameException::ErrTooLong);
	}
	strcpy_s(m_szName, MAXNAME + 1, s);
}

CName::~CName()
{
}

void CName::display()
{

	
	int cnt = 0;
	for (size_t i = 0; i < MAXNAMES * sizeof(CName); ++i)
	{
		
		if (i == (MAXNAMES *sizeof(CName) - ((MAXNAMES-cnt) * sizeof(CName))))
		{
			std::cout << "\n" << cnt<<"."<< (isEmptyArray[cnt] ? "foglalt" : "szabad")<<":";
			cnt++;
		}
		std::cout << std::hex << static_cast<int>(dataArray[i]) << "|";
	}
	
}

const char* CName::getname()
{
	return this->m_szName;
}

size_t CName::getcnt()
{
	int output = 0;
	for (size_t i = 0; i < MAXNAMES; i++)
	{
		if (isEmptyArray[i])
		{
			output++;
		}
	}
	return output;
}

bool CName::isfree(size_t bn)
{
	if (bn >= MAXNAMES)
	{
		throw CNameException(CNameException::ErrOutOfRange);
	}
	return !isEmptyArray[bn]; //negated because have to return true if its empty
}

void* CName::operator new(size_t size)
{
	if (getcnt() == MAXNAMES)
	{
		throw CNameException(CNameException::ErrOutofMemory);
	}
	_CrtSetDebugFillThreshold(0);
	int i = 0;
	while (i < MAXNAMES && isEmptyArray[i])
	{
		i++;
	}
	if (!isEmptyArray[i])//if last element and also false (false means its empty)
	{
		void* memory = &dataArray[i * sizeof(CName)];
		memset(memory, 0, sizeof(CName));
		isEmptyArray[i] = true;
		return memory;
	}

	/*for (size_t i = 0; i <MAXNAMES; i++)
	{
		if (!isEmptyArray[i])
		{
			void* memory = &dataArray[i * sizeof(CName)];
			memset(memory, 0, sizeof(CName));
			isEmptyArray[i] = true;
			return memory;
		}
	}*/
	return nullptr;

	//ctr gets called
}

void CName::clearmem()
{
	//kell e delete itt?
	memset(dataArray, 0, sizeof(dataArray));
	memset(isEmptyArray, 0, sizeof(isEmptyArray));
}




unsigned char CName::get(size_t y, size_t x)
{
	return dataArray[MAXNAMES * sizeof(CName) - ((MAXNAMES - y) * sizeof(CName)) + x]; //x -1 previously
	//if string is shark x-1 so if the user wants the 2nd char it returns h not 0,1,2 a
	//formula to calculate blocks:
	//MAXNAMES * sizeof(CName) - ((MAXNAMES - cnt) * sizeof(CName))
	//whole blocksize          - MAXNAMES - block we want * block size 
}

void CName::operator delete(void* ptr)
{
	if (ptr && ptr >= dataArray && ptr < (dataArray + MAXNAMES * sizeof(CName)))
	{
		size_t index = ((unsigned char*)ptr - dataArray) / sizeof(CName);//calculate index
		if (index >= 0 && index < MAXNAMES)
		{
			isEmptyArray[index] = false;
		}
	}
	else
	{
		std::cout << CNameException::ErrInvalidPtr;
	}
	//dtr gets called
	//TODO: IMPLEMENT
}

CName& CName::operator=(const CName& cn)
{
	strcpy_s(m_szName, MAXNAME + 1, cn.m_szName);
	return *this;
}


void CName::initializeIsEmptyArray()
{
	for (size_t i = 0; i < MAXNAMES; i++)
	{
		isEmptyArray[i] = true;
	}
}
