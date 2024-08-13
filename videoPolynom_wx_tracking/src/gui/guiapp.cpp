/////////////////////////////////////////////////////////////////////////////
// Name:        guiapp.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     Thu 05 Aug 2010 09:59:54 BRT
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "guiapp.h"

using namespace cv;

////@begin XPM images

////@end XPM images


/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( GuiApp )
////@end implement app


/*!
 * GuiApp type definition
 */

IMPLEMENT_CLASS( GuiApp, wxApp )


/*!
 * GuiApp event table definition
 */

BEGIN_EVENT_TABLE( GuiApp, wxApp )

////@begin GuiApp event table entries
////@end GuiApp event table entries

END_EVENT_TABLE()


/*!
 * Constructor for GuiApp
 */

GuiApp::GuiApp()
{
    Init();
}


/*!
 * Member initialisation
 */

void GuiApp::Init()
{
////@begin GuiApp member initialisation
////@end GuiApp member initialisation
}

/*!
 * Initialisation for GuiApp
 */

bool GuiApp::OnInit()
{    
////@begin GuiApp initialisation
    // Remove the comment markers above and below this block
    // to make permanent changes to the code.

#if wxUSE_XPM
    wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
    wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
    wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
    wxImage::AddHandler(new wxGIFHandler);
#endif
    frm_main* mainWindow = new frm_main(NULL);
    mainWindow->Show(true);
////@end GuiApp initialisation

    return true;
}


/*!
 * Cleanup for GuiApp
 */

int GuiApp::OnExit()
{    
////@begin GuiApp cleanup
    return wxApp::OnExit();
////@end GuiApp cleanup
}

