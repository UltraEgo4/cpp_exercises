#include "cmystring.h"
#include "cmystringexception.h"
#include <iostream>

int main() {

	CMyString obj1("APPLE");
	CMyString obj2("BANANA");
	obj1.swap(obj2);


	CMyString str;
	CMyString moved = std::move(str);

	
	CMyString w("45");
	CMyString x("23");
	CMyString y("01");
	y += x += w += "67";

	CMyString str3("mystringBANANA");
	str3 += "mystringBANANA";
	str3 += str3;

	try
	{
		CMyString str("mystring");
		CMyString str1 = str.substring(9);
	}
	catch (CMyStringException& e)
	{
		std::cerr << e.what();
	}
	CMyString str8("mystring");
	CMyString subbed2 = str8.substring(2, 2);
	CMyString subbed = str8.substring(0);
	
	std::cout << str8;
	return 0;
}