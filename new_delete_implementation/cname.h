#pragma once
#define MAXNAMES 5
#define MAXNAME 48
class CName
{
public:
	CName();
	CName(const char* s);
	~CName();
	static void display();
	const char* getname();
	static size_t getcnt();
	static bool isfree(size_t bn);
	void* operator new(size_t size);
	static void clearmem();
	static unsigned char get(size_t y, size_t x);
	void operator delete(void* ptr);
	CName& operator=(const CName& cn);

	//own defined
	void initializeIsEmptyArray();
private:
	char m_szName[MAXNAME + 1];
	//own defined
	//int indexInArray;
	

	//unsigned getIndex(); // current index of *this inisde the dataArray
};

