/* 
 * File:   logitechWrapper.h
 * Author: asobieranski@cyclops.ufsc.br
 *
 * Created on November, 17, 2010, 11:50 AM
 */

#include "logitechWrapper.h"
#include <sstream>

//---------------------------- -------------------------------------------------
logitechWrapper::logitechWrapper() 
{
	int i=system("uvcdynctrl &> /dev/null");
	if(i)
	{
		printf("\nCamera control is not available\n");
		m_available=false;
	}
	else
	{
		m_available=true;
		printf("\nCamera control is available\n");

		m_dev.append("/dev/video0");

		string command;
		command.append("uvcdynctrl -c -d /dev/video0");
		system(command.c_str());
		
		printf("\n\n");
		m_x = 0;
		m_y = 0;
	}
}
//-----------------------------------------------------------------------------
logitechWrapper::~logitechWrapper() 
{
}
//-----------------------------------------------------------------------------
void logitechWrapper::resetPositions(int code)
{
	if(!m_available) return;
	
	std::stringstream oss;
	oss << "uvcdynctrl -d " << m_dev.c_str() << " -s 'Pan/tilt Reset' " << code << '\n';

	system(oss.str().c_str());
	
	if(code == 1) m_x = 0;
	if(code == 2) m_y = 0;
	if(code == 3) m_x = m_y = 0;
}
//-----------------------------------------------------------------------------
void logitechWrapper::setDevice(string dev)
{
	if(!m_available) return;
	
	m_dev.clear();
	m_dev.append(dev.c_str());
}
//-----------------------------------------------------------------------------
void logitechWrapper::setPanRel(int value)
{
	if(!m_available) return;
	
	//if(m_x+value > 4500) return;
	//if(m_x-value < -4500) return;
	//m_x += value;
	
	std::stringstream oss;
	if(value < 0)
		oss << "uvcdynctrl -d " << m_dev.c_str() << " -s 'Pan (relative)' -- -" << value*(-1) << '\n';
	else
		oss << "uvcdynctrl -d " << m_dev.c_str() << " -s 'Pan (relative)' " << value << '\n';

	system(oss.str().c_str());
}
//-----------------------------------------------------------------------------
void logitechWrapper::setTiltRel(int value)
{
	if(!m_available) return;
	
	//if(m_y+value > 1500) return;
	//if(m_y-value < -2000) return;
	//m_y += value;

	std::stringstream oss;
	if(value < 0)
		oss << "uvcdynctrl -d " << m_dev.c_str() << " -s 'Tilt (relative)' -- -" << value*(-1) << '\n';
	else
		oss << "uvcdynctrl -d " << m_dev.c_str() << " -s 'Tilt (relative)' " << value << '\n';

	system(oss.str().c_str());
}
//-----------------------------------------------------------------------------
void logitechWrapper::setFocus(int value)
{
	std::stringstream oss;
	oss << "uvcdynctrl -d " << m_dev.c_str() << " -s 'Focus' " << value << '\n';
  
	system(oss.str().c_str());
}
//-----------------------------------------------------------------------------
