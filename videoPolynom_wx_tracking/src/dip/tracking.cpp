#include "tracking.h"

//---------------------------------------------------------------------------------//
dip::tracking::tracking(int W, int H)
{
	this->W = W;
	this->H = H;
	
	mLab = NULL;
	m_listOfFrames = NULL;
	
	m_correspondencyMethod = MINIMAL_DISTANCE;
}
//---------------------------------------------------------------------------------//
dip::tracking::~tracking()
{
	if(mLab) delete(mLab);
	
	if(m_listOfFrames)
	{
		dip::frameTr* currFrame = m_listOfFrames;
		while(currFrame)
		{
			dip::frameTr* nextFr = currFrame->nextFr;
			dip::objectTr* currObject = currFrame->m_objects;
			while(currObject)
			{
				dip::objectTr* nextOb = currObject->nextOb;
				delete currObject;
				currObject = nextOb;				
			}
			delete currFrame;
			currFrame = nextFr;
		}
	}
}
//---------------------------------------------------------------------------------//
void dip::tracking::addBinFrame(unsigned char* frame)
{
	//do labeling over a new frame
	this->doLabeling(frame);
	
	//track objects
	this->doTrackObjects2();
}
//---------------------------------------------------------------------------------//
void dip::tracking::doLabeling(unsigned char* frame)
{
	//labeling procedure
	int sizeI = W*H;
	
	register unsigned char* p;
	for(p=frame; p < frame+sizeI*3; p++)
	{
		if(*p > 50) *p=0;
		else *p=1;
	}

	//labeling instanc
	if(mLab) delete(mLab);
	mLab = new dip::labeling(W,H);

	mLab->execute(frame);
}
//---------------------------------------------------------------------------------//
void dip::tracking::doTrackObjects2()
{
	int sizeL=mLab->numOfObjects();
	
	dip::frameTr* newFrame = new dip::frameTr();
	static unsigned int maxIndex=0;
	
	//***** storing objects in m_listObject
	dip::objectTr* currObject;
	for(int i=0; i<sizeL; i++)
	{
		//creating a new trObject
		dip::objectTr* newObject   = new dip::objectTr();
		
		newObject->m_labelingIndex = mLab->getObject(i).index;
		newObject->m_area          = mLab->getObject(i).area;
		newObject->m_center.x	   = mLab->getObject(i).center.x;
		newObject->m_center.y	   = mLab->getObject(i).center.y;
		
		//if is the first time the objects receive an index. otherwise, 0
		if(!m_listOfFrames)
			newObject->m_trIndex = ++maxIndex;

		//push back into objectsInFrame
		if(!newFrame->m_objects)
		{
			newFrame->m_objects = newObject;
			currObject = newObject;
		}
		else
		{
			currObject->nextOb = newObject;
			newObject->priorOb = currObject;
			currObject = newObject;
		}
		//currObject->numberOfObjects++;
	}
	//push back into m_listObject
	if(!m_listOfFrames)
	{
		m_listOfFrames = newFrame;
		m_pLastFrame = newFrame;
	}
	else
	{
		m_pLastFrame->nextFr = newFrame;
		newFrame->priorFr = m_pLastFrame;
		m_pLastFrame = newFrame;
	}
	//m_pLastFrame->numberOfFrames++;
	
	//***** tracking objects in the last frame
	if(m_listOfFrames != m_pLastFrame)
	{
		dip::objectTr* currObject = m_pLastFrame->m_objects;
		while(currObject)
		{
			dip::objectTr* queryObject = currObject;
			dip::objectTr* correspObject = findCorrespondency(queryObject);
			//link trajectories
			if(correspObject)
			{
			      queryObject->priorTr = correspObject;
			      correspObject->nextTr = queryObject;
			      queryObject->m_trIndex = correspObject->m_trIndex;
			}
			else
			{
			      queryObject->m_trIndex = ++maxIndex;
			      printf("\n*** There is a new trajectory with index %d", maxIndex);
			}

			currObject = currObject->nextOb;
		}
	}
	
	/*
	//DEBUG HERE
	dip::objectTr* currLastObjec = m_pLastFrame->m_objects;
	
	int i=0;
	while(currLastObjec)
	{
		dip::objectTr* currObjecttt = currLastObjec;	
		
		printf("\nObject : %d", ++i);
		while(currObjecttt)
		{
			  printf("\ncurrObject: %d %d %d %d", currObjecttt->m_center.x, currObjecttt->m_center.y, currObjecttt->m_labelingIndex, currObjecttt->m_trIndex);
			  currObjecttt = currObjecttt->priorTr;
			  printf("\n-----------------------");
		}	
		printf("\n-----------------------");
		currLastObjec = currLastObjec->nextOb;
	}
	*/
}
//---------------------------------------------------------------------------------//
dip::objectTr* dip::tracking::findCorrespondency(dip::objectTr* queryObject)
{
	if(m_correspondencyMethod == MINIMAL_DISTANCE)
	{
		return fc_minimalDistance(queryObject);
	}
	return 0;
}
//---------------------------------------------------------------------------------//
dip::objectTr* dip::tracking::fc_minimalDistance(dip::objectTr* queryObject)
{
	//search in all frames....
	dip::frameTr* currFrame = m_pLastFrame->priorFr;
	int frameLimit = 0;
	while(currFrame && frameLimit++ < 5)
	{
		//printf("\n\nCrossing query with frame objects");

		//...and in all objects in that frames....
		float minDe = 999999;
		
		dip::objectTr* currObject = currFrame->m_objects;
		dip::objectTr* minObjectDistance;
		while(currObject)
		{
			float de = (currObject->m_center.x - queryObject->m_center.x)*(currObject->m_center.x - queryObject->m_center.x) +
				   (currObject->m_center.y - queryObject->m_center.y)*(currObject->m_center.y - queryObject->m_center.y);
			
			de = sqrt(de);
			if(de < minDe)
			{
				minDe=de;
				minObjectDistance = currObject;
			}
			
			//printf("\nIndex = %.3f", de);

			currObject = currObject->nextOb;
		}
		//printf("\n-------------\n");
		
		//if((minDe < 50) && (minObjectDistance->m_trIndex!=0))
		if(minDe < 80 && minObjectDistance->nextTr == NULL)
		{
			return minObjectDistance;
		}
		
		//else continue
		currFrame = currFrame->priorFr;
	}
	return NULL;
}
//---------------------------------------------------------------------------------//
dip::trajectories* dip::tracking::getTrajectories(int n_lastFrames, int timeStep)
{
	dip::trajectories* m_traject = new dip::trajectories();
	
	vector<unsigned int> usedTrajectories;
	
	//search in all N last frames....
	dip::frameTr* currFrame = m_pLastFrame;
	int frameLimit = 0;
	while(currFrame && frameLimit++ < n_lastFrames)
	{
		dip::objectTr* currObject = currFrame->m_objects;
		while(currObject)
		{
			bool usedTraj = false;
			if(usedTrajectories.size() > 0)
			{
				for(unsigned int k=0; k<usedTrajectories.size(); k++)
				{
					if(currObject->m_trIndex == usedTrajectories.at(k))
					{
						usedTraj=true;
						break;
					}
				}
			}
			if(!usedTraj)
			{
				usedTrajectories.push_back(currObject->m_trIndex);
				m_traject->newTrajectory();
				
				dip::objectTr* followLinks = currObject;
				int timeStepC=frameLimit;

				//FILTER by time step or all possible trajectories 
				if(timeStep == -1)
				{
					while(followLinks)
					{
						m_traject->setCoordinate(followLinks->m_center.x,
									followLinks->m_center.y, 
									followLinks->m_trIndex,
									timeStepC++
									);
						followLinks = followLinks->priorTr;
					}
				}
				else
				{
					while(followLinks)
					{
						if(timeStepC < timeStep) 
						{
							m_traject->setCoordinate(followLinks->m_center.x,
										followLinks->m_center.y, 
										followLinks->m_trIndex,
										timeStepC++
										);
						}
						else 
							break;
						followLinks = followLinks->priorTr;
					}
				}
			}
			currObject = currObject->nextOb;
		}
		currFrame = currFrame->priorFr;
	}
	
	//printf("\nsize in draw: %d - %d", usedTrajectories.size(), m_traject->getTrajectoriesNumber());
	
	return m_traject;
}
//---------------------------------------------------------------------------------//
