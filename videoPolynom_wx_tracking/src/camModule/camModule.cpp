/* 
 * File:   cammodule.cpp
 * Author: alessio
 * 
 * Created on September 14, 2009, 11:50 AM
 */

//#include <opencv/cxtypes.h>


#include "camModule.h"
#include <iostream>
//-----------------------------------------------------------------------------
// Construtor do wrapper.
camModule::camModule() {

}
//-----------------------------------------------------------------------------
// destrutod do dispositivo.
camModule::~camModule() {
    cvReleaseCapture( &capture );
    cvDestroyWindow("in");
}
//-----------------------------------------------------------------------------
// Inicializa o dispositivo
int camModule::initializeDevice(int type, const char* dev) {
  frame = 0;
  capture = 0;

  if(type==1) 
  {
    capture = cvCaptureFromCAM(0);
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 640 );
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 480 );
  }

  if(type==2) capture = cvCaptureFromAVI(dev);
  //capture = cvCaptureFromAVI( "..\\videos\\PetsD1TeC1.avi" );
  if( !capture )
  {
	  fprintf(stderr,"Could not initialize capturing...\n");
	  return 0;
  }
  
  frame = cvQueryFrame( capture );

  //cvNamedWindow( "in", 0 );
  return 1;
}
//-----------------------------------------------------------------------------
// Formato BGR.
char *camModule::getBGRFrame() {
    if(!cvGrabFrame(capture))
      exit(1);

    frame = cvRetrieveFrame(capture);

    //cvShowImage("in", frame );

    if( cvWaitKey(10) >= 0 )
      exit(1);

    char *data = (char*) calloc(frame->width*frame->height*3, sizeof(char*));
    memcpy(data, frame->imageData, frame->width*frame->height*3 * sizeof(char));

    return data;
}
//-----------------------------------------------------------------------------
// Formato RGB.
char *camModule::getRGBFrame() {
    
    if(!cvGrabFrame(capture))
      exit(1);

    frame = cvRetrieveFrame(capture);
    //cvShowImage("in", frame );

    //if( cvWaitKey(10) >= 0 )
    //  exit(1);

    char *data = (char*) calloc(frame->width*frame->height*3, sizeof(char*));
    memcpy(data, frame->imageData, frame->width*frame->height*3 * sizeof(char));

     for(int i = 0; i < frame->width * frame->height*3; i+=3){
        char tmp = data[i];
        data[i] = data[i+2];
        data[i+2] = tmp;
   }
    

    return data;
}
//-----------------------------------------------------------------------------

void camModule::setDevice(char *device) {
    this->device = device;
}

//-----------------------------------------------------------------------------
//void camModule::setSizeWidth(int width) {
//    frame->width = width;
//}
//-----------------------------------------------------------------------------

//void camModule::setSizeHeight(int height) {
//    frame->height = height;
//}
//-----------------------------------------------------------------------------

int camModule::getSizeWidth() {
    return frame->width;
}
//-----------------------------------------------------------------------------

int camModule::getSizeHeight() {
    return frame->height;
}
//-----------------------------------------------------------------------------
void camModule::setScaleR(float valueR)
{
    this->scaleR = valueR;
}
//-----------------------------------------------------------------------------
void camModule::setScaleG(float valueG)
{
    this->scaleG = valueG;
}
//-----------------------------------------------------------------------------
void camModule::setScaleB(float valueB)
{
    this->scaleB = valueB;
}
//-----------------------------------------------------------------------------
float camModule::getScaleR() {
    return this->scaleR;
}
//-----------------------------------------------------------------------------
float camModule::getScaleG() {
    return this->scaleG;
}
//-----------------------------------------------------------------------------
float camModule::getScaleB() {
    return this->scaleB;
}
//-----------------------------------------------------------------------------
