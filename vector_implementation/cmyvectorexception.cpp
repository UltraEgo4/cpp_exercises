#include "cmyvectorexception.h"
#include <cstring>
#include <cstdlib>


CMyVectorException::CMyVectorException(const char* s)
{
	errorMsg = new char[strlen(s) + 1];
	if (errorMsg)
	{
		strcpy_s(errorMsg, strlen(s) + 1, s);
	}
}

CMyVectorException::~CMyVectorException()
{
	delete[] errorMsg;
}

const char* CMyVectorException::what(void)
{
	return errorMsg;
}
