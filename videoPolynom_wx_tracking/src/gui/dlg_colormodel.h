/////////////////////////////////////////////////////////////////////////////
// Name:        dlg_colormodel.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     Wed 29 Sep 2010 11:53:30 BRT
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLG_COLORMODEL_H_
#define _DLG_COLORMODEL_H_


/*!
 * Includes
 */

////@begin includes
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
#define ID_DLG_COLORMODEL 10003
#define ID_PANEL 10006
#define ID_CHECKBOX_RGB 10007
#define ID_CHECKBOX_HSV 10008
#define ID_CHECKBOX_HSL 10009
#define ID_CHECKBOX_LAB 10011
#define ID_BUTTON_OK 10014
#define SYMBOL_DLG_COLORMODEL_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxDIALOG_MODAL|wxTAB_TRAVERSAL
#define SYMBOL_DLG_COLORMODEL_TITLE _("Color model selection")
#define SYMBOL_DLG_COLORMODEL_IDNAME ID_DLG_COLORMODEL
#define SYMBOL_DLG_COLORMODEL_SIZE wxSize(400, 300)
#define SYMBOL_DLG_COLORMODEL_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * dlg_colorModel class declaration
 */

class dlg_colorModel: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( dlg_colorModel )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    dlg_colorModel();
    dlg_colorModel( wxWindow* parent, wxWindowID id = SYMBOL_DLG_COLORMODEL_IDNAME, const wxString& caption = SYMBOL_DLG_COLORMODEL_TITLE, const wxPoint& pos = SYMBOL_DLG_COLORMODEL_POSITION, const wxSize& size = SYMBOL_DLG_COLORMODEL_SIZE, long style = SYMBOL_DLG_COLORMODEL_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DLG_COLORMODEL_IDNAME, const wxString& caption = SYMBOL_DLG_COLORMODEL_TITLE, const wxPoint& pos = SYMBOL_DLG_COLORMODEL_POSITION, const wxSize& size = SYMBOL_DLG_COLORMODEL_SIZE, long style = SYMBOL_DLG_COLORMODEL_STYLE );

    /// Destructor
    ~dlg_colorModel();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin dlg_colorModel event handler declarations

////@end dlg_colorModel event handler declarations

////@begin dlg_colorModel member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dlg_colorModel member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin dlg_colorModel member variables
////@end dlg_colorModel member variables
};

#endif
    // _DLG_COLORMODEL_H_
