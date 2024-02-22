#include "fifo.h"
#include <cstdlib>


struct Fifo {
    int size;
    int head;
    int tail;
    int count;

    char* elements;
};

struct Frame {         //frame (array) that holds fifos
    int capacity;   //number of fifos it can hold
    int count;      // number of fifos in the array

    Fifo* fifos;
};

static Frame frame;

int buildfifo(size_t n) {

    if (frame.fifos != nullptr || n<=0) {       //check if already created
        return NOK;
    }

    frame.fifos = (Fifo*)malloc(n * sizeof(Fifo));       //allocates memory to the frame


    if (frame.fifos == nullptr) {      //check if memory allocation failed, it returns a nullptr
        return NOK;
    }

    frame.capacity = n;
    frame.count = 0;

    for (int i = 0; i < n; ++i) {               //initalizing fifos with default values
        frame.fifos[i].elements = nullptr;
        frame.fifos[i].size = 0;
        frame.fifos[i].head = 0;
        frame.fifos[i].tail = 0;
        frame.fifos[i].count = 0;
    }
    return OK;
}

fifoh getfifo(size_t n) {


    if (frame.count < frame.capacity) {
        
        for (int i = 0; i < frame.capacity; i++)        //serach for empty space in frame
        {
            if (frame.fifos[i].elements == nullptr)     //if any fifos elements array initialized to nullptr then thats a free spot
            {
                frame.fifos[i].elements = (char*)malloc(n*sizeof(char));

                frame.fifos[i].size = n;

                frame.count++;
                return i;
            }
        }  
    }
    else {

        return NOK;
    }

    return NOK;
}

int pushfifo(char c, fifoh fh) {
    if ( frame.fifos == nullptr || frame.fifos[fh].elements == nullptr ) {
        return NOK;
    }

    if (frame.fifos[fh].count < frame.fifos[fh].size) {         //if theres empty space in the fifos element array

        //char element = (c == 0) ? -1 : c;      //TEGNAP ADTAM HOOZZA!!!!!!! //handles when you push 0 into the fifo it interprets it as a c style string terminator \0, i represent 0 pushed into the stack with -1

        frame.fifos[fh].elements[frame.fifos[fh].tail] = c;     //set tail to c
        frame.fifos[fh].tail = (frame.fifos[fh].tail + 1) % frame.fifos[fh].size;   //set
        
        frame.fifos[fh].count++;

        return OK;

    }
    else {
        return NOK;
    }
}

int popfifo(fifoh fh) {
    if ( frame.fifos == nullptr || frame.fifos[fh].elements == nullptr) {
        return NOK;
    }

    if (frame.fifos[fh].count > 0) {
        /*if (frame.fifos[fh].head == frame.fifos[fh].tail)
        {
            frame.fifos[fh].head = 0;
            frame.fifos[fh].tail = 0;
        }*/
        
        int output = 0;
        output = frame.fifos[fh].elements[frame.fifos[fh].head] & 0xff;  
        //frame.fifos[fh].elements[frame.fifos[fh].head] = 'F';
        frame.fifos[fh].head = (frame.fifos[fh].head + 1) % frame.fifos[fh].size;   //simply skip it

        frame.fifos[fh].count--;

        return output;
    }
    else {
        return NOK;
    }

}

int freefifo(fifoh fh)
{
    if (frame.fifos == nullptr || fh < 0 || fh >= frame.capacity || frame.fifos[fh].elements == nullptr)
    {
        return NOK;
    }

    free(frame.fifos[fh].elements);

    frame.fifos[fh].elements = nullptr;
    frame.fifos[fh].size = 0;
    frame.fifos[fh].head = 0;
    frame.fifos[fh].tail = 0;
    frame.fifos[fh].count = 0;

    frame.count--;

    return OK;
}

int killfifo()
{
    if (frame.fifos == nullptr) {
        return NOK;
    }

    for (int i = 0; i < frame.capacity; ++i) {
        if (frame.fifos[i].elements != nullptr) {

            free(frame.fifos[i].elements);

            frame.fifos[i].elements = nullptr;
        }
    }

    free(frame.fifos);

    frame.fifos = nullptr;
    frame.capacity = 0;
    frame.count = 0;

    return OK;

}

int getcnt() {       //returns how many fifos are existing right now
    if (frame.fifos != nullptr) {

        return frame.count;
    }

    return NOK;
}

int getsizefifo(fifoh fh) {      //return how many elements can a fifo hold
    if (frame.fifos != nullptr && fh >= 0 && fh < frame.capacity && frame.fifos[fh].elements != nullptr)
    {
        return frame.fifos[fh].size;
    }
    return NOK;
}

int getcntfifo(fifoh fh) {       //returns how many elements are currently in a fifo
    if (frame.fifos != nullptr && fh >= 0 && fh < frame.capacity && frame.fifos[fh].elements != nullptr)
    {
        return frame.fifos[fh].count;
    }
    return NOK;
    
}




