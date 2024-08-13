#include "diffGray.h"

#include <math.h>
#include <malloc.h>
#include <string.h>
//---------------------------------------------------------------------------------
dip::diffGray::diffGray(int width, int height)
{
    this->W = width;
    this->H = height;
}
//---------------------------------------------------------------------------------
float dip::diffGray::dco(float &v, float &w, float lambda)
{
        double result, dE;
        dE = pow((double)(v-w)*(v-w), 0.5);
        result = exp(-pow(fabs(dE)/lambda, 5.0) / 5.0);
        return (result);
}
//---------------------------------------------------------------------------------
unsigned char *dip::diffGray::execute2(unsigned char *img, unsigned int iteractions, float lambda)
{
    unsigned char *res  = (unsigned char*) calloc(W*H*3, sizeof(unsigned char));
    memcpy(res, img, W*H*3*sizeof(unsigned char));

    float qC, qN, qNE, qE, qSE, qS, qSW, qW, qNW;   /* weights */

    for(unsigned int it=0; it<iteractions; it++)
    {
	for(int i=1; i<(H-1); i++)
	{
	    for(int j=3; j<(W-1)*3; j+=3)
	    {
		qC = img[(i)*(W*3)+j*3];
		qN = img[(i-1)*(W*3)+j*3];
		qNE = img[(i-1)*(W*3)+j*3+3];
		qE = img[(i)*(W*3)+j*3+3];
		qSE = img[(i+1)*(W*3)+j*3+3];
		qS = img[(i+1)*(W*3)+j*3];
		qSW = img[(i+1)*(W*3)+j*3-3];
		qW = img[(i)*(W*3)+j*3-3];
		qNW = img[(i-1)*(W*3)+j*3-3];
		qC  = (3*qC + qN + qNE + qE + qSE + qS + qSW + qW + qNW) / 11;
		
		res[(i)*(W*3)+j*3]=qC;
	    }
	}
	memcpy(img, res, W*H*3*sizeof(unsigned char));
    }
    //free(res);
    return img;
}
//---------------------------------------------------------------------------------
unsigned char *dip::diffGray::execute(unsigned char *imgF, unsigned int iteractions, float lambda)
{
    float *res  = (float*) calloc(W*H*3, sizeof(float));

    float *img = (float*) calloc(W*H*3, sizeof(float));
    for(int i=0; i<W*H*3; i++)
    {
	img[i]=imgF[i];
	res[i]=imgF[i];
    }

    //diffusive averaging
    float qC, qN, qNE, qE, qSE, qS, qSW, qW, qNW;   /* weights */
    float v, w;
    float ht = 0.5; //time step size, >0, e.g. 0.5
    
    for(unsigned int it=0; it<iteractions; it++)
    {
	for(int i=1; i<(H-1); i++)
	{
	    for(int j=3; j<(W-1)*3; j+=3)
	    {
		v = img[(i)*(W*3)+j*3];

		w = img[(i-1)*(W*3)+j*3];
		qN = (1.0 - exp(-8.0 * ht * dco(v, w, lambda))) / 8.0;

		w = img[(i-1)*(W*3)+j*3+3];
		qNE = (1.0 - exp(-8.0 * ht * dco(v, w, lambda))) / 8.0;

		w = img[(i)*(W*3)+j*3+3];
		qE = (1.0 - exp(-8.0 * ht * dco(v, w, lambda))) / 8.0;
		
		w = img[(i+1)*(W*3)+j*3+3];
		qSE = (1.0 - exp(-8.0 * ht * dco(v, w, lambda))) / 8.0;

		w = img[(i+1)*(W*3)+j*3];
		qS = (1.0 - exp(-8.0 * ht * dco(v, w, lambda))) / 8.0;
		
		w = img[(i+1)*(W*3)+j*3-3];
		qSW = (1.0 - exp(-8.0 * ht * dco(v, w, lambda))) / 8.0;
		
		w = img[(i)*(W*3)+j*3-3];
		qW = (1.0 - exp(-8.0 * ht * dco(v, w, lambda))) / 8.0;

		w = img[(i-1)*(W*3)+j*3-3];
		qNW = (1.0 - exp(-8.0 * ht * dco(v, w, lambda))) / 8.0;
		
		qC  = 1.0 - qN - qNE - qE - qSE - qS - qSW - qW - qNW;
		
		float g= 	 qNW*img[(i-1)*(W*3)+j*3-3] + qN*img[(i-1)*(W*3)+j*3] + qNE*img[(i-1)*(W*3)+j*3+3] +
		                 qW *img[(i)*(W*3)+j*3-3]   + qC*img[(i)*(W*3)+j*3]   + qE *img[(i)*(W*3)+j*3+3]   +
		                 qSW*img[(i+1)*(W*3)+j*3-3] + qS*img[(i+1)*(W*3)+j*3] + qSE*img[(i+1)*(W*3)+j*3+3];
				 
		res[(i)*(W*3)+j*3]   = g;
		res[(i)*(W*3)+j*3+1] = g;
		res[(i)*(W*3)+j*3+2] = g;
	    }
	}
	memcpy(img, res, W*H*3 * sizeof(float));	
    }
    
    //copying final result
    for(int i=0; i< W*H*3; i++)
    {
	imgF[i]=img[i];
    }
    free(img);
    free(res);
    
    return imgF;
}
//---------------------------------------------------------------------------------

