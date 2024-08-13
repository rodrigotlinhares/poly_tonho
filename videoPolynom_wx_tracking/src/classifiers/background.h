#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct frame {
	unsigned char* data;
	frame* next;
	frame* prior;
} tFrame;

//--------------------------------------------------------------------------------
class background {
  
private:
    unsigned int m_W, m_H;
    tFrame* m_fFrame; 
    tFrame* m_lFrame;
    unsigned int numberOfFrames;
    
public:
    //contructor and destructor
    background(unsigned int W, unsigned int H);
    ~background();
    
    void addImage(unsigned char* data);    
    unsigned char* getBackgroundModel();
};
//--------------------------------------------------------------------------------
#endif
