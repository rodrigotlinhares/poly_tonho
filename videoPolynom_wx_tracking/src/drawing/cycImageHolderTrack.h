#ifndef CYCIMAGEHOLDERTRACK_H_
#define CYCIMAGEHOLDERTRACK_H_

#include <vector>
#include "imageView/cycImageHolder.h"
#include "dip/labeling.h"
#include "dip/trajectories.h"

//using std::vector;

//--------------------------------------------------------------------------------
//class IMAGE HOLDER
class cycImageHolderTrack : public cycImageHolder
{
private:
	//enable tracking selection ?
	bool m_enableTrSelection;

	//subscribing the motion method
	void OnLeftMouseButtonUp(wxMouseEvent& event);
	void OnMouseMotion(wxMouseEvent& event);
	wxPoint currPos;

	//current SELECTED index from the list, and the nearest object from mouse pointer
	int m_trackingIndex, m_nearestObjectIndex;

	vector<dip::object>* m_objectList;
	dip::trajectories* m_trajectories;    
  
public:
 cycImageHolderTrack(wxWindow* parent) : m_enableTrSelection(false), cycImageHolder(parent), m_trackingIndex(-1), m_nearestObjectIndex(-1), m_objectList(NULL), m_trajectories(NULL) { };
	~cycImageHolderTrack();
	void Draw(wxBufferedPaintDC &dc);

	//clear object list and trajectories
	void clearObjectList();
	void clearTrajectories();

	//set a lisf of objects to be drawn
	void setObjectList(vector<dip::object>* _objL);
	
	//set trajectories to be drawn
	void setTrajectories(dip::trajectories* _traject);

	//return the index of the current selected object from the list
	int getSelectedIndexObject();

	//enable tracking for user selection
	void enableTrackSelection(bool option=true);
};
//--------------------------------------------------------------------------------

#endif /*CYCIMAGEHOLDERGC_H_*/
