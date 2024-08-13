#ifndef _TRACKING_H
#define _TRACKING_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "labeling.h"
#include "trajectories.h"

enum correspondecyMethod { MINIMAL_DISTANCE, VECTOR_FIELD};

//this class is responsible for object tracking
namespace dip
{

class objectTr
{
public:
	objectTr() { 
		m_labelingIndex = m_trIndex = m_area = 0;
		m_center.x = m_center.y = 0; 
		nextTr=priorTr=nextOb=priorOb=NULL;
	};

	//static int numberOfObjects;

	//object properties
	unsigned int m_labelingIndex;
	unsigned int m_area;
	point m_center; 
	
	//real index for it
	unsigned int m_trIndex;
	
	//next and prior objects
	dip::objectTr* nextOb;
	dip::objectTr* priorOb;

	dip::objectTr* nextTr;
	dip::objectTr* priorTr;
};

class frameTr
{
public:
	frameTr() {
		//numberOfObjects = 0;
		//numberOfFrames++;
		
		numberOfObjects = 0;
		m_objects = NULL;
		nextFr = priorFr = NULL;
	}
  
	//static int numberOfFrames;
	
	int numberOfObjects;
	dip::objectTr* m_objects;
	
	dip::frameTr* nextFr;
	dip::frameTr* priorFr;
};
  
class tracking
{
private:
	//image dimensions
	int W,H;

	//labeling instance module
	dip::labeling *mLab;
	
	//list of objects in tracking
	dip::frameTr* m_listOfFrames;
	dip::frameTr* m_pLastFrame;
	
	//correspondency method member variable
	correspondecyMethod m_correspondencyMethod;

	
	//apply labeling under the image to identify the component regions
	void doLabeling(unsigned char* frame);
	
	//find where the object was located in previous frames  -- return the index of this object, and 0 if it wasn't located
	dip::objectTr* findCorrespondency(dip::objectTr* queryObject);

	//**** CORRESPONDENCY METHODS
	//correspondency by minimal distance method
	dip::objectTr* fc_minimalDistance(dip::objectTr* queryObject);

	//track objects
	void doTrackObjects2();
	
  
public:
	//default constructors and destructors
	tracking(int W, int H);
	~tracking();
	
	//add a new binary image to track objects
	void addBinFrame(unsigned char* frame);
	
	//get trajectories all trajectories in the n_lastFrames, recovering the last timeStep (-1 for all)
	dip::trajectories* getTrajectories(int n_lastFrames, int timeStep);
};
};
#endif
