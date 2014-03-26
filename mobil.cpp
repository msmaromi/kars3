#include "mobil.h"
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

Mobil makeMobil(Point pos, int w, int h) {
	Mobil m;
	m.position = makePoint(pos.xFrame, pos.yFrame);
	m.width = (double) w;
	m.height = (double) h;

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
	Point p1 = makePoint(m.position.xFrame - m.width/4, m.position.yFrame + m.height);
	Point p2 = makePoint(m.position.xFrame + m.width/4, m.position.yFrame + m.height);
	Point p3 = makePoint(m.position.xFrame + m.width/2, m.position.yFrame);
	Point p4 = makePoint(m.position.xFrame - m.width/2, m.position.yFrame);

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

void runMobil(Mobil m, Frame frame, Lintasan l) {
	int endGame = 0;
	while(!endGame) {
		drawMobil(m, frame, GREEN);       
	    delay(111);
	    drawMobil(m, frame, BLACK);
	    m.position.yFrame -= 5;

	    if (m.position.yFrame < -222) {
	        m.position.yFrame = 100;
	        srand(time(NULL));
	        int randX = (2 * (rand() % 3) + 1) * 35;
	        m.position.xFrame = l.position.xFrame - l.topWidth/2 + randX;
	    }

	    if (kbhit()) {
	        char c = getch();
	        if (c == 's') {
	            endGame = 1;
	        } else if (c == 'M') { //key kanan
	            drawLintasan(l, frame, BLACK);
	            drawMobil(m, frame, BLACK);            
	            l.position.xFrame -= 170;   
	            m.position.xFrame -= 170;                                
	            drawLintasan(l, frame, RED);
	            drawMobil(m, frame, GREEN);
	        } else if (c == 'K') { //key kiri
	            drawLintasan(l, frame, BLACK);
	            drawMobil(m, frame, BLACK);
	            l.position.xFrame += 170;                
	            m.position.xFrame += 170;                        
	            drawLintasan(l, frame, RED);
	            drawMobil(m, frame, GREEN);
	        } 
	    }
	    
	    autoScaleMobil(m, l);
	    drawMobil(m, frame, GREEN);
	}	
}

void scaleMobil(Mobil &m, double scaling)
{
    m.width = scaling * m.width;
    m.height = scaling * m.height;
}

#include <stdio.h>

void autoScaleMobil(Mobil &m, Lintasan &l)
{
    int yPos = (m.position.yFrame - 78);
    if (yPos < 0)
        yPos *= -1;

    int widthLintasan = l.topWidth + yPos;

    m.width = widthLintasan / 3;
    m.height = 50 + (yPos/5);
}

