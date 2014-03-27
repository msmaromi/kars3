#ifndef MOBIL_H
#define MOBIL_H

#include <graphics.h>
#include "lintasan.h"

typedef struct
{
	Point position;
	double width;
	double height;
} Mobil;

Mobil makeMobil(Point pos, int w, int h);
void fillMobil(Point p, int fillColor, int boundaryColor, Frame f);
void drawMobil(Mobil m, Frame f, int color);
void runMobil(Mobil m, Frame frame, Lintasan l, Mobil p);
void scaleMobil(Mobil &m, double scaling);
void autoScaleMobil(Mobil &m, Lintasan &l);

#endif
