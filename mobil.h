#ifndef MOBIL_H
#define MOBIL_H

#include <graphics.h>
#include "lintasan.h"

typedef struct
{
	Point position;
	int width;
	int height;
} Mobil;

Mobil makeMobil(Point pos, int w, int h);
void fillMobil(Point p, int fillColor, int boundaryColor, Frame f);
void drawMobil(Mobil m, Frame f, int color);
void runMobil(Mobil m, Frame frame, Lintasan l);

#endif