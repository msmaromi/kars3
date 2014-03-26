
#ifndef LINTASAN_H
#define LINTASAN_H

#include "line.h"

typedef struct 
{
	Point position;
	int topWidth;
	int bottomWidth;
	int height;	
} Lintasan;

Lintasan makeLintasan(Point pos, int tw, int bw, int h);
void drawLintasan(Lintasan l, Frame frame, int color);

#endif