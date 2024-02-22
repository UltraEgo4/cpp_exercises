#include <cstring>
#include <cstdlib>

#include "cmystringexception.h"


CMyStringException::CMyStringException(const char* s)
{
	errorMsg = new char[strlen(s) + 1];
	if (errorMsg)
	{
		strcpy_s(errorMsg, strlen(s) + 1, s);
	}
}

CMyStringException::~CMyStringException()
{
	delete [] errorMsg;
}

const char* CMyStringException::what(void)
{
	return errorMsg;
}
