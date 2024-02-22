#pragma once
class CMyVectorException
{
public:


	CMyVectorException(const char* s);
	~CMyVectorException(); 
	const char* what(void); 

	static constexpr const char* ErrIndex = "Index error!";
	static constexpr const char* ErrEmpty = "Error: empty vector";
	static constexpr const char* ErrUnexpected = "Error: Unexpected error!";


private:

	char* errorMsg;
};

