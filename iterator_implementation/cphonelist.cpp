#include <iostream>
#include "cphonelist.h"
#include "cphoneitername.h"


CPhoneList::CPhoneList()
{
	m_iFirstEmpty = 0;
}

int CPhoneList::append(const Record& newrec)
{
	if (m_iFirstEmpty != MAXLENGTH)
	{
		m_rArray[m_iFirstEmpty] = newrec;
		m_iFirstEmpty++;
		return 0;
	}

	return -1;
}

void CPhoneList::displayname()
{
	CPhoneIterName it(*this);
	for (Record* p = it.begin(); p != nullptr; p = ++it)
	{
		std::cout << *p;
	}
}

std::ostream& operator<<(std::ostream& os, Record& r)
{
	os << std::endl << r.name << ";" << r.number;
	return os;
}
