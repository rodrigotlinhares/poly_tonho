#include "cycImageDraw.h"
//---------------------------------------------------------------------------------
void cycImageHolder::Draw(wxBufferedPaintDC &dc)  
{
	// only this in comment is need to show an image
	//dc.DrawRectangle(0,0, m_wndRawWidth, m_wndRawHeight);
	//dc.DrawBitmap(wxBitmap(*m_imageRaw), wxPoint((m_panMoving+0)->x, (m_panMoving+0)->y), false);

	//but, because the zooming process, we've a lost performance
	//only the rect into image is showed...
	//rect image raw

        //new image to copy scaled image
        if(m_zoomRatio != 1)
        {
            wxImage *buffImage = new wxImage(*m_imageInit);
            buffImage->Rescale(m_imageInit->GetWidth() * m_zoomRatio, m_imageInit->GetHeight() * m_zoomRatio);

            delete m_imageRaw;
            m_imageRaw = buffImage;
        }

	
	int panX = (m_panMoving+0)->x;
	int panY = (m_panMoving+0)->y;
	
	int x1, y1, x2, y2;
	int startX, startY;
	
	//width
	if(panX >= 0)
	{
		x1 = 0;
		x2 = m_wndRawWidth - panX;
		startX = panX;
	}
	else
	{
		x1 = panX * (-1);
		x2 = m_wndRawWidth;
		startX = 0;
	}
	
	//height
	if(panY >= 0)
	{
		y1 = 0;
		y2 = m_wndRawHeight - panY;
		startY = panY;
	}
	else
	{
		y1 = panY * (-1);
		y2 = m_wndRawHeight;
		startY = 0;
	}	
	
	//controll of ending image in m_wndRawHeight and m_wndRawWidth
	if(x1+x2 > m_imageRaw->GetWidth())
		x2 = m_imageRaw->GetWidth() - x1;
	
	if(y1+y2 > m_imageRaw->GetHeight())
		y2 = m_imageRaw->GetHeight() - y1;
	
	
	m_imageRawView = wxRect(x1, y1, x2, y2);
	wxImage rectImage = m_imageRaw->GetSubImage(m_imageRawView);
	
	//show image
	dc.DrawRectangle(0,0, m_wndRawWidth, m_wndRawHeight);
	dc.DrawBitmap(wxBitmap(rectImage), startX, startY, false);	 
}
//---------------------------------------------------------------------------------
void cycImageHolder::OnPaint(wxPaintEvent& event)
{
	if(!m_imageRaw) return;  
	
	wxBufferedPaintDC dc(this);
	DoPrepareDC(dc);

	this->Draw(dc);
}
//---------------------------------------------------------------------------------
void cycImageHolder::updateWindow()
{
	if(!m_imageRaw) return;  
	
	SetSize(m_wndRawWidth, m_wndRawHeight);	
	Refresh(false);
}
//---------------------------------------------------------------------------------



