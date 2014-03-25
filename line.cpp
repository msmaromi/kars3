//
//  line.c
//  
//
//  Created by Muhammad S Maromi on 2/17/14.
//
//

#include "line.h"
#include "math.h"

Line makeLine(Point *p1, Point *p2) {
    Line line;
    
    line.point1 = makePoint(p1->xFrame, p1->yFrame);
    line.point2 = makePoint(p2->xFrame, p2->yFrame);
    
    return line;
}

void drawLineDDA(Line *line, Frame *frame) {
    int xa,xb,ya,yb;
	//--------------
	xa= line->point1.xFrame;
	xb= line->point2.xFrame;
	ya= line->point1.yFrame;
	yb= line->point2.yFrame;
	//--------------
	int dx=xb-xa;
	int dy=yb-ya;
	int steps;
	int k;
	float xIncrement, yIncrement;
	float x=xa;
	float y=ya;

	if(abs(dx) > abs(dy)) steps = abs(dx);
	else steps = abs(dy);
	xIncrement = dx/(float) steps;
	yIncrement = dy/(float) steps;

	
	Point p = makePoint(x, y);
	drawPoint(&p, frame);

	for(k=0; k<steps;k++){
		x+=xIncrement;
		y+=yIncrement;
		p = makePoint(x, y);
		drawPoint(&p, frame);
	}
}
