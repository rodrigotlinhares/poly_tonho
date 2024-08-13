// Name:        dlg_pattern.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     Thu 05 Aug 2010 09:45:54 BRT
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

#include "dlg_pattern.h"

////@begin XPM images
////@end XPM images


/*!
 * dlg_pattern type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dlg_pattern, wxDialog )


/*!
 * dlg_pattern event table definition
 */

BEGIN_EVENT_TABLE( dlg_pattern, wxDialog )

////@begin dlg_pattern event table entries
    EVT_PAINT( dlg_pattern::OnPaint )
    EVT_IDLE( dlg_pattern::OnIdle )

    EVT_GRID_CELL_LEFT_CLICK( dlg_pattern::OnCellLeftClick )

    EVT_SPINCTRL( ID_SPINCTRL_GRIDSIZE, dlg_pattern::OnSpinctrlGridsizeUpdated )

    EVT_BUTTON( ID_BUTTON_PLAYVIDEO, dlg_pattern::OnButtonPlayvideoClick )

    EVT_BUTTON( ID_BUTTON_CLEARALL, dlg_pattern::OnButtonClearallClick )

    EVT_BUTTON( ID_BUTTON_CLEAR, dlg_pattern::OnButtonClearClick )

    EVT_BUTTON( ID_BUTTON_CONFIRM, dlg_pattern::OnButtonConfirmClick )

////@end dlg_pattern event table entries

END_EVENT_TABLE()


/*!
 * dlg_pattern constructors
 */

dlg_pattern::dlg_pattern()
{
    Init();
}

dlg_pattern::dlg_pattern( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
	
    m_camModule = NULL;
    m_isCapturing=true;
    m_playVideo->SetLabel(wxT("Stop Video"));
}


/*!
 * dlg_pattern creator
 */

bool dlg_pattern::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlg_pattern creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dlg_pattern creation
    return true;
}


/*!
 * dlg_pattern destructor
 */

dlg_pattern::~dlg_pattern()
{
////@begin dlg_pattern destruction
////@end dlg_pattern destruction
}


/*!
 * Member initialisation
 */

void dlg_pattern::Init()
{
////@begin dlg_pattern member initialisation
    m_colorgrid = NULL;
    m_gridSize = NULL;
    m_playVideo = NULL;
    m_flexGImage1 = NULL;
////@end dlg_pattern member initialisation
}


/*!
 * Control creation for dlg_pattern
 */

void dlg_pattern::CreateControls()
{    
////@begin dlg_pattern content construction
    dlg_pattern* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxFlexGridSizer* itemFlexGridSizer3 = new wxFlexGridSizer(3, 2, 0, 0);
    itemBoxSizer2->Add(itemFlexGridSizer3, 0, wxALIGN_LEFT|wxTOP|wxBOTTOM, 5);

    wxPanel* itemPanel4 = new wxPanel( itemDialog1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    itemFlexGridSizer3->Add(itemPanel4, 0, wxALIGN_CENTER_HORIZONTAL|wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer5 = new wxFlexGridSizer(1, 2, 0, 0);
    itemPanel4->SetSizer(itemFlexGridSizer5);

    wxFlexGridSizer* itemFlexGridSizer6 = new wxFlexGridSizer(1, 1, 0, 0);
    itemFlexGridSizer5->Add(itemFlexGridSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxGROW|wxLEFT|wxTOP, 5);

    m_colorgrid = new wxGrid( itemPanel4, ID_GRID, wxDefaultPosition, wxSize(150, 200), wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );
    m_colorgrid->SetDefaultColSize(40);
    m_colorgrid->SetDefaultRowSize(22);
    m_colorgrid->SetColLabelSize(22);
    m_colorgrid->SetRowLabelSize(22);
    m_colorgrid->CreateGrid(1, 2, wxGrid::wxGridSelectCells);
    itemFlexGridSizer6->Add(m_colorgrid, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer8 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer6->Add(itemFlexGridSizer8, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemPanel4, wxID_STATIC, _("Grid size (n x n)"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText9->SetFont(wxFont(10, wxSWISS, wxITALIC, wxNORMAL, false, wxT("Sans")));
    itemFlexGridSizer8->Add(itemStaticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_gridSize = new wxSpinCtrl( itemPanel4, ID_SPINCTRL_GRIDSIZE, _T("1"), wxDefaultPosition, wxSize(40, -1), wxSP_ARROW_KEYS, 1, 9, 1 );
    itemFlexGridSizer8->Add(m_gridSize, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer11 = new wxFlexGridSizer(2, 1, 0, 0);
    itemFlexGridSizer5->Add(itemFlexGridSizer11, 0, wxALIGN_LEFT|wxALIGN_TOP|wxBOTTOM, 5);

    m_playVideo = new wxButton( itemPanel4, ID_BUTTON_PLAYVIDEO, _("Play Video"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer11->Add(m_playVideo, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton13 = new wxButton( itemPanel4, ID_BUTTON_CLEARALL, _("Clear All"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer11->Add(itemButton13, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton14 = new wxButton( itemPanel4, ID_BUTTON_CLEAR, _("Clear Sel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer11->Add(itemButton14, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton15 = new wxButton( itemPanel4, ID_BUTTON_CONFIRM, _("Confirm"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer11->Add(itemButton15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxTextCtrl* itemTextCtrl16 = new wxTextCtrl( itemPanel4, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer11->Add(itemTextCtrl16, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_flexGImage1 = new wxFlexGridSizer(2, 2, 0, 0);
    itemFlexGridSizer3->Add(m_flexGImage1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP|wxALL, 5);

////@end dlg_pattern content construction
	//starting my m_imageHolder !
	m_imageHolder = new cycImageHolderMaha(this);
	m_flexGImage1->Add(m_imageHolder, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);
	m_imageHolder->SetScrollbars(1, 1, 0, 0);
	m_imageHolder->SetSize(640,480);
	
	m_imageHolder->setFunc_to_OnLeftMouseButtonUp(addSampling);	
    m_imageHolder->setFunc_to_OnMouseMotionLClick(addSampling);	
	
    this->SetSize(640,480);
    this->Update();
}


/*!
 * Should we show tooltips?
 */

bool dlg_pattern::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap dlg_pattern::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dlg_pattern bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dlg_pattern bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon dlg_pattern::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dlg_pattern icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dlg_pattern icon retrieval
}

void dlg_pattern::setVideoDevice(camModule *_video)
{
    m_camModule = _video;

    m_imageHolder->SetSize(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
    m_imageHolder->updateWindow();
    this->SetSize(m_camModule->getSizeWidth()+220, m_camModule->getSizeHeight()+40);
    
    this->Update();
}


/*!
 * wxEVT_PAINT event handler for ID_DLG_PATTERN
 */

void dlg_pattern::OnPaint( wxPaintEvent& event )
{
	wxPaintDC dc(this);    
	m_imageHolder->updateWindow();
}


/*!
 * wxEVT_IDLE event handler for ID_DLG_PATTERN
 */

void dlg_pattern::OnIdle( wxIdleEvent& event )
{
	if(m_camModule && m_isCapturing)
	{
		//showing the image on the imageholder
		wxImage *img = new wxImage(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
		unsigned char *data = (unsigned char*) m_camModule->getRGBFrame();
		
		img->SetData(data);
		m_imageHolder->SetImage(img);
	}
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_PLAYVIDEO
 */

void dlg_pattern::OnButtonPlayvideoClick( wxCommandEvent& event )
{
	m_isCapturing=!m_isCapturing;
	
	if(m_isCapturing)
		m_playVideo->SetLabel(wxT("Stop Video"));
	else
		m_playVideo->SetLabel(wxT("Play Video"));		
}

//-----------------------------------------------------------------------------
void dlg_pattern::addSampling(wxMouseEvent& event, wxWindow *_this)
{
    //point to Frm_Main 	
    dlg_pattern *frm = (dlg_pattern*) _this;
    
    //get point selection
    wxPoint pt = frm->m_imageHolder->ScreenToImageCoordinates(event.GetPosition().x, event.GetPosition().y);
    if( pt.x < 0 || 
        pt.y < 0 || 
        pt.x > frm->m_imageHolder->getInitImage()->GetWidth() || 
        pt.y > frm->m_imageHolder->getInitImage()->GetHeight())
        return;
    
    //get selected color
    int gridSize = frm->m_gridSize->GetValue();
    int bounds = (gridSize-1)/2;
    //printf("\n --- BOUNDS :  %d - %d \n", gridSize, bounds);

    for(int i=-bounds; i<bounds+1; i++)
    {
	for(int j=-bounds; j<bounds+1; j++)
	{
	    //printf("%d-%d", i, j);
	    
	    unsigned char r = frm->m_imageHolder->getInitImage()->GetRed(j+pt.x,i+pt.y);
	    unsigned char g = frm->m_imageHolder->getInitImage()->GetGreen(j+pt.x,i+pt.y);
	    unsigned char b = frm->m_imageHolder->getInitImage()->GetBlue(j+pt.x,i+pt.y);
	    wxColour c(r,g,b);	
	    
	    //define index
	    unsigned int index = frm->m_colorgrid->GetNumberRows()-1;
	    
	    frm->m_colorgrid->SelectRow(index);
	    
	    //set grid information and color
	    frm->m_colorgrid->SetCellBackgroundColour(index, 0, c);
	    frm->m_colorgrid->SetCellBackgroundColour(index, 1, c);
	    
	    wxString str;
	    str.sprintf(wxT("%d"), pt.x);
	    frm->m_colorgrid->SetCellValue(index, 0, str);
	    str.sprintf(wxT("%d"), pt.y);
	    frm->m_colorgrid->SetCellValue(index, 1, str);
	    
	    //add rows
	    frm->m_colorgrid->AppendRows();
	    
	    //print the coordinate samples
	    frm->m_imageHolder->addCoordinate(pt);	
	}
	//printf("\n");
    }
}
//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void dlg_pattern::OnButtonClearallClick( wxCommandEvent& event )
{
    m_colorgrid->DeleteRows(0, m_colorgrid->GetNumberRows()-1);
    m_imageHolder->clearCoordinates();
    m_imageHolder->updateWindow();
}
//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
 */
void dlg_pattern::OnButtonClearClick( wxCommandEvent& event )
{
    //m_ColorGrid->DeleteRows(0, m_ColorGrid->GetNumberRows()-1);
    if(m_selectedRow < m_colorgrid->GetNumberRows()-1)
    {
	m_colorgrid->DeleteRows(m_selectedRow, 1);
	m_colorgrid->Refresh();
    }
    m_selectedRow = 0;

    m_colorgrid->ClearSelection();
}
//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2
 */
void dlg_pattern::OnButtonConfirmClick( wxCommandEvent& event )
{
    unsigned int index = m_colorgrid->GetNumberRows()-1;
    (index > 0) ? wxDialog::EndModal(wxID_OK) : wxDialog::EndModal(wxID_CANCEL);
}
//-----------------------------------------------------------------------------
/*!
 * wxEVT_GRID_CELL_LEFT_CLICK event handler for ID_GRID
 */
void dlg_pattern::OnCellLeftClick( wxGridEvent& event )
{
    m_selectedRow = event.GetRow();

    if(m_selectedRow >= m_colorgrid->GetNumberRows()-1)
	m_selectedRow--;

    m_colorgrid->SelectRow(m_selectedRow);
}
//-----------------------------------------------------------------------------
pattern *dlg_pattern::getPattern(int &dim, int &size)
{
	dim = 3;
	size = m_colorgrid->GetNumberRows()-1;
	
	doubleVector *data = (doubleVector*) calloc(size, sizeof(doubleVector));
	point2D *coord = (point2D*) calloc(size, sizeof(point2D));
	
	for(int i=0; i<size; i++)
	{
		coord[i].x = atoi(m_colorgrid->GetCellValue(i,0).ToAscii());
		coord[i].y = atoi(m_colorgrid->GetCellValue(i,1).ToAscii());
		
		data[i].v = (double*) calloc(dim, sizeof(double));
		data[i].v[0] = m_colorgrid->GetCellBackgroundColour(i, 0).Red();
		data[i].v[1] = m_colorgrid->GetCellBackgroundColour(i, 0).Green();
		data[i].v[2] = m_colorgrid->GetCellBackgroundColour(i, 0).Blue();
	}	
	
	pattern *newPatt = new pattern(size, dim);
	newPatt->setData(data);
	newPatt->setCoordinates(coord);
	
	return newPatt;
}	
//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL_GRIDSIZE
 */

void dlg_pattern::OnSpinctrlGridsizeUpdated( wxSpinEvent& event )
{
    static int oldSize = 1;
    int currSize = m_gridSize->GetValue();
    
    if(currSize > oldSize) m_gridSize->SetValue(++currSize);
    if(currSize < oldSize) m_gridSize->SetValue(--currSize);
    
    oldSize = currSize;
}
//-----------------------------------------------------------------------------

