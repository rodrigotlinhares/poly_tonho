#ifndef CYCIMAGEHOLDER_H
#define CYCIMAGEHOLDER_H
//---------------------------------------------------------------------------------
#include <wx/wx.h> 
#include <wx/image.h>
#include <wx/dcbuffer.h>

//---------------------------------------------------------------------------------
enum  MouseEventKind { NO_TOOL, ZOOM, FASTZOOM, PAN};
//---------------------------------------------------------------------------------
class cycImageHolder : public wxScrolledWindow 
{
	//**********    imageView/cycEvtReferences.h       *********//
	//															//
	//			   Events and Pointers to references			//
	//															//
protected:
	//external pointers to mouse events
	void (*pEvtFunc_OnLeftMouseButtonUp)(wxMouseEvent& event, wxWindow *_this);
	void (*pEvtFunc_OnLeftMouseButtonDown)(wxMouseEvent& event, wxWindow *_this);
	void (*pEvtFunc_OnRightMouseButtonUp)(wxMouseEvent& event, wxWindow *_this);
	void (*pEvtFunc_OnLeftMouseButtonDClick)(wxMouseEvent& event, wxWindow *_this);
	void (*pEvtFunc_OnLeftMouseMotionLClick)(wxMouseEvent& event, wxWindow *_this);
	void (*pEvtFunc_OnLeftMouseMotionRClick)(wxMouseEvent& event, wxWindow *_this);	
	void (*pEvtFunc_OnLeftMouseZoom)(wxMouseEvent& event, wxWindow *_this);
	
	
public:
	
	//pointers to image holder event functions
	void setFunc_to_OnLeftMouseButtonUp(void (*pfun)(wxMouseEvent& event, wxWindow *_this));
	void setFunc_to_OnRightMouseButtonUp(void (*pfun)(wxMouseEvent& event, wxWindow *_this));
	void setFunc_to_OnLeftMouseButtonDClick(void (*pfun)(wxMouseEvent& event, wxWindow *_this));
	void setFunc_to_OnMouseMotionLClick(void (*pfun)(wxMouseEvent& event, wxWindow *_this));
	void setFunc_to_OnMouseMotionRClick(void (*pfun)(wxMouseEvent& event, wxWindow *_this));
	//disable all pointers to functions
	void disableAllFunc_to_Events() const {
		disableAllFunc_to_Events();
	};
	//---------------------------------------------------------------------------------
	
		
	
	//**********    imageView/cycMouseEvt.h            *********//
	//															//
	//			   Mouse Events									//
	//															//
protected:
	//mouse current state
	MouseEventKind m_mouseEventKind;
	
public:
	
	//--- mouse events
        virtual void OnLeftMouseButtonUp(wxMouseEvent& event);
	virtual void OnLeftMouseButtonDown(wxMouseEvent& event);
        virtual void OnRightMouseButtonUp(wxMouseEvent& event);
	virtual void OnLeftMouseButtonDClick(wxMouseEvent& event);
	virtual void OnMouseMotion(wxMouseEvent& event);
	void disableAllFunc_to_Events();	

	//--- set mouse state
	void setMouseState(MouseEventKind _mouseState);
	//enable or disable PAN mouse
	void setPanMouse(bool active = true);
	//zoomIn on display image (incremental == true takes a sum of prior scale value)
	void zoomIn(float scale, bool incremental = true);
	//zoomOut on display image (incremental == true takes a sum of prior scale value)
	void zoomOut(float scale, bool incremental = true);
	//makes image be zoomed into middle direction  ***Atention: Call this before rezise image
	void uptadeZoomRate(float scale);
        //restor default values for zoom and pan.
        void restoreDefaults();
        
	//---------------------------------------------------------------------------------
	
	
	
	//**********    imageView/cycImageDraw.h            *********//
	//															 //
	//			   Drawing Events								 //
	//															 //
public:
	
	//--- drawing events
	void OnPaint(wxPaintEvent& event);
	virtual void Draw(wxBufferedPaintDC &dc);
	
	//update window
	void updateWindow();
	

	//---------------------------------------------------------------------------------
	
	
	
	//**********    imageView/cycImageHolder.h            *********//
	//															   //
	//			   Main Image Holder header						   //
	//															   //
	//**********    imageView/cycImageHolder.h            *********//
	//															   //
	//			   Main Image Holder header						   //
	//															   //
protected:
	//window Size
	unsigned int m_wndRawWidth;
	unsigned int m_wndRawHeight;
	
	
	//input image
	wxImage *m_imageInit;
	//image raw to show in device
	wxImage *m_imageRaw;
	//zoom ratio defalt 1
	float m_zoomRatio;
	//max zoom ratio (default=4x)
	float m_maxZoomRatio;
	
	//init current coordenate "A" and prior position "B"
	wxPoint m_panMoving[2];
	
	//rect correponding of image raw showing now....
	wxRect m_imageRawView;
	
	
	
public:
	//Constructors and Destructor
    cycImageHolder(wxWindow* parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxSIMPLE_BORDER, const wxString& name = wxT("scrolledWindow"));
    virtual ~cycImageHolder(); 
    
	//set raw image (management memory)
	virtual void SetImage(wxImage *_imageRaw);
	//get Init Image
	wxImage *getInitImage();

	//screen windows convertion
	wxPoint ScreenToImageCoordinates(const int X, const int Y);
	wxPoint ImageToScreenCoordinates(const int X, const int Y);
	
	//return the rect correponding of image raw showing now...
	wxRect getImageRawView();

	//set window Size
	void setWndSize(unsigned int _x, unsigned int _y);
	
	//set zoom limit
	void setZoomLimit(float x);
	//---------------------------------------------------------------------------------


	DECLARE_EVENT_TABLE();
	
};
//---------------------------------------------------------------------------------
#endif 
