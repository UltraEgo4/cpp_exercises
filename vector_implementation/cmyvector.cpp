#include <iostream>
#include <algorithm>

#include "cmyvector.h"
#include "cmyvectorexception.h"
#include "cmystring.h"

template class CMyVector<char>;
template class CMyVector<int>;
template class CMyVector<double>;
template class CMyVector<CMyString>;

template <class T>
CMyVector<T>::CMyVector(void) {

	m_pData = nullptr;
	m_nSize = 0;
	m_nCapacity = 0;
}

template <class T>
CMyVector<T>::CMyVector(unsigned n) {

	m_pData = new T[n];
	m_nSize = n;
	m_nCapacity = n;
}

template <class T>
CMyVector<T>::~CMyVector(void) {
	delete[] m_pData;
}

template<class T>
T& CMyVector<T>::operator[](unsigned n) {

	if (m_nSize == 0) {
		throw CMyVectorException(CMyVectorException::ErrEmpty);
	}
	if (n < 0 || n >= m_nSize) {
		throw CMyVectorException(CMyVectorException::ErrIndex);
	}
	return m_pData[n];
}

template<class T>
CMyVector<T>& CMyVector <T>::operator=(const CMyVector<T>& r) {
	if (m_nCapacity >= r.m_nSize) //ENOUGH SPACE 
	{
		for (size_t i = 0; i < r.m_nSize; i++)
		{
			m_pData[i] = r.m_pData[i];
		}
		m_nSize = r.m_nSize;
		return *this;
	}
	else //NOT ENOUGH SPACE
	{
		delete[] m_pData;

		m_nSize = r.m_nSize;
		m_nCapacity = r.m_nSize;
		m_pData = new T[m_nCapacity];

		for (size_t i = 0; i < r.m_nSize; i++)
		{
			m_pData[i] = r.m_pData[i];
		}
		return *this;

	}
	return *this;
}

template<class T>
void CMyVector<T>::clear() {

	delete[] m_pData;
	m_nSize = 0;

	m_pData = new T[m_nCapacity];

	for (size_t i = 0; i < m_nCapacity; i++)
	{
		m_pData[i] = {};
	}
}


template <class T>
void CMyVector<T>::push_back(const T& value) {
	if (m_nSize != m_nCapacity)
	{
		m_pData[m_nSize] = value; //not m_nSize+1, just m_nSize if array has 4 elements 0,1,2,3 you put the next element to size(4) not size + 1(5)
		m_nSize++;

	}
	else
	{
		if (1.5* m_nCapacity < 4)
		{
			m_nCapacity = 4;
		}
		else
		{
			m_nCapacity = 1.5 * m_nCapacity;
		}
		//save elements to temp array
		T* tempArr = new T[m_nSize];//array with the same length as items in m_pData
		for (size_t i = 0; i < m_nSize; i++)
		{
			tempArr[i] = m_pData[i];
		}
		delete[] m_pData;
		
		m_pData = new T[m_nCapacity];
		for (size_t i = 0; i < m_nSize; i++)
		{
			m_pData[i] = tempArr[i];
		}
		m_pData[m_nSize] = value;
		m_nSize++;

		delete[] tempArr;

	}
	
}

template <class T>
void CMyVector<T>::list() {
	if (m_pData != nullptr)
	{
		for (size_t i = 0; i < m_nSize; i++)
		{
			std::cout << i << ".:" << m_pData[i]; // . : , dont know if new line needed or not
		}

	}
}

template <class T>
void CMyVector<T>::sort(bool f) {
	if (m_pData != nullptr)
	{
		if (f) {
			T* ptr = begin();
			T* ptr2 = end();
			std::sort(begin(), end());
		}
		else {

			std::sort(begin(), end(), std::greater<T>());
		}
	}
}

template <class T>
void CMyVector<T>::resize(unsigned n) {
	if (n == m_nCapacity || n== m_nSize)
	{
		m_nSize = n;
		return;
	}
	if (n > m_nCapacity)
	{
		//create temp array with default values, length is n
		if (m_nSize==0)
		{
			if (m_pData == nullptr)
			{
				m_nSize = n;
				m_nCapacity = n;
				m_pData = new T[m_nCapacity];
				return;
			}
			else
			{
				delete[] m_pData;
				m_nSize = n;
				m_nCapacity = n;
				m_pData = new T[m_nCapacity];
				return;
			}
			
		}
		T* tempArr = new T[n];
		for (size_t i = 0; i < n; i++)
		{
			tempArr[i] = {};
		}
		//copy value to temp array
		for (size_t i = 0; i < m_nSize; i++)
		{
			tempArr[i] = m_pData[i];
		}

		delete[] m_pData;

		m_nSize = n;
		m_nCapacity = n;

		//create new m_pData, length is n
		m_pData = new T[m_nCapacity];
		//copy elments from temp to m_pData, length is the same
		for (size_t i = 0; i < m_nSize; i++)
		{
			m_pData[i] = tempArr[i];
		}

		delete[] tempArr;
		return;
	}
	if (n< m_nSize)
	{
		//start from size-1, if array has 5 elements 0,1,2,3,4 | iterate until n | i--
		for (size_t i = m_nSize-1; i >= n; i--)
		{
			m_pData[i] = {};
		}
		m_nSize = n;
	}
}


template <class T>
void CMyVector<T>::shrink_to_fit() {

	T* tempArr = new T[m_nSize];

	for (size_t i = 0; i < m_nSize; i++)
	{
		tempArr[i] = m_pData[i];
	}

	delete[] m_pData;

	m_nCapacity = m_nSize;

	m_pData = new T[m_nCapacity];

	for (size_t i = 0; i < m_nSize; i++)
	{
		m_pData[i] = tempArr[i];
	}

	delete[] tempArr;
}

template <class T>
unsigned CMyVector<T>::size(void) {
	return m_nSize;
}

template <class T>
unsigned CMyVector<T>::capacity(void) {
	return m_nCapacity;
}