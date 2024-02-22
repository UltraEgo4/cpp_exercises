#pragma once
#include <ostream>

#define MAXLENGTH 10
#define MAXNAME 32
#define MAXNUMBER 16

struct Record {
	char name[MAXNAME + 1];
	char number[MAXNUMBER + 1];
};

class CPhoneList {

	friend class CPhoneIterName;
	friend std::ostream& operator << (std::ostream& os, Record& r);

public:
	CPhoneList();

	int append(const Record& newrec);
	void displayname();

private:
	Record m_rArray[MAXLENGTH];
	int m_iFirstEmpty;
};
std::ostream& operator << (std::ostream& os, Record& r);
