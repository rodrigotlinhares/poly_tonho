#ifndef _FRAMEOBJECTS_H
#define _FRAMEOBJECTS_H

#include <iostream>

#include "labeling.h"
#include "dilate.h"

//this class is responsible for image improvement, filtering, labeling and object extration from a specified frame buffer
namespace dip
{

class frameObjects
{
private:
	//image dimensions
	int W,H;
	
	//labeling instance
	dip::labeling *mLab;
	
	//minimum size area of an objects
	int m_minArea;
	
	//apply filtering under the image
	unsigned char* doFiltering(unsigned char* frame);

	//apply labeling under the image to identify the component regions
	unsigned char* doLabeling(unsigned char* frame);
  
public:
	//default constructors and destructors
	frameObjects(int W, int H);
	~frameObjects();
	
	//set minimum area of an object
	void setMinArea(int minArea) { m_minArea = minArea; }

	//extract objects from grayscale frame and get pseudo colors for them
	unsigned char* execute(unsigned char* frame);
	
	//get list of representative objects on the scene for the last frame inserted
	vector<dip::object>* getObjectList(void);
};

};
#endif
