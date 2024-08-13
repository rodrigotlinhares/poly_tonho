// Name:        frm_main.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     Thu 05 Aug 2010 09:59:39 BRT
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
#include "dlg_topologicalmap.h"
#include "dlg_pattern.h"
#include "dlg_colormodel.h"
////@end includes

#include "frm_main.h"

////@begin XPM images
////@end XPM images

//-----------------------------------------------------------------------------
/*!
 * frm_main type definition
 */

IMPLEMENT_CLASS( frm_main, wxFrame )
//-----------------------------------------------------------------------------

/*!
 * frm_main event table definition
 */

BEGIN_EVENT_TABLE( frm_main, wxFrame )
//-----------------------------------------------------------------------------

////@begin frm_main event table entries
    EVT_PAINT( frm_main::OnPaint )
    EVT_IDLE( frm_main::OnIdle )

    EVT_MENU( ID_MENUITEM_OPENVIDEO, frm_main::OnMenuitemOpenvideoClick )

    EVT_MENU( ID_MENUITEM_OPENVIDEO_FILE, frm_main::OnMenuitemOpenvideoFileClick )

    EVT_MENU( ID_MENUITEM_EXIT, frm_main::OnMenuitemExitClick )

    EVT_MENU( ID_MENUITEM_TOPMAPS, frm_main::OnMenuitemTopmapsClick )

    EVT_MENU( ID_MENUITEM_PATTERN, frm_main::OnMenuitemPatternClick )

    EVT_MENU( ID_MENUITEM_COLORMODEL, frm_main::OnMenuitemColormodelClick )

    EVT_SPINCTRL( ID_SPINCTRL1, frm_main::OnSpinctrl1Updated )

    EVT_CHECKBOX( ID_CHECKBOX_FOLLOWME, frm_main::OnCheckboxFollowmeClick )

////@end frm_main event table entries

END_EVENT_TABLE()
//-----------------------------------------------------------------------------


/*!
 * frm_main constructors
 */

//-----------------------------------------------------------------------------
frm_main::frm_main()
{
    Init();
}

//-----------------------------------------------------------------------------
frm_main::frm_main( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
	
    m_isCapturing = false;
    m_deviceCapturing = 0;
    m_camModule = false;
    m_background = NULL;
    
    //polynomial Mahalanobis instance
    m_polyClassifier = new classifiers::polyMahalanobis();
    detector = new ViolaJonesDetector();
    
    //allocating similarity array
    int sizeN = 256*256*256;
    m_similarityArray = (double *) malloc(sizeN * sizeof(double));
    //memset(m_similarityArray, 1, 255*255*255*sizeof(double));
    
    this->resetSimilarityArray();
    
    //camera exibition
    m_camControl.resetPositions(3);
}

//-----------------------------------------------------------------------------
/*!
 * frm_main creator
 */

bool frm_main::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin frm_main creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();
////@end frm_main creation
    return true;
}


//-----------------------------------------------------------------------------
/*!
 * frm_main destructor
 */

frm_main::~frm_main()
{
////@begin frm_main destruction
////@end frm_main destruction

	if(m_imageHolder) 
		delete m_imageHolder;
	
	if(m_polyClassifier)
		free(m_polyClassifier);
	
	if(m_trackModule)
		delete(m_trackModule);
	
	if(m_background)
		delete(m_background);
	
	free(m_similarityArray);
}


//-----------------------------------------------------------------------------
/*!
 * Member initialisation
 */

void frm_main::Init()
{
////@begin frm_main member initialisation
    m_polyOrderToShow = NULL;
    m_expValue = NULL;
    m_tracking = NULL;
    m_showRegions = NULL;
    m_followme = NULL;
    m_flexGImage1 = NULL;
    m_flexGImage2 = NULL;
////@end frm_main member initialisation
}


//-----------------------------------------------------------------------------
/*!
 * Control creation for frm_main
 */

void frm_main::CreateControls()
{    
////@begin frm_main content construction
    frm_main* itemFrame1 = this;

    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* itemMenu3 = new wxMenu;
    itemMenu3->Append(ID_MENUITEM_OPENVIDEO, _("Open Video from Camera"), wxEmptyString, wxITEM_NORMAL);
    itemMenu3->Append(ID_MENUITEM_OPENVIDEO_FILE, _("Open Video from File"), wxEmptyString, wxITEM_NORMAL);
    itemMenu3->AppendSeparator();
    itemMenu3->Append(ID_MENUITEM_EXIT, _("Exit"), wxEmptyString, wxITEM_NORMAL);
    menuBar->Append(itemMenu3, _("File"));
    wxMenu* itemMenu8 = new wxMenu;
    itemMenu8->Append(ID_MENUITEM_TOPMAPS, _("Topological maps"), wxEmptyString, wxITEM_NORMAL);
    menuBar->Append(itemMenu8, _("View"));
    wxMenu* itemMenu10 = new wxMenu;
    itemMenu10->Append(ID_MENUITEM_PATTERN, _("Pattern selection"), wxEmptyString, wxITEM_NORMAL);
    itemMenu10->Append(ID_MENUITEM_COLORMODEL, _("Color model"), wxEmptyString, wxITEM_NORMAL);
    menuBar->Append(itemMenu10, _("Features"));
    itemFrame1->SetMenuBar(menuBar);

    wxFlexGridSizer* itemFlexGridSizer13 = new wxFlexGridSizer(2, 2, 0, 0);
    itemFrame1->SetSizer(itemFlexGridSizer13);

    wxFlexGridSizer* itemFlexGridSizer14 = new wxFlexGridSizer(3, 1, 0, 0);
    itemFlexGridSizer13->Add(itemFlexGridSizer14, 0, wxALIGN_LEFT|wxALIGN_TOP|wxTOP|wxBOTTOM, 5);

    wxPanel* itemPanel15 = new wxPanel( itemFrame1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    itemFlexGridSizer14->Add(itemPanel15, 0, wxALIGN_LEFT|wxGROW|wxLEFT|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer16 = new wxFlexGridSizer(2, 1, 0, 0);
    itemPanel15->SetSizer(itemFlexGridSizer16);

    wxFlexGridSizer* itemFlexGridSizer17 = new wxFlexGridSizer(2, 2, 0, 0);
    itemFlexGridSizer16->Add(itemFlexGridSizer17, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText18 = new wxStaticText( itemPanel15, wxID_STATIC, _("Order to show"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer17->Add(itemStaticText18, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_polyOrderToShow = new wxSpinCtrl( itemPanel15, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxSize(50, -1), wxSP_ARROW_KEYS, 1, 100, 1 );
    itemFlexGridSizer17->Add(m_polyOrderToShow, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText20 = new wxStaticText( itemPanel15, wxID_STATIC, _("Exponential Value"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer17->Add(itemStaticText20, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT, 5);

    m_expValue = new wxTextCtrl( itemPanel15, ID_TEXTCTRL, _("-1"), wxDefaultPosition, wxSize(50, -1), 0 );
    itemFlexGridSizer17->Add(m_expValue, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_tracking = new wxCheckBox( itemPanel15, ID_CHECKBOX1, _("object tracking"), wxDefaultPosition, wxDefaultSize, 0 );
    m_tracking->SetValue(false);
    itemFlexGridSizer17->Add(m_tracking, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP, 5);

    itemFlexGridSizer17->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer24 = new wxFlexGridSizer(0, 1, 0, 0);
    itemFlexGridSizer16->Add(itemFlexGridSizer24, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_showRegions = new wxCheckBox( itemPanel15, ID_CHECKBOX, _("show regions"), wxDefaultPosition, wxDefaultSize, 0 );
    m_showRegions->SetValue(false);
    itemFlexGridSizer24->Add(m_showRegions, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT|wxRIGHT, 5);

    m_followme = new wxCheckBox( itemPanel15, ID_CHECKBOX_FOLLOWME, _("follow me"), wxDefaultPosition, wxDefaultSize, 0 );
    m_followme->SetValue(false);
    itemFlexGridSizer24->Add(m_followme, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT|wxRIGHT, 5);

    wxBoxSizer* itemBoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer13->Add(itemBoxSizer27, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP|wxALL, 5);

    m_flexGImage1 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer27->Add(m_flexGImage1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_flexGImage2 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer27->Add(m_flexGImage2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end frm_main content construction

    //starting my m_imageHolder !
    m_imageHolder = new cycImageHolderTrack(this);
    m_flexGImage1->Add(m_imageHolder, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    m_imageHolder->SetScrollbars(1, 1, 0, 0);

    //m_imageHolder->setFunc_to_OnLeftMouseButtonUp(NULL);
    
    this->SetSize(500,400);
    this->Update();
}

//-----------------------------------------------------------------------------
/*!
 * wxEVT_PAINT event handler for ID_FRM_MAIN
 */

void frm_main::OnPaint( wxPaintEvent& event )
{
	wxPaintDC dc(this);    
	m_imageHolder->updateWindow();
}


//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_OPENVIDEO
 */

void frm_main::OnMenuitemOpenvideoClick( wxCommandEvent& event )
{
	m_isCapturing = !m_isCapturing;
	m_deviceCapturing = 1;
}


//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_EXIT
 */

void frm_main::OnMenuitemExitClick( wxCommandEvent& event )
{
	Close();
}


//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_PATTERN
 */

void frm_main::OnMenuitemPatternClick( wxCommandEvent& event )
{
	if(!m_isCapturing)
	{
		wxMessageBox(wxT("Video is not capturing..."));
		return;
	}
		
	  
	m_isCapturing = false;
	
	dlg_pattern* window = new dlg_pattern(this);
	window->setVideoDevice(m_camModule);
	int returnValue = window->ShowModal();
	
	if(returnValue == wxID_OK)	
	{
		int dim, size;
		pattern *currPattern = window->getPattern(dim, size);
		
		m_polyClassifier->setPattern(currPattern);
		m_polyClassifier->makeSpace(3);
		
		this->resetSimilarityArray();
	}
	window->Destroy();
	
	m_isCapturing = true;
}

//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL1
 */

void frm_main::OnSpinctrl1Updated( wxSpinEvent& event )
{
      if(!m_polyClassifier->hasPattern()) return;

      unsigned int maxOrder = m_polyClassifier->getMaxqOrder();
      unsigned int orderToShow = m_polyOrderToShow->GetValue();
      
      if(orderToShow > maxOrder)
	  m_polyOrderToShow->SetValue(maxOrder);
      else      
	  this->resetSimilarityArray();
}
//-----------------------------------------------------------------------------
/*!
 * Should we show tooltips?
 */

bool frm_main::ShowToolTips()
{
    return true;
}

//-----------------------------------------------------------------------------
/*!
 * Get bitmap resources
 */

wxBitmap frm_main::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin frm_main bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end frm_main bitmap retrieval
}

//-----------------------------------------------------------------------------
/*!
 * Get icon resources
 */

wxIcon frm_main::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin frm_main icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end frm_main icon retrieval
}


//-----------------------------------------------------------------------------
/*!
 * wxEVT_IDLE event handler for ID_FRM_MAIN
 */

void frm_main::OnIdle( wxIdleEvent& event )
{
	if(m_isCapturing)
	{
		//initialize the cam module if it is not yet ready
		if(!m_camModule)
		{
			m_camModule = new camModule();
		  
			bool status;
			if(m_deviceCapturing==1) status = m_camModule->initializeDevice(1, "0");
			if(m_deviceCapturing==2) status = m_camModule->initializeDevice(2, m_videoPath.ToAscii());
			
			if(!status)
			{
				wxMessageBox(wxT("Error on open video device"));
				m_isCapturing = false;
				return;
			}
			//initializing window size
			wxImage *img = new wxImage(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
			unsigned char *data = (unsigned char*) m_camModule->getRGBFrame();
			img->SetData(data);
			m_imageHolder->SetImage(img);
			m_imageHolder->SetSize(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
			
			this->SetSize(m_camModule->getSizeWidth()+220, m_camModule->getSizeHeight()+40);
			m_imageHolder->updateWindow();
			
			//initialize tracking module
			if(m_trackModule) delete m_trackModule;
			m_trackModule = new dip::tracking(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
			
			if(m_background) delete(m_background);
			m_background = new background(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
		}
		else
		{
			//showing the image on the imageholder
			unsigned char *data = (unsigned char*) m_camModule->getRGBFrame();
			
			if(m_polyClassifier->hasPattern())
			{
				//classify Frame in a specific order
				unsigned int orderToShow = m_polyOrderToShow->GetValue();
				unsigned int size=m_camModule->getSizeWidth()*m_camModule->getSizeHeight();
				unsigned char *simMap = this->evaluateToMap(data, size, 3, orderToShow);
				wxImage *img = new wxImage(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
				
				if(m_tracking->GetValue())
				{
					//*** extract elements from a current frame buffer
					//this class is responsible for the image enhancement and identify the objects of interest
					//on the scene
					dip::frameObjects mObjects(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
					simMap = mObjects.execute(simMap);
					vector<dip::object>* objList=mObjects.getObjectList();
					m_imageHolder->setObjectList(objList);

					//tracking module
					m_trackModule->addBinFrame(simMap);
					//dip::trajectories* mtrajectories = NULL;
					dip::trajectories* mtrajectories = m_trackModule->getTrajectories(10, -1);
					m_imageHolder->setTrajectories(mtrajectories);
					
					if(!m_showRegions->GetValue())
					{
						img->SetData(data);
						free(simMap);
					}
					else
					{
	  					img->SetData(simMap);
						free(data);
					}
					m_imageHolder->SetImage(img);
					
					//camera follow me, please !!!
					if(m_followme->GetValue())
					{
						wxPoint pt;
						int index = m_imageHolder->getSelectedIndexObject();
						if(index != -1)
						{
							if(mtrajectories->getTrajectory(index).size() > 0)
							{
								pt.x=mtrajectories->getTrajectory(index).at(0).x;
								pt.y=mtrajectories->getTrajectory(index).at(0).y;
								this->followme(pt);
							}
						}
						else
						{
							unsigned int trajNum = mtrajectories->getTrajectoriesNumber();
							for(unsigned int i=0; i<trajNum; i++)
							{
								pt.x+=mtrajectories->getTrajectory(i).at(0).x;
								pt.y+=mtrajectories->getTrajectory(i).at(0).y;
							}
							if(trajNum)
							{
							      pt.x/=trajNum;
							      pt.y/=trajNum;
							      this->followme(pt);
							}
						}
					}
				}
				else
				{
					m_followme->SetValue(false);
					m_imageHolder->enableTrackSelection(false);

					m_imageHolder->clearObjectList();
					m_imageHolder->clearTrajectories();
					
					for(unsigned int i=0; i<size*3; i++)
					    simMap[i]=((float)simMap[i]/255) * data[i];
					img->SetData(simMap);
					m_imageHolder->SetImage(img);

					free(data);
				}
			}
			else
			{
				//showing the result image
				wxImage *img = new wxImage(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
				img->SetData(data);
				m_imageHolder->SetImage(img);
				
				/*
				unsigned int size=m_camModule->getSizeWidth()*m_camModule->getSizeHeight();
				unsigned char *simMap = this->evaluateToBackGround(data, size);
				wxImage *img = new wxImage(m_camModule->getSizeWidth(), m_camModule->getSizeHeight());
				img->SetData(simMap);
				m_imageHolder->SetImage(img);
				*/
			}
			
			//if(DEBUG) 
			computeFPS();
		}
	}
}

//-----------------------------------------------------------------------------
void frm_main::computeFPS()
{
	static int frames = 0, overtime = 0, nextUpdate = 0;
	static float fps = 0;

	++frames;
	overtime = clock() - nextUpdate;
	
	if (overtime > 0) {
		fps = (double) frames / (float) (1 + (float) overtime / (float) CLOCKS_PER_SEC);
		PRINT_DEBUG("\nfps: %d", frames);
		frames = 0;
		nextUpdate = clock() + 1 * CLOCKS_PER_SEC;
	}
}

//-----------------------------------------------------------------------------
void frm_main::resetSimilarityArray()
{
      register double* p;
      int sizeN = 256*256*256;
      for(p=m_similarityArray; p<m_similarityArray+sizeN; p++)
	    *p = -1;
}
//-----------------------------------------------------------------------------
unsigned char* frm_main::evaluateToBackGround(unsigned char *data, unsigned int size)
{
      unsigned char* currFrame = (unsigned char*) calloc(size*3, sizeof(unsigned char));
      memcpy(currFrame, data, size*3*sizeof(unsigned char));
  
      m_background->addImage(data);
      unsigned char* back = m_background->getBackgroundModel();
      
      for(int i=0; i<size*3; i+=3)
      {
	    back[i]   = fabs(back[i]   - currFrame[i]);
	    back[i+1] = fabs(back[i+1] - currFrame[i+1]);
	    back[i+2] = fabs(back[i+2] - currFrame[i+2]);
	    //back[i]   = fabs(back[i]   - dataorigin[i]);
	    //back[i+1] = fabs(back[i+1] - dataorigin[i+1]);
	    //back[i+2] = fabs(back[i+2] - dataorigin[i+2]);
	    
	    /*
	    if((back[i]+back[i+1]+back[i+2]) > 50)
	    {
		  back[i]   = 255;
		  back[i+1] = 255;
		  back[i+2] = 255;
	    }
	    else
	    {
		  back[i]   = 0;
		  back[i+1] = 0;
		  back[i+2] = 0;
	    }*/
	    
      }
      free(currFrame);
      
      return back;
}
//-----------------------------------------------------------------------------
unsigned char* frm_main::evaluateToMap(unsigned char *data, unsigned int size, unsigned int dim, unsigned int order)
{
	//verifying in the map to a specified color vector
	//int maxOrder = m_polyClassifier->getMaxqOrder();
	unsigned char* res = (unsigned char*) calloc(size*3, sizeof(unsigned char));

	int r,g,b;
	double v;
	double *vI = (double*) calloc(3, sizeof(double));
	double expValue = atof(m_expValue->GetValue().ToAscii());
	
	for(register unsigned int i=0; i<size*3; i+=3)
	{
	    r=data[i];
	    g=data[i+1];
	    b=data[i+2];
	    
	    //v = m_similarityArray[r*g*256+b];
	    v = m_similarityArray[r*256*256+g*256+b];
	    if(v == -1)
	    {
		  vI[0] = data[i];
		  vI[1] = data[i+1];
		  vI[2] = data[i+2];
	    
		  double *intens = m_polyClassifier->evaluateToCenter(vI, 1, dim);
		  v=intens[order-1];
		  //m_similarityArray[r*g*256+b]=v;
		  m_similarityArray[r*256*256+g*256+b]=v;
		  
		  free(intens);
	    }
	  
	    double sim = exp(expValue * v);
	    
	    //thresholding
	    //if(sim > 0.5) sim = 1;
	    //else	  sim = 0;
	    
	    res[i]  = sim*255;
	    res[i+1]= sim*255;
	    res[i+2]= sim*255;
	}
	//m_isCapturing = false;
	free(vI);
	
	return res;
}
//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_COLORMODEL
 */

void frm_main::OnMenuitemColormodelClick( wxCommandEvent& event )
{
    dlg_colorModel* window = new dlg_colorModel(this);
    int returnValue = window->ShowModal();
    if(returnValue != wxID_OK)
	printf("color space bla bla bla");
    
    window->Destroy();
}
//-----------------------------------------------------------------------------

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_TOPMAPS
 */

void frm_main::OnMenuitemTopmapsClick( wxCommandEvent& event )
{
    if(!m_isCapturing)
    {
	wxMessageBox(wxT("Video is not capturing..."));
	return;
    }
    
    m_isCapturing = false;
    
    dlg_topologicalMap* window = new dlg_topologicalMap(this);
    window->setVideoDevice(m_camModule);
    window->ShowModal();
    window->Destroy();
    
    m_isCapturing = true;    
}

/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_OPENVIDEO_FILE
 */
//-----------------------------------------------------------------------------
void frm_main::OnMenuitemOpenvideoFileClick( wxCommandEvent& event )
{
	m_deviceCapturing = 2;
	
	wxFileDialog *openDlgFile = new wxFileDialog(this, wxT("Select a video"), wxT(""), wxT(""), wxT("Any file (*.*)|*.*"), wxOPEN);
	if(openDlgFile->ShowModal() == wxID_OK)
	{
		m_videoPath.clear();
		m_videoPath.append(openDlgFile->GetPath());
        }
	delete openDlgFile;
	m_isCapturing = !m_isCapturing;
}
//-----------------------------------------------------------------------------
void frm_main::followme(wxPoint ptRef)
{
	//printf("\nReference Point is %d %d\n", ptRef.x, ptRef.y);
	
	int W = m_imageHolder->getInitImage()->GetWidth();
	int H = m_imageHolder->getInitImage()->GetHeight();
	
	float de = sqrt( (ptRef.x-W/2)*(ptRef.x-W/2) + (ptRef.y-H/2)*(ptRef.y-H/2) );
	
	static int delay=0;
	
	if((de > 40)&&(delay==0))
	{
		int vx = (ptRef.x-W/2);
		m_camControl.setPanRel(-vx*1.75);
	}	
	if((de > 40)&&(delay==2))
	{
		int vy = (ptRef.y-H/2);
		m_camControl.setTiltRel(vy*1.75);
	}
	if(delay++ > 5) delay=0;
}
//-----------------------------------------------------------------------------
/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX2
 */
void frm_main::OnCheckboxFollowmeClick( wxCommandEvent& event )
{
	bool stageActive = m_followme->GetValue();
	if(stageActive && !m_tracking->GetValue())
	{
		m_followme->SetValue(false);
		return;
	}

	if(stageActive) 
		m_imageHolder->enableTrackSelection(true);
	else 
		m_imageHolder->enableTrackSelection(false);
}
//-----------------------------------------------------------------------------

