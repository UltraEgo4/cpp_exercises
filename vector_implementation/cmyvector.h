#pragma once
template <class T> class CMyVector
{
public:
	CMyVector(void);
	CMyVector(unsigned n);
	~CMyVector(void);

	T& operator[](unsigned n);
	CMyVector<T>& operator=(const CMyVector<T>& r);

	void clear();
	void push_back(const T& value);
	void list();
	void sort(bool f);
	void resize(unsigned n);
	void shrink_to_fit();

	unsigned size(void);
	unsigned capacity(void);

	//own defined, for sort
	T* begin() { return m_pData; }
	T* end() { return m_pData + m_nSize; }


private:
	T* m_pData;	//def nullptr
	unsigned m_nSize;	//def 0, number of elements in array
	unsigned m_nCapacity;	//def 0, number of elements in can HOLD

};

