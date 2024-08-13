#include "cycEvtReferences.h"

//---------------------------------------------------------------------------------
void cycImageHolder::setFunc_to_OnLeftMouseButtonUp(void (*pfun)(wxMouseEvent& event, wxWindow *_this))
{
	pEvtFunc_OnLeftMouseButtonUp = pfun;
}
//---------------------------------------------------------------------------------
void cycImageHolder::setFunc_to_OnRightMouseButtonUp(void (*pfun)(wxMouseEvent& event, wxWindow *_this))
{
	pEvtFunc_OnRightMouseButtonUp = pfun;
}
//---------------------------------------------------------------------------------
void cycImageHolder::setFunc_to_OnLeftMouseButtonDClick(void (*pfun)(wxMouseEvent& event, wxWindow *_this))
{
	pEvtFunc_OnLeftMouseButtonDClick = pfun;
}
//---------------------------------------------------------------------------------
void cycImageHolder::setFunc_to_OnMouseMotionLClick(void (*pfun)(wxMouseEvent& event, wxWindow *_this))
{
	pEvtFunc_OnLeftMouseMotionLClick = pfun;
}
//---------------------------------------------------------------------------------
void cycImageHolder::setFunc_to_OnMouseMotionRClick(void (*pfun)(wxMouseEvent& event, wxWindow *_this))
{
	pEvtFunc_OnLeftMouseMotionRClick = pfun;
}
//---------------------------------------------------------------------------------
