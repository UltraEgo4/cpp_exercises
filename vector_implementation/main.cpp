#include "cmystring.h"
#include "cmystringexception.h"
#include <iostream>
#include "cmyvector.h"
#include "cmyvectorexception.h"

extern template class CMyVector<char>;
extern template class CMyVector<int>;
extern template class CMyVector<double>;
extern template class CMyVector<CMyString>;
#define _MAXTEST  5u
struct test_int {
	int ori[_MAXTEST] = { -12, 345, 0, 5, -16000 };
	int growing[_MAXTEST] = { -16000, -12, 0, 5, 345 };
	int decreasing[_MAXTEST] = { 345, 5, 0, -12, -16000 };
} Test;
typedef CMyVector<char> CharVector;
typedef CMyVector<int> IntVector;
typedef CMyVector<double> DoubleVector;
typedef CMyVector<CMyString> CMyStringVector;
int main(){
	int i;
	CMyStringVector t2(2);//2,2
	t2[0] = Test.ori[0];
	t2[1] = Test.ori[1];
	t2.resize(_MAXTEST);//5,5
	
	IntVector t1;
	t1.resize(_MAXTEST);
	for (i = 0; i < _MAXTEST; i++)
	{
		t1[i] = Test.ori[i];
	}


	CMyStringVector t;
	t.resize(_MAXTEST);


	for (i = 0; i < _MAXTEST; i++)
	{
		t[i] = Test.ori[i];
	}
	t.sort(false);
	t.list();

	



}