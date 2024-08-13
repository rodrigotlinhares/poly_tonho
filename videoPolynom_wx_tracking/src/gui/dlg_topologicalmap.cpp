/////////////////////////////////////////////////////////////////////////////
// Name:        dlg_topologicalmap.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     Wed 29 Sep 2010 13:56:53 BRT
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

#include "dlg_topologicalmap.h"

////@begin XPM images
////@end XPM images

//--------------------------------------------------------------------------------
/*!
 * dlg_topologicalMap type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dlg_topologicalMap, wxDialog )


/*!
 * dlg_topologicalMap event table definition
 */
//--------------------------------------------------------------------------------

BEGIN_EVENT_TABLE( dlg_topologicalMap, wxDialog )

////@begin dlg_topologicalMap event table entries
    EVT_IDLE( dlg_topologicalMap::OnIdle )

////@end dlg_topologicalMap event table entries

END_EVENT_TABLE()


//--------------------------------------------------------------------------------
/*!
 * dlg_topologicalMap constructors
 */

dlg_topologicalMap::dlg_topologicalMap()
{
    Init();
}

//--------------------------------------------------------------------------------
dlg_topologicalMap::dlg_topologicalMap( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
    
    //allocating similarity array
    //int sizeN = 256*256*256;
    //m_histogram = (int *) malloc(sizeN * sizeof(int));
    
    m_camModule = NULL;
}


/*!
 * dlg_topologicalMap creator
 */
//--------------------------------------------------------------------------------
bool dlg_topologicalMap::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlg_topologicalMap creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dlg_topologicalMap creation
    return true;
}


/*!
 * dlg_topologicalMap destructor
 */
//--------------------------------------------------------------------------------
dlg_topologicalMap::~dlg_topologicalMap()
{
////@begin dlg_topologicalMap destruction
////@end dlg_topologicalMap destruction

    //if(m_imageHolderRG) free(m_imageHolderRG);
    //if(m_imageHolderRB) free(m_imageHolderRB);
    //if(m_imageHolderGB) free(m_imageHolderGB);
    
    //if(m_imageHolder) free(m_imageHolder);
    
    //if(m_histogram) free(m_histogram);
}
//--------------------------------------------------------------------------------
/*!
 * Member initialisation
 */

void dlg_topologicalMap::Init()
{
////@begin dlg_topologicalMap member initialisation
    m_flexGImage1 = NULL;
    m_flexGImage2 = NULL;
    m_flexGImage3 = NULL;
    m_flexGImage4 = NULL;
////@end dlg_topologicalMap member initialisation
}

//--------------------------------------------------------------------------------
/*!
 * Control creation for dlg_topologicalMap
 */

void dlg_topologicalMap::CreateControls()
{    
////@begin dlg_topologicalMap content construction
    dlg_topologicalMap* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxFlexGridSizer* itemFlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer2->Add(itemFlexGridSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer3->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_flexGImage1 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer4->Add(m_flexGImage1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_flexGImage2 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer4->Add(m_flexGImage2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_flexGImage3 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer4->Add(m_flexGImage3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_flexGImage4 = new wxFlexGridSizer(2, 2, 0, 0);
    itemFlexGridSizer3->Add(m_flexGImage4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end dlg_topologicalMap content construction

    //starting my m_imageHolder !
    m_imageHolderRG = new cycImageHolderTopolMaps(this);
    m_imageHolderRB = new cycImageHolderTopolMaps(this);
    m_imageHolderGB = new cycImageHolderTopolMaps(this);
    m_imageHolder = new cycImageHolder(this);

    m_flexGImage1->Add(m_imageHolderRG, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    m_imageHolderRG->SetScrollbars(1, 1, 0, 0);
    
    m_flexGImage2->Add(m_imageHolderRB, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    m_imageHolderRB->SetScrollbars(1, 1, 0, 0);

    m_flexGImage3->Add(m_imageHolderGB, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    m_imageHolderGB->SetScrollbars(1, 1, 0, 0);
    
    m_flexGImage4->Add(m_imageHolder, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    m_imageHolder->SetScrollbars(1, 1, 0, 0);
    
    m_imageHolderRG->SetSize(256,256);
    m_imageHolderRB->SetSize(256,256);
    m_imageHolderGB->SetSize(256,256);
    m_imageHolder->SetSize(640,480);
    
    this->Update();
}

//--------------------------------------------------------------------------------
/*!
 * Should we show tooltips?
 */

bool dlg_topologicalMap::ShowToolTips()
{
    return true;
}

//--------------------------------------------------------------------------------
/*!
 * Get bitmap resources
 */

wxBitmap dlg_topologicalMap::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dlg_topologicalMap bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dlg_topologicalMap bitmap retrieval
}

//--------------------------------------------------------------------------------
/*!
 * Get icon resources
 */

wxIcon dlg_topologicalMap::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dlg_topologicalMap icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dlg_topologicalMap icon retrieval
}

//--------------------------------------------------------------------------------
void dlg_topologicalMap::setVideoDevice(camModule *_video)
{
    m_camModule = _video;
}
//--------------------------------------------------------------------------------
/*!
 * wxEVT_IDLE event handler for ID_DLG_TOPOLOGICALMAP
 */

void dlg_topologicalMap::OnIdle( wxIdleEvent& event )
{
    if(!m_camModule) return;
  
    //reseting the histogram
    this->resetHistogram();
    
    //computing the histogram
    unsigned char *data = (unsigned char*) m_camModule->getRGBFrame();
    
    //showing image	
    int W=m_camModule->getSizeWidth();
    int H=m_camModule->getSizeHeight();

    wxImage *img = new wxImage(W,H);
    img->SetData(data);
    m_imageHolder->SetImage(img);
    
    wxImage *RG = new wxImage(256,256);
    wxImage *RB = new wxImage(256,256);
    wxImage *GB = new wxImage(256,256);

    int size=W*H*3;
    int r,g,b;
    for(int i=0; i<size; i+=3)
    {
	r=data[i];
	g=data[i+1];
	b=data[i+2];
	
	//m_histogram[r*g*256+b]++;

	RG->GetData()[data[i]*256*3+data[i+1]*3]  =data[i];
	RG->GetData()[data[i]*256*3+data[i+1]*3+1]=data[i+1];
	RG->GetData()[data[i]*256*3+data[i+1]*3+2]=data[i+2];

	RB->GetData()[data[i]*256*3+data[i+2]*3]  =data[i];
	RB->GetData()[data[i]*256*3+data[i+2]*3+1]=data[i+1];
	RB->GetData()[data[i]*256*3+data[i+2]*3+2]=data[i+2];

	GB->GetData()[data[i+1]*256*3+data[i+2]*3]  =data[i];
	GB->GetData()[data[i+1]*256*3+data[i+2]*3+1]=data[i+1];
	GB->GetData()[data[i+1]*256*3+data[i+2]*3+2]=data[i+2];
    }
    
    m_imageHolderRG->SetImage(RG);
    m_imageHolderRB->SetImage(RB);
    m_imageHolderGB->SetImage(GB);    
}
//--------------------------------------------------------------------------------
void dlg_topologicalMap::resetHistogram()
{
      //register int *p;
      //int sizeN = 256*256*256;
      //for(p=m_histogram; p<m_histogram+sizeN; p++)
	//    *p = 0;
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
