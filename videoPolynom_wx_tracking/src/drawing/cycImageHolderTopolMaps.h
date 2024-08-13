#ifndef CYCIMAGEHOLDERTOPOLMAPS_H_
#define CYCIMAGEHOLDERTOPOLMAPS_H_

#include "imageView/cycImageHolder.h"
//--------------------------------------------------------------------------------
//class IMAGE HOLDER - MAHA-MUMSHAH
class cycImageHolderTopolMaps : public cycImageHolder
{
public:
	cycImageHolderTopolMaps(wxWindow* parent) : cycImageHolder(parent) { };
	void Draw(wxBufferedPaintDC &dc);
};
//--------------------------------------------------------------------------------

#endif /*CYCIMAGEHOLDERGC_H_*/
