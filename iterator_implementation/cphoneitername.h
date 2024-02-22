#pragma once
#include "cphonelist.h"
class CPhoneIterName
{
public:
	CPhoneIterName(CPhoneList& m);
	~CPhoneIterName();
	Record* begin();
	Record* prev();
	Record* next();
	Record* end();

	int size();
	Record* search(const char* key);

	Record* operator++(); //pre
	Record* operator++(int n); //post

	unsigned* sorted;

private:
	CPhoneList* const m_cpList;
	int m_iCurrentIndex;

	//own defined


	void mysort(Record* inputArr, unsigned size);
};

