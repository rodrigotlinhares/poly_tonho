/* 
 * File:   dilatacao.cpp
 * Author: thiago
 * 
 * Created on September 8, 2010, 9:38 AM
 */

//-----------------------------------------------------------------------------
#include "dilate.h"

#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


//-----------------------------------------------------------------------------
dip::dilate::dilate(int width, int height)
{
    this->m_width = width;
    this->m_height = height;

    this->m_hsX = 0;
    this->m_hsY = 0;
    this->m_kW = this->m_kH = 0;

    //kernel
    m_kernel = NULL;

    m_buff = (unsigned char*) calloc(m_width * m_height * 3, sizeof (unsigned char));
}
//-----------------------------------------------------------------------------
dip::dilate::~dilate()
{
    if(m_kernel != NULL)
    {
        for(int i = 0; i < m_kH; i++)
            free(m_kernel[i]);
        free(m_kernel);
    }


    if(m_buff)
        free(m_buff);
}
//-----------------------------------------------------------------------------
void dip::dilate::setKernel(int *kernel, int kW, int kH)
{
    m_kW = kW;
    m_kH = kH;

    if(m_kernel != NULL)
    {
        for(int i = 0; i < m_kH; i++)
            free(m_kernel[i]);
        free(m_kernel);
    }

    m_kernel = (int**) calloc(m_kH, sizeof (int*));
    for(int i = 0; i < m_kH; i++)
        m_kernel[i] = (int*) calloc(m_kW, sizeof (int));


    /*
    for(int i = 0; i < m_kH; i++)
    {
        for(int j = 0; j < m_kW; j++)
        {
            m_kernel[i][j] = kernel[i*m_kW + j];
            printf("%d ", m_kernel[i][j]);
        }
        printf("\n");
    }
    */
}
//-----------------------------------------------------------------------------
void dip::dilate::setHotSpot(int x, int y)
{
    m_hsX = x;
    m_hsY = y;
}
//-----------------------------------------------------------------------------
unsigned char* dip::dilate::execute(unsigned char *imBin)
{
    for(int i = 0; i<m_width*m_height*3; i++)
        m_buff[i] = 0;

    memcpy(m_buff, imBin, m_width*m_height*3 * sizeof(unsigned char));

    //for(int i = 0; i<m_width*m_height*3; i+=3)
    //    imBin[i] = 255;
    //return(imBin);

    //for, image
    for(int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_width*3; j+=3)
        {
            if(imBin[i*m_width*3 + j] == 255)
            {
                //for, kernel
                for(int m = -m_hsY; m<m_kH-m_hsY; m++)
                {
                    for(int n = -m_hsX; n<m_kW-m_hsX; n++)
                    {
                        //controle para nao sair fora da imagem inicial
                        if((m+i < m_height) && (n+j < m_width*3) && (m+i >= 0) && (n+j >= 0))
                        {
                            if(m_kernel[m+m_hsY][n+m_hsX] == 0)
                            {
                                //m_buff[(i+m)*m_width*3 + (j+n*3)] = 0;
                                //m_buff[(i+m)*m_width*3 + (j+n*3) + 1] = 0;
                                //m_buff[(i+m)*m_width*3 + (j+n*3) + 2] = 0;
                            }
                            else
                            {
                                m_buff[(i+m)*m_width*3 + (j+n)] = 255;
                                m_buff[(i+m)*m_width*3 + (j+n) + 1] = 255;
                                m_buff[(i+m)*m_width*3 + (j+n) + 2] = 255;
                            }
                        }
                    }
                }
            }
        }
    }

    //unsigned char *buffRet = (unsigned char*)calloc(m_width * m_height * 3, sizeof(unsigned char));
    memcpy(imBin, m_buff, m_width*m_height*3 * sizeof(unsigned char));

    return imBin;
}
//-----------------------------------------------------------------------------

