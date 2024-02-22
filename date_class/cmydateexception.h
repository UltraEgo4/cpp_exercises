#pragma once
class CMyDateException
{
public:
	//CMyDateException(); 
	CMyDateException(const char* s);
	~CMyDateException(); 
	const char* what(void); // function to querry the reason of the exception

	static constexpr const char* ErrMinYear = "year is less then 1970";
	static constexpr const char* ErrMinDay = "day is less then 1";
	static constexpr const char* ErrMaxDay = "day is bigger then the give month number of days";
	static constexpr const char* ErrMinMonth = "month is less then 1";
	static constexpr const char* ErrMaxMonth = "month is bigger then 12";
	static constexpr const char* ErrUnexpected = "unexpected exception";


private:
	// buffer to store the error msg
	char* errorMsg;


};
