#include <fstream>
#include <iostream>
#include "sortfile.h"



int sortfile(char* infn, char* outfn, unsigned char* buf, unsigned short bufsize) //input buffer, output buffer, used buffers address, used buffers size
{
	//CHECK INVALID PARAMETERS

	if ( infn == nullptr || outfn == nullptr || buf == nullptr || infn[0] == '\0' || outfn[0] == '\0' || bufsize <= 0 || bufsize > 8192)
	{
		return NOK;
	}
	

	int outputLength = 0;

	while (outfn[outputLength] != '\0' && outputLength < MYMAXFN - 1) {
		outputLength++;
	}

	int inputLength = 0;
	while (infn[inputLength] != '\0' && inputLength < MYMAXFN - 1) {
		inputLength++;
	}

	if (inputLength > MYMAXFN || outputLength + 4 > MYMAXFN )
	{
		return NOK;
	}

	//ADD EXTENSION TO FILE ; 


	/*char fileExtension[] = ".srt";
	int fileExtensionIndex = 0;

	while (fileExtension[fileExtensionIndex] != '\0') {
		outfn[outputLength] = fileExtension[fileExtensionIndex];
		outputLength++;
		fileExtensionIndex++;
	}

	outfn[outputLength] = '\0';*/

	//READ FROM FILE

	std::ifstream ifs(infn, std::ios_base::binary);
	int counter = 0;	//counter for cout
	

	if (ifs.is_open())
	{
		for (int i = 0; i < MYBUFSIZE; i++)
		{
			buf[i] = 0;
		}

		unsigned short n;	//read character into this
		int i = 0;



		std::cout << "*READ\n";

		while (ifs.read((char*)&n, sizeof(n)))	//read character into n with a size of 2 bytes
		{
			int bytePosition = n / 8;	//calculate the bytes positon where the bit is
			int bitPosition = n % 8;	//calculate the bits postion in the byte 1 byte = 8 bit --> 0-7 bit
			buf[bytePosition] |= (1 << bitPosition);	//flip the bits value to 1 on the calculated position, bitwise operator
			
			std::cout << counter << ".\t" << n << "\n";		
			counter++;
			
		}
		ifs.close();
	}
	else
	{
		return NOK;
	}
	
	//WRITE TO FILE

	std::ofstream ofs;

	ofs.open(outfn, std::ios_base::binary);
	if (ofs.bad()) {
		return NOK;
	}

	

	std::cout << "\n*SORT, WRITE\n";
	counter = 0;

	for (int i = 0; i < MYBUFSIZE; i++)		//iterate through each byte
	{
		for (int j = 0; j < 8; j++)			//iterate through each bit
		{
			if (buf[i] & (1<<j))	//bitwise operation & , bitmask (1<<j) ; check if any of the bytes bits set to 1
			{
				unsigned short n = i * 8 + j;	//calculate the global bit index in the buffer so the actual value we need
				std::cout << counter<<".\t"<< n << "\n";
				counter++;
				ofs.write((char*)&n, sizeof(n));
			}
		}
	}

	
	ofs.close();
	



	return OK;
}


