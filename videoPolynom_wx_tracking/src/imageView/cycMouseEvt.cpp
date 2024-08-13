//#include "imageView/cycMouseEvt.h"
#include "cycMouseEvt.h"
//---------------------------------------------------------------------------------
BEGIN_EVENT_TABLE(cycImageHolder, wxScrolledWindow)

	EVT_PAINT(cycImageHolder::OnPaint)
	EVT_LEFT_UP(cycImageHolder::OnLeftMouseButtonUp)
	EVT_LEFT_DOWN(cycImageHolder::OnLeftMouseButtonDown)
	EVT_RIGHT_UP(cycImageHolder::OnRightMouseButtonUp) 
	EVT_LEFT_DCLICK(cycImageHolder::OnLeftMouseButtonDClick) 
	EVT_MOTION(cycImageHolder::OnMouseMotion)

END_EVENT_TABLE()
//---------------------------------------------------------------------------------
void cycImageHolder::OnLeftMouseButtonDClick(wxMouseEvent& event)
{
	//if defined a function.... call it
	if(pEvtFunc_OnLeftMouseButtonDClick)
	{
		pEvtFunc_OnLeftMouseButtonDClick(event, this->GetParent()); 
		return;
	}
}

//---------------------------------------------------------------------------------
void cycImageHolder::OnLeftMouseButtonUp(wxMouseEvent& event)
{
	//if defined a function.... call it
	if(pEvtFunc_OnLeftMouseButtonUp)
	{
		pEvtFunc_OnLeftMouseButtonUp(event, this->GetParent()); 
		return;
	}
}
//---------------------------------------------------------------------------------
void cycImageHolder::OnRightMouseButtonUp(wxMouseEvent& event)
{
	//if defined a function.... call it
	if(pEvtFunc_OnRightMouseButtonUp)
	{
		pEvtFunc_OnRightMouseButtonUp(event, this->GetParent());  
		return;
	}
}
//---------------------------------------------------------------------------------
void cycImageHolder::OnLeftMouseButtonDown(wxMouseEvent& event)
{
	//if defined a function.... call it
	if(pEvtFunc_OnLeftMouseButtonDown)
	{
		pEvtFunc_OnLeftMouseButtonDown(event, this->GetParent());  
		return;
	}

	//get init coordinate to pan image
	if(m_mouseEventKind == PAN)
	{
		(m_panMoving+1)->x = event.GetPosition().x;
		(m_panMoving+1)->y = event.GetPosition().y;
	}
}
//---------------------------------------------------------------------------------
void cycImageHolder::OnMouseMotion(wxMouseEvent& event)
{
	if(event.LeftIsDown())
	{
		if(m_mouseEventKind == NO_TOOL)
		{
			if(pEvtFunc_OnLeftMouseMotionLClick)
			{
				pEvtFunc_OnLeftMouseMotionLClick(event, this->GetParent());  
			}
		}
			
		if(m_mouseEventKind == PAN)
		{
			//get translation value and refresh image on device
			(m_panMoving+0)->x += (event.GetPosition().x - (m_panMoving+1)->x);
			(m_panMoving+0)->y += (event.GetPosition().y - (m_panMoving+1)->y);
	
			(m_panMoving+1)->x = event.GetPosition().x;
			(m_panMoving+1)->y = event.GetPosition().y;
	
			this->Refresh(false);		
		}
	}
	//***************
	if(event.RightIsDown())
	{
		if(m_mouseEventKind == NO_TOOL)
		{
			if(pEvtFunc_OnLeftMouseMotionLClick)
			{
				pEvtFunc_OnLeftMouseMotionRClick(event, this->GetParent());  			
			}
		}
	}
}
//---------------------------------------------------------------------------------
void cycImageHolder::disableAllFunc_to_Events()
{
	pEvtFunc_OnLeftMouseButtonUp		= NULL;
	pEvtFunc_OnLeftMouseButtonDown		= NULL;
	pEvtFunc_OnRightMouseButtonUp		= NULL;
	pEvtFunc_OnLeftMouseButtonDClick	= NULL;
	pEvtFunc_OnLeftMouseZoom			= NULL;
	pEvtFunc_OnLeftMouseMotionLClick	= NULL;
	pEvtFunc_OnLeftMouseMotionRClick 	= NULL;
}
//---------------------------------------------------------------------------------
void cycImageHolder::setMouseState(MouseEventKind _mouseState)
{
	m_mouseEventKind = _mouseState;
}
//---------------------------------------------------------------------------------
void cycImageHolder::setPanMouse(bool active)
{
	if(active)
		m_mouseEventKind = PAN;
	else
		m_mouseEventKind = NO_TOOL;
}
//---------------------------------------------------------------------------------
void cycImageHolder::zoomIn(float scale, bool incremental)
{
	if(!m_imageRaw) return;

	//zoomRatio control
	(incremental) ? m_zoomRatio += scale : m_zoomRatio = scale;
	(m_zoomRatio >= m_maxZoomRatio ) ? m_zoomRatio -= scale : m_zoomRatio=m_zoomRatio;

	//makes image be zoomed into middle
	uptadeZoomRate(m_zoomRatio);
	
	//new image to copy scaled image
	//wxImage *buffImage = new wxImage(*m_imageInit);
	//buffImage->Rescale(m_imageInit->GetWidth() * m_zoomRatio, m_imageInit->GetHeight() * m_zoomRatio);

	//delete m_imageRaw;
	//m_imageRaw = buffImage;
	
	this->Refresh(false);
}
//---------------------------------------------------------------------------------
void cycImageHolder::zoomOut(float scale, bool incremental)
{
	if(!m_imageRaw) return;

	//zoomRatio control
	(incremental) ? m_zoomRatio -= scale : m_zoomRatio = scale;
	(m_zoomRatio <= 0.25 ) ? m_zoomRatio += scale : m_zoomRatio=m_zoomRatio;

	//makes image be zoomed into middle
	uptadeZoomRate(m_zoomRatio);
	
	//new image to copy scaled image
	//wxImage *buffImage = new wxImage(*m_imageInit);
	//buffImage->Rescale(m_imageInit->GetWidth() * m_zoomRatio, m_imageInit->GetHeight() * m_zoomRatio);

	//delete m_imageRaw;
	//m_imageRaw = buffImage;

	this->Refresh(false);
}
//---------------------------------------------------------------------------------
void cycImageHolder::uptadeZoomRate(float scale)
{
	//calculate window center position
	int centerX = m_wndRawWidth / 2; 
	int centerY = m_wndRawHeight/ 2;
	
	//calculate variation between images
	float diffX = (float) m_imageInit->GetWidth()*scale / m_imageRaw->GetWidth();
	float diffY = (float) m_imageInit->GetHeight()*scale / m_imageRaw->GetHeight();
	
	//desloc Width and Height
	int deslocX = centerX - (m_panMoving+0)->x;
	int deslocY = centerY - (m_panMoving+0)->y;
	
	//new desloc Width and Height
	int newDeslocX = (int)deslocX * diffX;
	int newDeslocY = (int)deslocY * diffY;
	
	//setting new pan coordinate
	(m_panMoving+0)->x = centerX - newDeslocX;
	(m_panMoving+0)->y = centerY - newDeslocY;
	(m_panMoving+1)->x = centerX - newDeslocX;
	(m_panMoving+1)->y = centerY - newDeslocY;
}
//---------------------------------------------------------------------------------
