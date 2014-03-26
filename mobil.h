#ifndef MOBIL_H
#define MOBIL_H

#include <graphics.h>
#include "line.h"

typedef struct
{
	Point position;
	int width;
	int height;
} Mobil;

Mobil makeMobil(Point pos, int w, int h);
void fillMobil(Point p, int fillColor, int boundaryColor, Frame f);
void drawMobil(Mobil m, Frame f, int color);

#endif