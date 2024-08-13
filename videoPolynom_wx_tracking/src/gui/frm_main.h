/////////////////////////////////////////////////////////////////////////////
// Name:        frm_main.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     Thu 05 Aug 2010 09:59:39 BRT
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _FRM_MAIN_H_
#define _FRM_MAIN_H_

/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/spinctrl.h"
////@end includes

#include "util/debug.h"
#include "drawing/cycImageHolderTrack.h"
#include "classifiers/polyMahalanobis.h"
#include "classifiers/background.h"
#include "detector/detector.h"
#include "camModule/camModule.h"
#include "camModule/logitechWrapper.h"

#include "dip/frameObjects.h"
#include "dip/tracking.h"


/*!
 * Forward declarations
 */

////@begin forward declarations
class wxSpinCtrl;
class wxFlexGridSizer;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_FRM_MAIN 10000
#define ID_MENUITEM_OPENVIDEO 10024
#define ID_MENUITEM_OPENVIDEO_FILE 10023
#define ID_MENUITEM_EXIT 10015
#define ID_MENU_VIEW 10021
#define ID_MENUITEM_TOPMAPS 10022
#define ID_MENUITEM_PATTERN 10001
#define ID_MENUITEM_COLORMODEL 10016
#define ID_PANEL2 10005
#define ID_SPINCTRL1 10020
#define ID_TEXTCTRL 10018
#define ID_CHECKBOX1 10012
#define ID_CHECKBOX 10026
#define ID_CHECKBOX_FOLLOWME 10029
#define SYMBOL_FRM_MAIN_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_FRM_MAIN_TITLE _("Polynomial Mahalanobis Classifier")
#define SYMBOL_FRM_MAIN_IDNAME ID_FRM_MAIN
#define SYMBOL_FRM_MAIN_SIZE wxSize(500, 400)
#define SYMBOL_FRM_MAIN_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * frm_main class declaration
 */

class frm_main: public wxFrame
{    
    DECLARE_CLASS( frm_main )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    frm_main();
    frm_main( wxWindow* parent, wxWindowID id = SYMBOL_FRM_MAIN_IDNAME, const wxString& caption = SYMBOL_FRM_MAIN_TITLE, const wxPoint& pos = SYMBOL_FRM_MAIN_POSITION, const wxSize& size = SYMBOL_FRM_MAIN_SIZE, long style = SYMBOL_FRM_MAIN_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_FRM_MAIN_IDNAME, const wxString& caption = SYMBOL_FRM_MAIN_TITLE, const wxPoint& pos = SYMBOL_FRM_MAIN_POSITION, const wxSize& size = SYMBOL_FRM_MAIN_SIZE, long style = SYMBOL_FRM_MAIN_STYLE );

    /// Destructor
    ~frm_main();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin frm_main event handler declarations

    /// wxEVT_PAINT event handler for ID_FRM_MAIN
    void OnPaint( wxPaintEvent& event );

    /// wxEVT_IDLE event handler for ID_FRM_MAIN
    void OnIdle( wxIdleEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_OPENVIDEO
    void OnMenuitemOpenvideoClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_OPENVIDEO_FILE
    void OnMenuitemOpenvideoFileClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_EXIT
    void OnMenuitemExitClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_TOPMAPS
    void OnMenuitemTopmapsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_PATTERN
    void OnMenuitemPatternClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_COLORMODEL
    void OnMenuitemColormodelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL1
    void OnSpinctrl1Updated( wxSpinEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX_FOLLOWME
    void OnCheckboxFollowmeClick( wxCommandEvent& event );

////@end frm_main event handler declarations

////@begin frm_main member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end frm_main member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin frm_main member variables
    wxSpinCtrl* m_polyOrderToShow;
    wxTextCtrl* m_expValue;
    wxCheckBox* m_tracking;
    wxCheckBox* m_showRegions;
    wxCheckBox* m_followme;
    wxFlexGridSizer* m_flexGImage1;
    wxFlexGridSizer* m_flexGImage2;
////@end frm_main member variables

private:
	//is capturing ?
	bool m_isCapturing;
	int m_deviceCapturing; 	//1 - camera    2 - file video
	wxString m_videoPath;  	//when m_deviceCapturing is 2
  
	//image Holder main class
	cycImageHolderTrack *m_imageHolder;
	
	//polynomial Mahalanobis instance
	classifiers::polyMahalanobis *m_polyClassifier;
	background *m_background;
  ViolaJonesDetector* detector;
	
	//similarity array
	double* m_similarityArray;
	
	//cam module member variable
	camModule* m_camModule;
	logitechWrapper m_camControl;
	
	//tracking module
	dip::tracking* m_trackModule;

private:
	void computeFPS();
	
	//evaluate to integer buffer
	unsigned char *evaluateToMap(unsigned char *data, unsigned int size, unsigned int dim, unsigned int order);
	unsigned char *evaluateToBackGround(unsigned char *data, unsigned int size);
	
	//reset array of similarity indexes
	void resetSimilarityArray();
	
	//follow me
	void followme(wxPoint ptRef);
};

#endif
    // _FRM_MAIN_H_
