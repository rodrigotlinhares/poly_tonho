/* 
 * File:   dilatacao.h
 * Author: thiago
 *
 * Created on September 8, 2010, 9:38 AM
 */

#ifndef DILATACAO_H
#define	DILATACAO_H


namespace dip
{
  
class dilate {
private:
    //image size
    int m_width, m_height;

    //kernel masks and size
    int **m_kernel;
    int m_kW, m_kH;
    int m_hsX, m_hsY;

    //buffer image
    unsigned char *m_buff; 
    
public:
    dilate(int width, int height);
    ~dilate();

    void setKernel(int *kernel, int kW, int kH);
    void setHotSpot(int x, int y);

    unsigned char *execute(unsigned char *imBin);

};

};

#endif	/* DILATACAO_H */

