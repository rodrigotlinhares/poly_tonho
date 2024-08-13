/* 
 * File:   logitechWrapper.h
 * Author: asobieranski@cyclops.ufsc.br
 *
 * Created on November, 17, 2010, 11:50 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
//#include <unistd.h>

#ifndef _LOGITECHWRAPPER_H
#define	_LOGITECHWRAPPER_H

using namespace std;

class logitechWrapper {
private:
	int m_x, m_y;
  
	//control if uvcdynctrl is available in the system
	bool m_available;
	
	//camera current device
	string m_dev;
	
public:
	//constructors and destructors methods
	logitechWrapper();
	~logitechWrapper();

	//set device camera number
	void setDevice(string dev);
	
	//reset camera positions  //0-PAN  //1-TILT  //2-BOTH
	void resetPositions(int code);
	
	//set focus
	void setFocus(int value);

	//setPan Relative
	void setPanRel(int value);
	
	//setTilt Relative
	void setTiltRel(int value);
	
};
//-----------------------------------------------------------------------------
#endif	/* _LOGITECHWRAPPER_H */
