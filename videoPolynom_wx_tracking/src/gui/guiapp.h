/////////////////////////////////////////////////////////////////////////////
// Name:        guiapp.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     Thu 05 Aug 2010 09:59:54 BRT
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _GUIAPP_H_
#define _GUIAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "frm_main.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * GuiApp class declaration
 */

class GuiApp: public wxApp
{    
    DECLARE_CLASS( GuiApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    GuiApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin GuiApp event handler declarations
////@end GuiApp event handler declarations

////@begin GuiApp member function declarations
////@end GuiApp member function declarations

////@begin GuiApp member variables
////@end GuiApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(GuiApp)
////@end declare app

#endif
    // _GUIAPP_H_
