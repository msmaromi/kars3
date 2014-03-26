#include "mobil.h"
#include <dos.h>

Mobil makeMobil(Point pos, int w, int h) {
	Mobil m;
	m.position = makePoint(pos.xFrame, pos.yFrame);
	m.width = w;
	m.height = h;

	return m;
}

void fillMobil(Point P1, int fillColor, int boundaryColor, Frame f) {
	int current;

	Point Pa,Pb,Pc,Pd;
	Pa.xFrame = P1.xFrame;
	Pb.xFrame = P1.xFrame;
	Pc.xFrame = P1.xFrame;
	Pd.xFrame = P1.xFrame;
	Pa.yFrame = P1.yFrame;
	Pb.yFrame = P1.yFrame;
	Pc.yFrame = P1.yFrame;
	Pd.yFrame = P1.yFrame;

	current = getpixel(P1.xFrame,P1.yFrame);
	if((current != boundaryColor) && (current != fillColor)){
		delay(1);		
		drawPoint(&P1, &f, fillColor);
		Pa.xFrame++;
		fillMobil(Pa,fillColor, boundaryColor, f);
		Pb.yFrame++;
		fillMobil(Pb,fillColor, boundaryColor, f);
		Pc.xFrame--;
		fillMobil(Pc,fillColor, boundaryColor, f);
		Pd.yFrame--;
		fillMobil(Pd,fillColor, boundaryColor, f);
	}
}

/*
 	p1......p2
   .          .
  .            .
p4..............p3
*/

void drawMobil(Mobil m, Frame f, int color) {
	Point p1 = makePoint(m.position.xFrame - m.width/4, m.position.yFrame + m.height/4);
	Point p2 = makePoint(m.position.xFrame + m.width/4, m.position.yFrame + m.height/4);
	Point p3 = makePoint(m.position.xFrame + m.width/2, m.position.yFrame - m.height/4);
	Point p4 = makePoint(m.position.xFrame - m.width/2, m.position.yFrame - m.height/4);

	Line l1 = makeLine(&p1, &p2);
	Line l2 = makeLine(&p2, &p3);
	Line l3 = makeLine(&p3, &p4);
	Line l4 = makeLine(&p4, &p1);

	drawLineDDA(&l1, &f, color);
	drawLineDDA(&l2, &f, color);
	drawLineDDA(&l3, &f, color);
	drawLineDDA(&l4, &f, color);

	// fillMobil(m.position, color, color, f);
}