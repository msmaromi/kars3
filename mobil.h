#ifndef MOBIL_H
#define MOBIL_H

#include <graphics.h>
#include "lintasan.h"

typedef struct
{
	Point position;
	double width;
	double height;
	Point boundary[500];
	int sizeBoundary;
} Mobil;

Mobil makeMobil(Point pos, double w, double h);
void fillMobil(Frame f, Point p, int fillColor, int boundaryColor, int plus);
void drawMobil(Mobil &m, Frame f, int color);
void drawMobilFromPoints(Mobil &m, Point &p1, Point &p2, Point &p3, Point &p4, Frame &f, int color);
void drawMobilWithRotAngle(Mobil &m, Frame f, int color, double angle);
void runMobil(Mobil listM[], Frame frame, Lintasan l, Mobil p);
void scaleMobil(Mobil &m, double scaling);
void autoScaleMobil(Mobil &m, Lintasan &l);
int isCollide(Mobil &m1, Mobil &m2);
void setBoundary(Mobil &m, Line &l);
void resetBoundary(Mobil &m);

#endif
