#include <cstring>
#include <cstdlib>

#include "cmydateexception.h"


CMyDateException::CMyDateException(const char* s)
{
	errorMsg = static_cast<char*>(malloc(strlen(s) + 1));
	if (errorMsg)
	{
		strcpy_s(errorMsg, strlen(s) + 1, s);
	}
}

CMyDateException::~CMyDateException()
{
	free(errorMsg);
}

const char* CMyDateException::what(void)
{
	return errorMsg;
}
