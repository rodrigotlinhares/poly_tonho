/* 
 * File:   cammodule.h
 * Author: alessio
 *
 * Created on September 14, 2009, 11:50 AM
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "cv.h"
#include "highgui.h"


#ifndef _CAMMODULE_H
#define	_CAMMODULE_H

class camModule {
private:
    IplImage* frame;
    CvCapture* capture;

    int vid;
    int row_stride;
    int input;
    char *data;
    char *device;
//    int width;
//    int height;
//    struct v4l2_capability cap;
//    struct v4l2_format fmt;

    float scaleR, scaleG, scaleB;

public:
    //constructors and destructors methods
    camModule();
    ~camModule();

    //initialize device driver
    //type 1 - camera, type 2 - file
    int initializeDevice(int type, const char* dev);

    //Videum driver in the BGR format
    char *getBGRFrame();

    //Videum driver in the RGB format
    char *getRGBFrame();

    // Modifica o dispositivo.
    void setDevice(char *device);

    // Modifica width.
    void setSizeWidth(int width);

    // Modifica height.
    void setSizeHeight(int height);

    // Retorna width.
    int getSizeWidth();

    // Retorna height.
    int getSizeHeight();

    //Set new value R video
    void setScaleR(float valueR);

    //Set new value G video
    void setScaleG(float valueG);

    //Set new value B video
    void setScaleB(float valueB);

    //return scale r
    float getScaleR();

    //return scale g
    float getScaleG();

    //return scale b
    float getScaleB();
    
};
//-----------------------------------------------------------------------------

#endif	/* _V4L2_WRAPPER_H */

