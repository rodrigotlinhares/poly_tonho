#include "frameObjects.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//---------------------------------------------------------------------------------//
dip::frameObjects::frameObjects(int W, int H)
{
	m_minArea = 200;
	this->W = W;
	this->H = H;
	
	mLab = NULL;
}
//---------------------------------------------------------------------------------//
dip::frameObjects::~frameObjects()
{
       if(mLab) delete(mLab);
}
//---------------------------------------------------------------------------------//
unsigned char* dip::frameObjects::execute(unsigned char* frame)
{
	//filtering process
	frame = this->doFiltering(frame);
	
	//labeling process
	frame = this->doLabeling(frame);
	
	return frame; 
}
//---------------------------------------------------------------------------------//
unsigned char* dip::frameObjects::doFiltering(unsigned char* frame)
{
	//binary image
	register unsigned char* p;
	int sizeI = W*H;
	for(p=frame; p < frame+sizeI*3; p++)
	{
		if(*p > 128) *p=255;
		else *p=0;
	}
	
	//dilatation process
      	/*
      	int k[] = {1, 1, 1,
		   1, 1, 1,
		   1, 1, 1 };
		   */
  
	int k[] = {1, 1, 1,
		   1, 1, 1,
		   1, 1, 1};

      	/*int k[] = {1, 0, 0, 0, 0, 0,
		   0, 1, 0, 0, 0, 0,
		   0, 0, 1, 0, 0, 0,
		   0, 0, 0, 1, 0, 0,
		   0, 0, 0, 0, 1, 0,
		   0, 0, 0, 0, 0, 1	
	};*/
		   
	dip::dilate mDil(W,H);
	mDil.setKernel(k, 3, 3);
	mDil.setHotSpot(1, 1);
	
	frame = mDil.execute(frame);
	//frame = mDil.execute(frame);
	//frame = mDil.execute(frame);
	//frame = mDil.execute(frame);
	
	return frame;
}
//---------------------------------------------------------------------------------//
unsigned char* dip::frameObjects::doLabeling(unsigned char* frame)
{
	//labeling procedure
	int sizeI = W*H;
	unsigned char *binImg = (unsigned char*) calloc(sizeI*3, sizeof(unsigned char));
	memcpy(binImg, frame, sizeI*3*sizeof(unsigned char));
	
	register unsigned char* p;
	for(p=binImg; p < binImg+sizeI*3; p++)
	{
		if(*p > 50) *p=0;
		else *p=1;
	}
	//dip::labeling mLab(W,H);
	if(mLab) delete(mLab);
	mLab = new dip::labeling(W,H);

	mLab->execute(binImg);
	
	//clear frame buffer
	register unsigned char* pF;
	for(pF=frame; pF < frame+sizeI*3; pF++)
	{
		*pF=0;
	}

	//object filtering by area
	int numOfObjects = mLab->numOfObjects();
	for(int i=0; i<numOfObjects; i++)
	{
		object cur = mLab->getObject(i);
		if(cur.area > m_minArea)
		{
			
			/*
			unsigned char cr = rand()%255;
			unsigned char cg = rand()%255;
			unsigned char cb = rand()%255;
			*/
			unsigned char cr = 255;
			unsigned char cg = 255;
			unsigned char cb = 255;
			
			int areaControl=0;

			for(register int j=0; j<W*H; j++)
			{
				if(mLab->getIndexMap()[j]==cur.index)
				{
					frame[j*3]=cr;
					frame[j*3+1]=cg;
					frame[j*3+2]=cb;

					areaControl++;
					if(areaControl==cur.area) break;
				}
			}
		}
	}

	free(binImg);
	return frame;
}
//---------------------------------------------------------------------------------//
vector<dip::object>* dip::frameObjects::getObjectList(void)
{
	vector<object>* objectList = new vector<object>;
	
	//object filtering by area
	int numOfObjects = mLab->numOfObjects();
	for(int i=0; i<numOfObjects; i++)
	{
		object cur = mLab->getObject(i);
		if(cur.area > m_minArea)
		{
		      objectList->push_back(cur);
		}
	}
	
	return objectList;
}
//---------------------------------------------------------------------------------//
