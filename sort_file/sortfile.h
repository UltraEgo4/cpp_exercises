#pragma once
#include <fstream>

#define MYBUFSIZE 8192
#define MYMAXVALUE 65535
#define MYMAXFN 128
#define OK 0
#define NOK (-1)


int sortfile(char* infn, char* outfn,unsigned char* buf, unsigned short bufsize);  //input buffer, output buffer, used buffers address, used buffers size
