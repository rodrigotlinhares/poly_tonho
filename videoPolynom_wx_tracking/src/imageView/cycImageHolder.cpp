#include "cycImageHolder.h"

//---------------------------------------------------------------------------------
cycImageHolder::cycImageHolder(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) :
               wxScrolledWindow(parent,id,pos,size,style,name)
{
	m_mouseEventKind = NO_TOOL;
	m_imageRaw = m_imageInit = NULL;

	//initialize the external event pointers
	disableAllFunc_to_Events();
	
	//initialize zoom ratio
	m_zoomRatio = 1;
	setZoomLimit(4);
}
//---------------------------------------------------------------------------------
cycImageHolder::~cycImageHolder() 
{
	if(m_imageInit) 
		delete m_imageInit;
	
	if(m_imageRaw)
		delete m_imageRaw;
}
//---------------------------------------------------------------------------------
void cycImageHolder::SetImage(wxImage *_imageRaw)
{
	//clear images
	if(m_imageInit) 
		delete m_imageInit;
	if(m_imageRaw) 
		delete m_imageRaw;
	
	m_imageInit = _imageRaw;
	
	//copy m_imageInit to m_imageRaw
	wxImage *buffImage = new wxImage(*m_imageInit);
	m_imageRaw = buffImage;
	
	this->setWndSize(m_imageInit->GetWidth(), m_imageInit->GetHeight());
	this->Refresh(false);
}
//---------------------------------------------------------------------------------
wxPoint cycImageHolder::ScreenToImageCoordinates(const int X, const int Y)
{
	int _X = (int)(X - m_panMoving[0].x) / m_zoomRatio;
	int _Y = (int)(Y - m_panMoving[0].y) / m_zoomRatio;
	
	return wxPoint(_X, _Y);
}
//---------------------------------------------------------------------------------
wxPoint cycImageHolder::ImageToScreenCoordinates(const int X, const int Y)
{
	int _X = (int)(X * m_zoomRatio) + m_panMoving[0].x;
	int _Y = (int)(Y * m_zoomRatio) + m_panMoving[0].y;
	
	return wxPoint(_X, _Y);
}
//---------------------------------------------------------------------------------
void cycImageHolder::setWndSize(unsigned int _x, unsigned int _y)
{
	if(_x)
		m_wndRawWidth  = _x;
	
	if(_y)
		m_wndRawHeight = _y; 
}
//---------------------------------------------------------------------------------
wxImage *cycImageHolder::getInitImage()
{
	return m_imageInit;
}
//---------------------------------------------------------------------------------
void cycImageHolder::setZoomLimit(float x)
{
	m_maxZoomRatio = x;
}
//---------------------------------------------------------------------------------
wxRect cycImageHolder::getImageRawView()
{
	return m_imageRawView;
}
//---------------------------------------------------------------------------------
void cycImageHolder::restoreDefaults()
{
    m_zoomRatio = 1;
    m_panMoving[0].x = 0;
    m_panMoving[0].y = 0;
}
//---------------------------------------------------------------------------------