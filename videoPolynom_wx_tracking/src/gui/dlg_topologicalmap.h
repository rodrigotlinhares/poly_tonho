/////////////////////////////////////////////////////////////////////////////
// Name:        dlg_topologicalmap.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     Wed 29 Sep 2010 13:56:53 BRT
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLG_TOPOLOGICALMAP_H_
#define _DLG_TOPOLOGICALMAP_H_


/*!
 * Includes
 */

////@begin includes
////@end includes

#include "camModule/camModule.h"
#include "drawing/cycImageHolderTopolMaps.h"


/*!
 * Forward declarations
 */

////@begin forward declarations
class wxFlexGridSizer;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DLG_TOPOLOGICALMAP 10019
#define SYMBOL_DLG_TOPOLOGICALMAP_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxDIALOG_MODAL|wxTAB_TRAVERSAL
#define SYMBOL_DLG_TOPOLOGICALMAP_TITLE _("Histogram and topological map viewer")
#define SYMBOL_DLG_TOPOLOGICALMAP_IDNAME ID_DLG_TOPOLOGICALMAP
#define SYMBOL_DLG_TOPOLOGICALMAP_SIZE wxSize(400, 300)
#define SYMBOL_DLG_TOPOLOGICALMAP_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * dlg_topologicalMap class declaration
 */

class dlg_topologicalMap: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( dlg_topologicalMap )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    dlg_topologicalMap();
    dlg_topologicalMap( wxWindow* parent, wxWindowID id = SYMBOL_DLG_TOPOLOGICALMAP_IDNAME, const wxString& caption = SYMBOL_DLG_TOPOLOGICALMAP_TITLE, const wxPoint& pos = SYMBOL_DLG_TOPOLOGICALMAP_POSITION, const wxSize& size = SYMBOL_DLG_TOPOLOGICALMAP_SIZE, long style = SYMBOL_DLG_TOPOLOGICALMAP_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DLG_TOPOLOGICALMAP_IDNAME, const wxString& caption = SYMBOL_DLG_TOPOLOGICALMAP_TITLE, const wxPoint& pos = SYMBOL_DLG_TOPOLOGICALMAP_POSITION, const wxSize& size = SYMBOL_DLG_TOPOLOGICALMAP_SIZE, long style = SYMBOL_DLG_TOPOLOGICALMAP_STYLE );

    /// Destructor
    ~dlg_topologicalMap();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin dlg_topologicalMap event handler declarations

    /// wxEVT_IDLE event handler for ID_DLG_TOPOLOGICALMAP
    void OnIdle( wxIdleEvent& event );

////@end dlg_topologicalMap event handler declarations

////@begin dlg_topologicalMap member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dlg_topologicalMap member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin dlg_topologicalMap member variables
    wxFlexGridSizer* m_flexGImage1;
    wxFlexGridSizer* m_flexGImage2;
    wxFlexGridSizer* m_flexGImage3;
    wxFlexGridSizer* m_flexGImage4;
////@end dlg_topologicalMap member variables

private:
    //reset array of similarity indexes
    void resetHistogram();

    //image Holder main class
    cycImageHolderTopolMaps *m_imageHolderRG;
    cycImageHolderTopolMaps *m_imageHolderRB;
    cycImageHolderTopolMaps *m_imageHolderGB;
    cycImageHolder *m_imageHolder;

    //video device from main form
    camModule *m_camModule;
    
    //similarity array
    //int *m_histogram;
    
    
	
public:
    void setVideoDevice(camModule *video);
    
};

#endif
    // _DLG_TOPOLOGICALMAP_H_
