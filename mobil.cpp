#include "mobil.h"
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>

Mobil makeMobil(Point pos, int w, int h) {
	Mobil m;
	m.position = makePoint(pos.xFrame, pos.yFrame);
	m.width = (double) w;
	m.height = (double) h;	
	m.sizeBoundary = 0;

	return m;
}

void resetBoundary(Mobil &m) {
	m.sizeBoundary = 0;
}

void setBoundary(Mobil &m, Line &line) {	
	int xa,xb,ya,yb;
	//--------------
	xa= line.point1.xFrame;
	xb= line.point2.xFrame;
	ya= line.point1.yFrame;
	yb= line.point2.yFrame;
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
	m.boundary[m.sizeBoundary].xFrame = p.xFrame;	
	m.boundary[m.sizeBoundary].yFrame = p.yFrame;		
	m.sizeBoundary++;

	for(k=0; k<steps;k++){
		x+=xIncrement;
		y+=yIncrement;
		p = makePoint(x, y);
		m.boundary[m.sizeBoundary].xFrame = p.xFrame;
		m.boundary[m.sizeBoundary].yFrame = p.yFrame;		
		m.sizeBoundary++;
	}	

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

void drawMobilFromPoints(Mobil &m, Point &p1, Point &p2, Point &p3, Point &p4, Frame &f, int color)
{
	Line l1 = makeLine(&p1, &p2);
	Line l2 = makeLine(&p2, &p3);
	Line l3 = makeLine(&p3, &p4);
	Line l4 = makeLine(&p4, &p1);

	drawLineDDA(&l1, &f, color);
	drawLineDDA(&l2, &f, color);
	drawLineDDA(&l3, &f, color);
	drawLineDDA(&l4, &f, color);

	resetBoundary(m);

	setBoundary(m, l1);
	setBoundary(m, l2);
	setBoundary(m, l3);
	setBoundary(m, l4);
}

void drawMobil(Mobil &m, Frame f, int color) {
	Point p1 = makePoint(m.position.xFrame - m.width/4, m.position.yFrame + m.height);
	Point p2 = makePoint(m.position.xFrame + m.width/4, m.position.yFrame + m.height);
	Point p3 = makePoint(m.position.xFrame + m.width/2, m.position.yFrame);
	Point p4 = makePoint(m.position.xFrame - m.width/2, m.position.yFrame);

    drawMobilFromPoints(m, p1, p2, p3, p4, f, color);
	// fillMobil(m.position, color, color, f);
}

void drawMobilWithRotAngle(Mobil &m, Frame f, int color, double angle)
{
    // TODO
    angle = 0;
    
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    
    drawMobilFromPoints(m, p1, p2, p3, p4, f, color);
}

void runMobil(Mobil m, Frame frame, Lintasan l, Mobil p) {
	int stop = 0;
	srand(time(NULL));	
	while(!stop) {		
		// printf("%d,%d\n", m.position.xFrame, m.position.yFrame);
		drawLintasan(l, frame, RED);
		drawMobil(m, frame, GREEN);
		drawMobil(p, frame, GREEN);
	    // delay(1);	    
	    drawMobil(m, frame, BLACK);
	    double deltaMove = 1 + 4 * (300 - m.position.yFrame - l.position.yFrame) / 300;
	    m.position.yFrame -= deltaMove;

	    if (m.position.yFrame < -222) {
	        m.position.yFrame = 100;
	        
	        int randX = (rand() % 3) * 73;
	        m.position.xFrame = randX - l.topWidth/4;
	    }

	    if (m.position.xFrame - l.position.xFrame > 0) {
	    	m.position.xFrame = l.position.xFrame + (100 * (78 - m.position.yFrame)) / 300 + 73.333;
	    } else if (m.position.xFrame - l.position.xFrame < 0) {
	    	m.position.xFrame = l.position.xFrame - ((100 * (78 - m.position.yFrame)) / 300 + 73.333);
	    }	    

	    if (kbhit()) {
	        char c = getch();
	        if (c == 's') {
	            stop = 1;
	        } else if (c == 'M') { //key kanan
	        	if (l.position.xFrame > -173) {
	        		drawLintasan(l, frame, BLACK);
		            drawMobil(m, frame, BLACK);          
		            l.position.xFrame -= 44;	            
		            m.position.xFrame -= 44;
	        	}	                                            	           
	        } else if (c == 'K') { //key kiri
	        	if (l.position.xFrame < 173) {
	        		drawLintasan(l, frame, BLACK);
		            drawMobil(m, frame, BLACK);
		            l.position.xFrame += 44;                
		            m.position.xFrame += 44;
	        	}	              	           
	        } 
	    }
	    
	    autoScaleMobil(m, l);
	    drawMobil(m, frame, GREEN);	    

	    if(isCollide(m, p)) {
	    	stop = 1;
	    	drawMobil(m, frame, BLACK);
	    	drawMobil(p, frame, GREEN);
	    	printf("tabrakan!\n");	    	
	    }
	}	
}

void scaleMobil(Mobil &m, double scaling)
{
    m.width = scaling * m.width;
    m.height = scaling * m.height;
}

void autoScaleMobil(Mobil &m, Lintasan &l)
{
    int yPos = (m.position.yFrame - 78);
    if (yPos < 0)
        yPos *= -1;

    int widthLintasan = l.topWidth + yPos;

    m.width = widthLintasan / 3;
    m.height = 50 + (yPos/5);
}

int isCollide(Mobil &m1, Mobil &m2) {		
	for(int i = 0; i < m1.sizeBoundary; i++) {
		for(int j = 0; j < m2.sizeBoundary; j++) {			
			if(m1.boundary[i].xFrame == m2.boundary[j].xFrame && m1.boundary[i].yFrame == m2.boundary[j].yFrame)
				return 1;
		}
	}
	return 0;
}
