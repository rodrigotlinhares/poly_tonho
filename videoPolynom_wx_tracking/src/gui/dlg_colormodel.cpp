/////////////////////////////////////////////////////////////////////////////
// Name:        dlg_colormodel.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     Wed 29 Sep 2010 11:53:30 BRT
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

#include "dlg_colormodel.h"

////@begin XPM images
////@end XPM images


/*!
 * dlg_colorModel type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dlg_colorModel, wxDialog )


/*!
 * dlg_colorModel event table definition
 */

BEGIN_EVENT_TABLE( dlg_colorModel, wxDialog )

////@begin dlg_colorModel event table entries
////@end dlg_colorModel event table entries

END_EVENT_TABLE()


/*!
 * dlg_colorModel constructors
 */

dlg_colorModel::dlg_colorModel()
{
    Init();
}

dlg_colorModel::dlg_colorModel( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * dlg_colorModel creator
 */

bool dlg_colorModel::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlg_colorModel creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dlg_colorModel creation
    return true;
}


/*!
 * dlg_colorModel destructor
 */

dlg_colorModel::~dlg_colorModel()
{
////@begin dlg_colorModel destruction
////@end dlg_colorModel destruction
}


/*!
 * Member initialisation
 */

void dlg_colorModel::Init()
{
////@begin dlg_colorModel member initialisation
////@end dlg_colorModel member initialisation
}


/*!
 * Control creation for dlg_colorModel
 */

void dlg_colorModel::CreateControls()
{    
////@begin dlg_colorModel content construction
    dlg_colorModel* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxPanel* itemPanel3 = new wxPanel( itemDialog1, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    itemBoxSizer2->Add(itemPanel3, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    wxFlexGridSizer* itemFlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
    itemPanel3->SetSizer(itemFlexGridSizer4);

    wxCheckBox* itemCheckBox5 = new wxCheckBox( itemPanel3, ID_CHECKBOX_RGB, _("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
    itemCheckBox5->SetValue(false);
    itemFlexGridSizer4->Add(itemCheckBox5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxCheckBox* itemCheckBox6 = new wxCheckBox( itemPanel3, ID_CHECKBOX_HSV, _("HSV"), wxDefaultPosition, wxDefaultSize, 0 );
    itemCheckBox6->SetValue(false);
    itemFlexGridSizer4->Add(itemCheckBox6, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxCheckBox* itemCheckBox7 = new wxCheckBox( itemPanel3, ID_CHECKBOX_HSL, _("HSL"), wxDefaultPosition, wxDefaultSize, 0 );
    itemCheckBox7->SetValue(false);
    itemFlexGridSizer4->Add(itemCheckBox7, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxCheckBox* itemCheckBox8 = new wxCheckBox( itemPanel3, ID_CHECKBOX_LAB, _("CIE-Lab"), wxDefaultPosition, wxDefaultSize, 0 );
    itemCheckBox8->SetValue(false);
    itemFlexGridSizer4->Add(itemCheckBox8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton9 = new wxButton( itemPanel3, ID_BUTTON_OK, _("Confirm"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(itemButton9, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end dlg_colorModel content construction
}


/*!
 * Should we show tooltips?
 */

bool dlg_colorModel::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap dlg_colorModel::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dlg_colorModel bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dlg_colorModel bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon dlg_colorModel::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dlg_colorModel icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dlg_colorModel icon retrieval
}
