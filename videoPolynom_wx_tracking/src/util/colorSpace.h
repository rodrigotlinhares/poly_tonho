/* 
 * File:   colorSpace.h
 * Author: asobieranski
 *
 * Created on September 11, 2008, 1:11 PM
 */

#ifndef _COLORSPACE_H
#define	_COLORSPACE_H

#include <cmath>
#include <algorithm>

/*
 * Types and definitions
 */

typedef unsigned char pixelvalue;

struct illuminant {
  illuminant(double _x,double _y,double _z) {x=_x; y=_y; z=_z;};

  double x, y, z;
};

namespace observer2 {
  const illuminant A(109.850,100,35.585);
  const illuminant C(98.074,100,118.232);
  const illuminant D50(96.422,100,82.521);
  const illuminant D55(95.682,100,92.149);
  const illuminant D65(95.047,100,108.883);
  const illuminant D75(94.972,100,122.638);
  const illuminant F2(99.187,100,67.395);
  const illuminant F7(95.044,100,108.755);
  const illuminant F11(100.966,100,64.370);
};

namespace observer10 {
  const illuminant A(111.144,100,35.200);
  const illuminant C(97.285,100,116.145);
  const illuminant D50(96.720,100,81.427);
  const illuminant D55(95.799,100,90.926);
  const illuminant D65(94.811,100,107.304);
  const illuminant D75(94.416,100,120.641);
  const illuminant F2(103.280,100,69.026);
  const illuminant F7(95.792,100,107.687);
  const illuminant F11(103.866,100,65.627);
};

namespace colorspace {    
  int rgbtoxyz(const pixelvalue r, const pixelvalue g, const pixelvalue b,
			 double& x, double& y, double& z);
  int rgbtohsv(const pixelvalue r, const pixelvalue g, const pixelvalue b,
        double& h, double& s, double& v);
  int xyztorgb(const double x, const double y, const double z,
		      pixelvalue& r, pixelvalue& g, pixelvalue& b);
  // HSL
  int rgbtohsl(const pixelvalue r, const pixelvalue g, const pixelvalue b,
		      double& h, double& s, double& l);
  int hsltorgb(const double h, const double s, const double l,
		      pixelvalue& r, pixelvalue& g, pixelvalue& b);
  // HSV
  int rgbtohsv(const pixelvalue r, const pixelvalue g, const pixelvalue b,
		      double& h, double& s, double& v);
  int hsvtorgb(const double h, const double s, const double v,
		      pixelvalue& r, pixelvalue& g, pixelvalue& b);
  // CIE L*AB
  int xyztolab(const double x, const double y, const double z,
		      double& l, double& a, double& b);
  int labtoxyz(const double l, const double a, const double b,
		      double& x, double& y, double& z);
  int rgbtolab(const pixelvalue r, const pixelvalue g, const pixelvalue b,
		      double& l, double& a, double& _b);
  int labtorgb(const double l, const double a, const double _b,
		      pixelvalue& r, pixelvalue& g, pixelvalue& b);
  // CIE L*CH
  int labtolch(const double _l, const double a, const double b,
		      double& l, double& c, double& h);
  int lchtolab(const double l, const double c, const double h,
		      double& _l, double& a, double& b);
  int rgbtolch(const pixelvalue r, const pixelvalue g, const pixelvalue b,
		      double& l, double& c, double& h);
  int lchtorgb(const double l, const double c, const double h,
		      pixelvalue& r, pixelvalue& g, pixelvalue& b);
  // CIE L*UV
  int xyztoluv(const double x, const double y, const double z,
		      double& l, double& u, double& v);
  int luvtoxyz(const double l, const double u, const double v,
		      double& x, double& y, double& z);
  int rgbtoluv(const pixelvalue r, const pixelvalue g, const pixelvalue b,
		      double& l, double& u, double& v);
  int luvtorgb(const double l, const double u, const double v,
		      pixelvalue& r, pixelvalue& g, pixelvalue& b);    

}


#endif	/* _COLORSPACE_H */

