#include "sortfile.h"
int main(int argc, char* argv[]) {
	
	if (argc != 2)
	{
		return NOK;
	}

	char infn[] = "C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin10000.dat";
	
	char outfn[MYMAXFN] = { "C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\output.srt"};
	
	unsigned char buf[MYBUFSIZE] = { 0 };
	
	const char* infFileUnit[7] = {
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin5.dat",
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin10.dat",
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin50.dat",
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin100.dat",
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin10000.dat",
		NULL,
		NULL

	};
	const char* outfFileUnit[7] = {
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin5.dat.srt",
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin10.dat.srt",
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin50.dat.srt",
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin100.dat.srt",
		"C:\\Users\\X\\Documents\\cplusplus\\feladat3\\feladat3\\testin10000.dat.srt",
		NULL,
		NULL

	};
	int test[8] = {0};
	for (int i = 0; infFileUnit[i]; i++)
	{
		test[i] = sortfile((char*)infFileUnit[i], (char*)outfFileUnit[i], buf, MYBUFSIZE);
	}
	
	


	//int result = sortfile(infn, outfn, buf, sizeof(buf));


	return 0;
}