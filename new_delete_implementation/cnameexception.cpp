#include <cstring>
#include <cstdlib>

#include "cnameexception.h"


CNameException::CNameException(const char* s)
{
	errorMsg = new char[strlen(s) + 1];
	if (errorMsg)
	{
		strcpy_s(errorMsg, strlen(s) + 1, s);
	}
}

CNameException::~CNameException()
{
	delete[] errorMsg;
}

const char* CNameException::what(void)
{
	return errorMsg;
}
