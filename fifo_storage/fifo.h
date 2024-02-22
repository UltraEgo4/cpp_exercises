#pragma once
#include <cstddef>

#define NOK -1
#define OK 0

typedef int fifoh;      // fifo address (fifoh fh)

int buildfifo(size_t n); //creates and array that can hold n number of fifos, but i dosent allocate space for the fifos,n is the number of fifos it can hold

int killfifo();//kills the array that holds the fifos


int getcnt();//returns the current number of fifos loaded


fifoh getfifo(size_t n);//creates a fifo that can hold n number of elements, and return the address/manager (array index,identifier of the fifo)

int freefifo(fifoh fh);//frees a fifo


int getsizefifo(fifoh fh);//returns the size of a fifo

int getcntfifo(fifoh fh);//returns how many elements are in a fifo


int pushfifo(char c, fifoh fh);//pushes one element into the fifo

int popfifo(fifoh fh);//pops out one element from the fifo
