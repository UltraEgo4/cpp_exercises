#include <iostream>

#include "cmydate.h"
#include "cmydateexception.h"

int main() {
	/*try
	{
		CMyDate date1(2000, 12, 31);

		date1.Display();
		std::cout << date1.DayOfTheYear() << std::endl;
		CMyDate date2(1999, 12, 31);
		date2.Display();
		std::cout << date2.DayOfTheYear() << std::endl;

	}
	catch (CMyDateException& e)
	{
		std::cerr << e.what();
	}*/
	/*try
	{
		CMyDate date(2004, 2, 29);
		date.Display();
		date.SetYear(2000);
		date.Display();

		date.SetYear(1999);
		date.Display();
	}
	catch (CMyDateException& e)
	{
	std::cerr << e.what();
	}*/
	//int i;
	//static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//static char buf[32];
	//for (i = 1; i < 13; i++)
	//{

	//	sprintf_s(buf, sizeof(buf), "%d.", i); //hol a hiba?
	//	CMyDate d7(2021, i, days[i]);
	//	sprintf_s(buf, sizeof(buf), " %d. - %d", days[i], d7.GetDay());
	//	d7.GetYear(); //2021
	//	d7.GetMonth(); //i
	//	days[i], d7.GetDay(); //days[i]
	//}
	/*CMyDate d10(2021, 1, 31);
	d10.SetMonth(4);
	d10.Display();*/

	CMyDate d11(2000, 3, 29);
	d11.SetYear(2001);
	d11.Display();

	return 0;
}