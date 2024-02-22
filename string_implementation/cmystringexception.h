#pragma once
class CMyStringException
{
public:


	CMyStringException(const char* s);
	~CMyStringException();
	const char* what(void); 

	static constexpr const char* ErrOutOfRange = "Index error!";
	static constexpr const char* ErrInvalidChar = "Invalid character!";
	static constexpr const char* ErrCount = "Character number is 0";
	static constexpr const char* ErrUnexpected = "unexpected error";


private:
	char* errorMsg;


};
