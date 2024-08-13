#ifndef _TRAJECTORIES_H
#define _TRAJECTORIES_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using std::vector;
using namespace std;

//this class is responsible for trajectory managenment
namespace dip
{

class point2D
{
public:
	point2D(int _x, int _y, unsigned int _trIndex, unsigned int _timeStep) : x(_x), y(_y), trIndex(_trIndex), timeStep(_timeStep) { };
	int x, y;
	unsigned int trIndex;
	unsigned int timeStep;
};
  
class trajectories
{
private:
	vector<vector<point2D> > m_trajectories;
    
public:
	trajectories();
	~trajectories();
	
	//define a new trajectory to be inserted
	void newTrajectory();
	
	//putt a coordinate to the last new trajectory specified
	void setCoordinate(int x, int y, unsigned int trIndex, unsigned int timeStep);
	
	//get number of trajectories
	int getTrajectoriesNumber();

	//get trajectory of index I
	vector<point2D> getTrajectory(int index);
};
  
};
#endif
