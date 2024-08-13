#ifndef _LABELING_H
#define	_LABELING_H

#include <iostream>
#include <vector>
using std::vector;

namespace dip
{

class point
{
public:
    int x, y;
};

class object
{
public:
    int index;
    int area;
    point center; 
    point limits[4];    //limits[0] is the most left point, [1] the most right, [2] the upper and [3] the bottom point
};

class labeling
{
private:
    //image size
    int m_width, m_height;
    int* m_indexMap;
    int flood(int i, int j, int index, unsigned char* imBin, point* center, point* limits);
    int validate(int i, int j, unsigned char* imBin);

    vector<object> m_listObject;

public:
    labeling(int width, int height);
    ~labeling();

    int numOfObjects();
    object getObject(int index);
    int* getIndexMap() const { return m_indexMap; };

    void execute(unsigned char *imBin);
};

};
#endif	/* _LABELING_H */
