#include "cycImageHolderMaha.h"

//--------------------------------------------------------------------------------
void cycImageHolderMaha::Draw(wxBufferedPaintDC &dc)
{
   
	//call draw image in base class
	cycImageHolder::Draw(dc);
	
        if(showSeeds)
        {
            //show a WHITE point based on init and last points
            dc.SetPen(wxPen(wxColour(255,255,255), 2, wxSOLID));

            for(unsigned int i=0; i<reg; i++)
            {
                    wxPoint convInit = ImageToScreenCoordinates(point_list[i].x, point_list[i].y);
                    dc.DrawCircle(convInit.x, convInit.y, 2);
            }
        }
}
//--------------------------------------------------------------------------------
void cycImageHolderMaha::addCoordinate(wxPoint pt)
{
	point_list[reg] = pt;
	reg++;
	Refresh(true);
}
//--------------------------------------------------------------------------------
void cycImageHolderMaha::clearCoordinates()
{
	for(unsigned int i=0; i<reg; i++)
	{
		point_list[i].x = 0;
		point_list[i].y = 0;
	}
	reg =  0;
}
//--------------------------------------------------------------------------------
