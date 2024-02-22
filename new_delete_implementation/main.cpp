#include "cname.h"
#include <iostream>
#include "cnameexception.h"
int main(){

	CName* names[MAXNAMES];
	names[2] = new CName("monkey");

	const char* str = "monkey";
	for (size_t i = 0; i < 6; i++)
	{
		char asd = str[i];
		char based = names[2]->get(0, i);
		int gdfsg = 0;
	}
	names[0]->display();



}