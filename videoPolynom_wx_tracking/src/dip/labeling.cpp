#include "labeling.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//---------------------------------------------------------------------------------//
dip::labeling::labeling(int width, int height)
{
    this->m_width = width;
    this->m_height = height;

    m_indexMap = (int*) calloc(m_width*m_height, sizeof (int));
}
//---------------------------------------------------------------------------------//
dip::labeling::~labeling()
{
     free(m_indexMap);
     m_listObject.clear();
}
//---------------------------------------------------------------------------------//
void dip::labeling::execute(unsigned char* imBin)
{
    //clear index map buffer
    register int* p;
    int sizeL = m_height*m_width;
    for(p=m_indexMap; p < m_indexMap+sizeL; p++)
        *p = 0;

    //clear object list
    m_listObject.clear();
    int index = 1;

    for(int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_width*3; j+=3)
        {
            //cada vez que entrar aqui, eh um novo objeto
            if((imBin[i*m_width*3 + j] == 0) && (m_indexMap[i*m_width + j/3]) == 0)
            {
                //push em um lista que deve estar no labeling
                object newObject;
		
                newObject.area = flood(i, j/3, index, imBin, &newObject.center, newObject.limits);
		newObject.index = index;

                m_listObject.push_back(newObject);
                index++;
            }
        }
     }

     /*
     int areaMin = 200;
     printf("\n\nObject index whose area is bigger than %d\n", areaMin);
     for(unsigned int k = 0; k < m_listObject.size(); k++)
     {
	  if(m_listObject.at(k).area > areaMin)
	  {
		printf("Indice: %d", m_listObject.at(k).index);
		printf("\t");
		printf("Area: %d", m_listObject.at(k).area);
		printf("\t");
		printf("X: %d", m_listObject.at(k).center.x);
		printf("\t");
		printf("Y: %d", m_listObject.at(k).center.y);
		printf("\n");
	  }
    }
    printf("\n\n\n");
    */
}
//---------------------------------------------------------------------------------//
int dip::labeling::flood(int i, int j, int index, unsigned char* imBin, point* center, point* limits)
{
    int area = 1;
    limits[0].x=limits[1].x=limits[2].x=limits[3].x=j;
    limits[0].y=limits[1].y=limits[2].y=limits[3].y=i;    
    
    unsigned long mediaX = j, mediaY = i;

    m_indexMap[(i)*m_width + j] = index;

    vector<point> m_listPoints;
    int pos = validate(i, j, imBin);

    if(pos == 0)
        return 1;

    point newPoint;
    newPoint.x = j;
    newPoint.y = i;
    m_listPoints.push_back(newPoint);
    
    if(pos == 1) {i--; (i<limits[2].y) ? (limits[2].x=j, limits[2].y=i) : 0; }
    if(pos == 2) {j++; (j>limits[1].x) ? (limits[1].x=j, limits[1].y=i) : 0; }
    if(pos == 3) {i++; (i>limits[3].y) ? (limits[3].x=j, limits[3].y=i) : 0; } 
    if(pos == 4) {j--; (j<limits[0].x) ? (limits[0].x=j, limits[0].y=i) : 0; } 

    while(m_listPoints.size() != 0)
    {
        m_indexMap[(i)*m_width + j] = index;

        pos = validate(i, j, imBin);

        point t = m_listPoints.back();
        if(t.x != j || t.y != i)
        {
            newPoint.x = j;
            newPoint.y = i;
            m_listPoints.push_back(newPoint);

            mediaX += j;
            mediaY += i;

            area++;
        }
	if(pos == 1) {i--; (i<limits[2].y) ? (limits[2].x=j, limits[2].y=i) : 0; }
	if(pos == 2) {j++; (j>limits[1].x) ? (limits[1].x=j, limits[1].y=i) : 0; }
	if(pos == 3) {i++; (i>limits[3].y) ? (limits[3].x=j, limits[3].y=i) : 0; } 
	if(pos == 4) {j--; (j<limits[0].x) ? (limits[0].x=j, limits[0].y=i) : 0; } 
        if(pos == 0)
        {
            m_listPoints.pop_back();
            point t = m_listPoints.back();
            i = t.y;
            j = t.x;
        }
    }
    center->x = mediaX/area;
    center->y = mediaY/area;

    return area;
}
//---------------------------------------------------------------------------------//
int dip::labeling::validate(int i, int j, unsigned char* imBin)
{
    if(i-1 >= 0)
        if(imBin[(i-1)*m_width*3 + j*3] == 0  &&  m_indexMap[(i-1)*m_width + j] == 0)
            return 1;

    if(j+1 < m_width)
        if(imBin[i*m_width*3 + (j+1)*3] == 0  &&  m_indexMap[i*m_width + (j+1)] == 0)
            return 2;

    if(i+1 < m_height)
       if(imBin[(i+1)*m_width*3 + j*3] == 0  &&  m_indexMap[(i+1)*m_width + j] == 0)
            return 3;

    if(j-1 >= 0)
       if(imBin[i*m_width*3 + (j-1)*3] == 0  &&  m_indexMap[i*m_width + (j-1)] == 0)
            return 4;
    return 0;
}
//---------------------------------------------------------------------------------//
int dip::labeling::numOfObjects()
{
    int numObjects = m_listObject.size();
    return numObjects;
}
//---------------------------------------------------------------------------------//
dip::object dip::labeling::getObject(int index)
{
    return m_listObject.at(index);
}
//---------------------------------------------------------------------------------//
