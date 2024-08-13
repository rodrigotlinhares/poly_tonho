/////////////////////////////////////////////////////////////////////////////
// Name:        dlg_pattern.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     Thu 05 Aug 2010 09:45:54 BRT
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLG_PATTERN_H_
#define _DLG_PATTERN_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/grid.h"
#include "wx/spinctrl.h"
////@end includes

#include "drawing/cycImageHolderMaha.h"
#include "camModule/camModule.h"
#include "classifiers/pattern.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxGrid;
class wxSpinCtrl;
class wxFlexGridSizer;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DLG_PATTERN 10013
#define ID_PANEL1 10004
#define ID_GRID 10010
#define ID_SPINCTRL_GRIDSIZE 10017
#define ID_BUTTON_PLAYVIDEO 10002
#define ID_BUTTON_CLEARALL 10025
#define ID_BUTTON_CLEAR 10027
#define ID_BUTTON_CONFIRM 10028
#define ID_TEXTCTRL1 10026
#define SYMBOL_DLG_PATTERN_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxDIALOG_MODAL|wxTAB_TRAVERSAL
#define SYMBOL_DLG_PATTERN_TITLE _("Pattern selection")
#define SYMBOL_DLG_PATTERN_IDNAME ID_DLG_PATTERN
#define SYMBOL_DLG_PATTERN_SIZE wxSize(400, 300)
#define SYMBOL_DLG_PATTERN_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * dlg_pattern class declaration
 */

class dlg_pattern: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( dlg_pattern )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    dlg_pattern();
    dlg_pattern( wxWindow* parent, wxWindowID id = SYMBOL_DLG_PATTERN_IDNAME, const wxString& caption = SYMBOL_DLG_PATTERN_TITLE, const wxPoint& pos = SYMBOL_DLG_PATTERN_POSITION, const wxSize& size = SYMBOL_DLG_PATTERN_SIZE, long style = SYMBOL_DLG_PATTERN_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DLG_PATTERN_IDNAME, const wxString& caption = SYMBOL_DLG_PATTERN_TITLE, const wxPoint& pos = SYMBOL_DLG_PATTERN_POSITION, const wxSize& size = SYMBOL_DLG_PATTERN_SIZE, long style = SYMBOL_DLG_PATTERN_STYLE );

    /// Destructor
    ~dlg_pattern();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin dlg_pattern event handler declarations

    /// wxEVT_PAINT event handler for ID_DLG_PATTERN
    void OnPaint( wxPaintEvent& event );

    /// wxEVT_IDLE event handler for ID_DLG_PATTERN
    void OnIdle( wxIdleEvent& event );

    /// wxEVT_GRID_CELL_LEFT_CLICK event handler for ID_GRID
    void OnCellLeftClick( wxGridEvent& event );

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL_GRIDSIZE
    void OnSpinctrlGridsizeUpdated( wxSpinEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_PLAYVIDEO
    void OnButtonPlayvideoClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CLEARALL
    void OnButtonClearallClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CLEAR
    void OnButtonClearClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CONFIRM
    void OnButtonConfirmClick( wxCommandEvent& event );

////@end dlg_pattern event handler declarations

////@begin dlg_pattern member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dlg_pattern member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin dlg_pattern member variables
    wxGrid* m_colorgrid;
    wxSpinCtrl* m_gridSize;
    wxButton* m_playVideo;
    wxFlexGridSizer* m_flexGImage1;
////@end dlg_pattern member variables
private:
    //is capturing ?
    bool m_isCapturing;
    
    //video device from main form
    camModule *m_camModule;
    
    //image Holder main class
    cycImageHolderMaha *m_imageHolder;
    
    //selected rown
    int m_selectedRow;
	
public:
	void setVideoDevice(camModule *video);

	//static function for image events
    static void addSampling(wxMouseEvent& event, wxWindow *_this);
	
	pattern *getPattern(int &dim, int &size);
};

#endif
    // _DLG_PATTERN_H_
