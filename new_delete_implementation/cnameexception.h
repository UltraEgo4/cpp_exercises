#pragma once
class CNameException
{
public:


	CNameException(const char* s);
	~CNameException();
	const char* what(void); 

	static constexpr const char* ErrInvalidPtr = "Error: invalid pointer!"; // When deleting, printing, NOT AN EXCEPTION!
static constexpr const char* ErrOutofMemory = "Error: out of memory!"; // new
static constexpr const char* ErrNullPtr = "Error: null pointer usage!"; // constructor
static constexpr const char* ErrTooLong = "Error: length error"; // constructor
static constexpr const char* ErrOutOfRange = "Error: index error!"; // block number is too large, isfree
//static constexpr const char* ErrOutOfRange = "Error: index error!";
static constexpr const char* ErrUnexpected = "Error: unexpected error!"; // undefined error case


private:
	char* errorMsg;


};


