#include "lintasan.h"

Lintasan makeLintasan(Point pos, int tw, int bw, int h) {
	Lintasan l;
	l.position = makePoint(pos.xFrame, pos.yFrame);
	l.topWidth = tw;
	l.bottomWidth = bw;
	l.height = h;

	return l;
}

/*
 	p1......p2


p4..............p3
*/

void drawLintasan(Lintasan l, Frame frame, int color) {
	Point p1 = makePoint(l.position.xFrame - l.topWidth/2, l.position.yFrame + l.height);
	Point p2 = makePoint(l.position.xFrame + l.topWidth/2, l.position.yFrame + l.height);
	Point p3 = makePoint(l.position.xFrame + l.bottomWidth/2, l.position.yFrame);
	Point p4 = makePoint(l.position.xFrame - l.bottomWidth/2, l.position.yFrame);

	Line line1 = makeLine(&p1, &p4);
	Line line2 = makeLine(&p2, &p3);
	
	drawLineDDA(&line1, &frame, color);
	drawLineDDA(&line2, &frame, color);
}