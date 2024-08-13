#include "trajectories.h"

//---------------------------------------------------------------------------------//
dip::trajectories::trajectories()
{
  
}
//---------------------------------------------------------------------------------//
dip::trajectories::~trajectories()
{
  
}
//---------------------------------------------------------------------------------//
void dip::trajectories::newTrajectory()
{
	vector<point2D> mTrajectory;
	m_trajectories.push_back(mTrajectory);
}
//---------------------------------------------------------------------------------//
void dip::trajectories::setCoordinate(int x, int y, unsigned int trIndex, unsigned int timeStep)
{
	int lastIndex = m_trajectories.size();
	m_trajectories.at(lastIndex-1).push_back(point2D(x,y,trIndex,timeStep));
}
//---------------------------------------------------------------------------------//
int dip::trajectories::getTrajectoriesNumber()
{
	return m_trajectories.size();
}
//---------------------------------------------------------------------------------//
vector<dip::point2D> dip::trajectories::getTrajectory(int index)
{
	return m_trajectories.at(index);
}
//---------------------------------------------------------------------------------//
