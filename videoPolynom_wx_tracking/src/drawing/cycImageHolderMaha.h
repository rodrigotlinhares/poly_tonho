#ifndef CYCIMAGEHOLDERMAHA_H_
#define CYCIMAGEHOLDERMAHA_H_

#include "imageView/cycImageHolder.h"
//--------------------------------------------------------------------------------
//class IMAGE HOLDER - MAHA-MUMSHAH
class cycImageHolderMaha : public cycImageHolder
{
private:
	wxPoint point_list[10000];
	unsigned int reg;
	
public:
	cycImageHolderMaha(wxWindow* parent) : cycImageHolder(parent), reg(0), showSeeds(true) { };
	void Draw(wxBufferedPaintDC &dc);
	
	void addCoordinate(wxPoint pt);
	void clearCoordinates();
        
        //show the seeds over the image ?
        bool showSeeds;
};
//--------------------------------------------------------------------------------

#endif /*CYCIMAGEHOLDERGC_H_*/
