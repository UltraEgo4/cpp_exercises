#include "cphoneitername.h"
#include <iostream>

CPhoneIterName::CPhoneIterName(CPhoneList& m) : m_cpList(&m), m_iCurrentIndex(0)
{
	sorted = new unsigned[m_cpList->m_iFirstEmpty];
	mysort(m_cpList->m_rArray, m_cpList->m_iFirstEmpty);
}

CPhoneIterName::~CPhoneIterName()
{
	delete[] sorted;
}

Record* CPhoneIterName::begin()
{
	if (m_cpList->m_iFirstEmpty == 0)
	{
		return nullptr;
	}
	//return &m_cpList->m_rArray[0];
	return &m_cpList->m_rArray[sorted[0]];
}

Record* CPhoneIterName::prev()
{
	if (m_cpList->m_iFirstEmpty == 0 || m_iCurrentIndex == 0)
	{
		return nullptr;
	}
	m_iCurrentIndex--;
	//return &m_cpList->m_rArray[m_iCurrentIndex];
	return &m_cpList->m_rArray[sorted[m_iCurrentIndex]];

}

Record* CPhoneIterName::next()
{
	if (m_cpList->m_iFirstEmpty == 0 || m_iCurrentIndex + 1 >= m_cpList->m_iFirstEmpty) //+1 removed from m_icuurentindex +1 removed m_iCurrentIndex+1 == m_cpList->m_iFirstEmpty
	{
		return nullptr;
	}
	m_iCurrentIndex++;
	//return &m_cpList->m_rArray[m_iCurrentIndex];
	return &m_cpList->m_rArray[sorted[m_iCurrentIndex]];
}

Record* CPhoneIterName::end()
{
	if (m_cpList->m_iFirstEmpty == 0)
	{
		return nullptr;
	}
	m_iCurrentIndex = m_cpList->m_iFirstEmpty - 1;
	//return &m_cpList->m_rArray[m_cpList->m_iFirstEmpty-1];
	return &m_cpList->m_rArray[sorted[m_cpList->m_iFirstEmpty-1]];
}

int CPhoneIterName::size()
{
	return m_cpList->m_iFirstEmpty;
}

Record* CPhoneIterName::search(const char* key)
{
	if (key == nullptr)
	{
		return nullptr;
	}
	m_iCurrentIndex = 0;
	for (Record* p = begin(); p != nullptr;p = next()) {
		if (strcmp(p->name, key) == 0) {
			return p;
		}
	}

	return nullptr;
}

Record* CPhoneIterName::operator++()
{
	if (m_cpList->m_iFirstEmpty == 0 || m_iCurrentIndex + 1 >= m_cpList->m_iFirstEmpty)//== was in the second statement
	{
		return nullptr;
	}
	m_iCurrentIndex++;
	//return &m_cpList->m_rArray[m_iCurrentIndex];
	return &m_cpList->m_rArray[sorted[m_iCurrentIndex]];

}

Record* CPhoneIterName::operator++(int n)
{
	Record* temp;
	if (m_iCurrentIndex >= m_cpList->m_iFirstEmpty)
	{
		temp = &m_cpList->m_rArray[sorted[m_cpList->m_iFirstEmpty-1]];
	}
	else
	{
		 temp = &m_cpList->m_rArray[sorted[m_iCurrentIndex]];
	}
	
	if (m_cpList->m_iFirstEmpty == 0 ) //|| m_iCurrentIndex + 1 == MAXLENGTH
	{
		return nullptr;
	}
	//Record* temp = &m_cpList->m_rArray[m_iCurrentIndex];
	// 
	//Record* temp = &m_cpList->m_rArray[sorted[m_iCurrentIndex]];
	/*if (m_iCurrentIndex + 1 != m_cpList->m_iFirstEmpty)
	{
		m_iCurrentIndex++;
	}*/
	if (m_iCurrentIndex +1 != m_cpList->m_iFirstEmpty)
	{
		m_iCurrentIndex++;
	}
	
	
	return temp;
}

void CPhoneIterName::mysort(Record* inputArr, unsigned size) //Bubble sort : sorted array , size of the sorted array
{
	if (m_cpList->m_iFirstEmpty == 0)
	{
		return;
	}
	for (size_t i = 0; i < size; i++) //sorted array filled up with indexes 0,1,2,3,4 etc.
	{
		sorted[i] = i;
	}
	unsigned i, j;
	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			std::string name1 = inputArr[sorted[j]].name;
			std::string name2 = inputArr[sorted[j + 1]].name;

			for (size_t i = 0; i < name1.length(); i++) {
				name1[i] = tolower(name1[i]);
			}
			for (size_t i = 0; i < name2.length(); i++) {
				name2[i] = tolower(name2[i]);
			}
			if (name1< name2)
			{
				std::swap(sorted[j], sorted[j + 1]);
			}

			/*if (inputArr[sorted[j]].name < inputArr[sorted[j+1]].name)
			{
				std::swap(sorted[j], sorted[j + 1]);
			}*/
		}
	}
}


