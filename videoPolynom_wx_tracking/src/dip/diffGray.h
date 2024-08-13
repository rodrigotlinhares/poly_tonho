#ifndef _DIFFGRAY_H
#define	_DIFFGRAY_H

#include <iostream>
//---------------------------------------------------------------------------------
namespace dip
{
  
class diffGray
{
private:
	int W, H;
        float dco(float &v, float &w, float lambda);

public:
	diffGray(int width, int height);
        unsigned char *execute(unsigned char *img, unsigned int iteractions, float lambda);
        unsigned char *execute2(unsigned char *img, unsigned int iteractions, float lambda);
};
//---------------------------------------------------------------------------------
};
#endif