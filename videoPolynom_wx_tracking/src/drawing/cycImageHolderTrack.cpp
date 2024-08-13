#include "cycImageHolderTrack.h"
#include <cmath>
//--------------------------------------------------------------------------------
void cycImageHolderTrack::Draw(wxBufferedPaintDC &dc)
{
	//call draw image in base class
	cycImageHolder::Draw(dc);
	
        //show a RED point based on init and last points
        dc.SetPen(wxPen(wxColour(255,0,0), 1, wxSOLID));
	
	//drawn boxes
	if(m_objectList!=NULL)
	{
		int trackingIndex = getSelectedIndexObject();

		for(unsigned int i=0; i<m_objectList->size(); i++)
		{
			  wxPoint convInit = ImageToScreenCoordinates(m_objectList->at(i).center.x, m_objectList->at(i).center.y);

			  if(trackingIndex != -1 && m_trajectories!=NULL && m_enableTrSelection)
			  {

				  if(m_trajectories->getTrajectory(trackingIndex).at(0).x == m_objectList->at(i).center.x &&
				     m_trajectories->getTrajectory(trackingIndex).at(0).y == m_objectList->at(i).center.y)
				  {
					dc.SetPen(wxPen(wxColour(255,255,0), 2, wxSOLID));
				  }
				  else
				  {
					dc.SetPen(wxPen(wxColour(255,0,0), 1, wxSOLID));
				  }
			  }

			  dc.DrawCircle(convInit.x, convInit.y, 3);
			  
			  dc.DrawLine(m_objectList->at(i).limits[0].x, m_objectList->at(i).limits[2].y, 
				      m_objectList->at(i).limits[1].x, m_objectList->at(i).limits[2].y);
			  dc.DrawLine(m_objectList->at(i).limits[1].x, m_objectList->at(i).limits[2].y, 
				      m_objectList->at(i).limits[1].x, m_objectList->at(i).limits[3].y);
			  dc.DrawLine(m_objectList->at(i).limits[1].x, m_objectList->at(i).limits[3].y, 
				      m_objectList->at(i).limits[0].x, m_objectList->at(i).limits[3].y);
			  dc.DrawLine(m_objectList->at(i).limits[0].x, m_objectList->at(i).limits[3].y, 
				      m_objectList->at(i).limits[0].x, m_objectList->at(i).limits[2].y);

		}
	}
	
	//drawn trackers !
	if(m_trajectories!=NULL)
	{
		int size = m_trajectories->getTrajectoriesNumber();
		//printf("\nsize in draw: %d", size);

		for(int i=0; i<size; i++)
		{
			vector<dip::point2D> mList2D = m_trajectories->getTrajectory(i);
			int prevX, prevY;
			prevX=prevY=-1;

			//for(unsigned int j=0; j<mList2D.size(); j++)
			for(unsigned int j=0; j<mList2D.size() && j<20; j++)
			{
				unsigned char r=(mList2D.at(0).trIndex*150);
				unsigned char g=(mList2D.at(0).trIndex*100);
				unsigned char b=(mList2D.at(0).trIndex*50);
				
				dc.SetPen(wxPen(wxColour(r,g,b), 2, wxSOLID));
				dc.DrawCircle(mList2D.at(j).x, mList2D.at(j).y, 2);
				
				if(prevX!=-1 && prevY!=1)
				    dc.DrawLine(mList2D.at(j).x, mList2D.at(j).y, prevX, prevY);
				
				prevX = mList2D.at(j).x;
				prevY = mList2D.at(j).y;
			}
		}
	}

	//select the nearest object to be tracked !!!
	if(m_enableTrSelection)
	{
		float minDE = 99999;
		m_nearestObjectIndex = -1;
		int size = m_trajectories->getTrajectoriesNumber();

		for(int i=0; i<size; i++)
		{
			int xx = m_trajectories->getTrajectory(i).at(0).x;
			int yy = m_trajectories->getTrajectory(i).at(0).y;

            float DE = std::pow((currPos.x-xx)*(currPos.x-xx) + (currPos.y-yy)*(currPos.y-yy), 0.5);
			if(DE < minDE && DE < 150)
			{
				minDE = DE;
				m_nearestObjectIndex=i;
			}

		}
		//draw a line to the nearest trajectory
		if(m_nearestObjectIndex != -1)
		{
			dc.SetPen(wxPen(wxColour(0,0,0), 4, wxSOLID));
			dc.DrawLine(m_trajectories->getTrajectory(m_nearestObjectIndex).at(0).x, m_trajectories->getTrajectory(m_nearestObjectIndex).at(0).y, 
				   currPos.x, currPos.y);
		}
	}
}
//--------------------------------------------------------------------------------
cycImageHolderTrack::~cycImageHolderTrack()
{
	if(m_objectList) delete m_objectList;
	if(m_trajectories) delete m_trajectories;
}
//--------------------------------------------------------------------------------
void cycImageHolderTrack::clearObjectList()
{
	if(m_objectList) delete m_objectList;
	m_objectList = NULL;
}
//--------------------------------------------------------------------------------
void cycImageHolderTrack::clearTrajectories()
{
	if(m_trajectories) delete m_trajectories;
	m_trajectories = NULL;	
}
//--------------------------------------------------------------------------------
void cycImageHolderTrack::setObjectList(vector<dip::object>* _objL)
{
	if(m_objectList) delete m_objectList;
	
	m_objectList = _objL;
	/*
	for(unsigned int i=0; i<m_objectList->size(); i++)
	{
		printf("Indice: %d", m_objectList->at(i).index);
		printf("\t");
		printf("Area: %d", m_objectList->at(i).area);
		printf("\t");
		printf("X: %d", m_objectList->at(i).center.x);
		printf("\t");
		printf("Y: %d", m_objectList->at(i).center.y);
		printf("\n\n\n");
	}*/
}
//--------------------------------------------------------------------------------
void cycImageHolderTrack::setTrajectories(dip::trajectories* _traject)
{
	if(m_trajectories) delete m_trajectories;
	m_trajectories = _traject;
}
//---------------------------------------------------------------------------------
void cycImageHolderTrack::OnMouseMotion(wxMouseEvent& event)
{
	currPos.x = event.GetPosition().x;
	currPos.y = event.GetPosition().y;
	//printf("\n%d - %d", currPos.x, currPos.y);
}
//---------------------------------------------------------------------------------
void cycImageHolderTrack::OnLeftMouseButtonUp(wxMouseEvent& event)
{
	if(!m_trajectories) return;
	if(!m_trajectories->getTrajectoriesNumber()) return;
	if(m_nearestObjectIndex == -1) return;

	m_trackingIndex = m_trajectories->getTrajectory(m_nearestObjectIndex).at(0).trIndex;	
}
//---------------------------------------------------------------------------------
int cycImageHolderTrack::getSelectedIndexObject()
{
	int size = m_trajectories->getTrajectoriesNumber();
	for(int i=0; i<size; i++)
	{
		if(m_trackingIndex == (int) m_trajectories->getTrajectory(i).at(0).trIndex)
			return i;
	}
	return -1;
}
//---------------------------------------------------------------------------------
void cycImageHolderTrack::enableTrackSelection(bool option)
{

  printf("option: %d\n", m_enableTrSelection);
	m_enableTrSelection = option;
}
//---------------------------------------------------------------------------------
