#pragma once
#define MYDEBUG
#include <ostream>
class CMyString
{
public:
	CMyString();

	CMyString(const char* psz);

	CMyString(char ch, size_t repeat = 1);

	CMyString(const CMyString& str);

	~CMyString();

	CMyString(CMyString&& str) noexcept;

	size_t size() const;
	size_t capacity() const;

	const char* c_str() const;
	void clear();
	char getat(size_t index) const;
	void setat(size_t index, char ch);
	bool empty() const;

	double stod();
	void display() const;

	void initempty();

	void append(const char* psz, unsigned offset = 0, unsigned count = ~0);
	CMyString substring(size_t pos, size_t len = (~0));
	void shrink_to_fit();
	void swap(CMyString& str1);

	//operators
	CMyString& operator=(const CMyString& str);
	CMyString& operator=(CMyString&& str) noexcept;
	char& operator[](size_t nIndex);
	bool operator==(const CMyString& s1);
	operator const char* ();
	CMyString& operator+=(const CMyString& str);
	CMyString& operator+=(const char* p);
	CMyString operator +(const CMyString& str1);

#ifdef MYDEBUG
	static unsigned objcount();
#endif // MYDEBUG
	

private:
	char* m_pchData;
	size_t m_nDataLength;
	size_t m_nAllocLength;

#ifdef MYDEBUG
	static unsigned m_iCounter;
#endif // MYDEBUG

	
};
std::ostream& operator << (std::ostream& os, CMyString& s);