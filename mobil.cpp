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

// void fillMobil(Point P, int fillColor, int boundaryColor, Frame f) {
// 	int ListPointX[10000];
// 	int ListPointY[10000];
// 	int current,counter;
// 	int currentW,currentE;
// 	int wXDos, wYDos, eXDos, eYDos, tempXDos, tempYDos;

// 	counter = 0;
	
// 	for(int i=0;i<1000;i++){
// 		ListPointX[i] = -2;
// 		ListPointY[i] = -3;
// 	}

// 	int pXDos = getXDos(&f, P.xFrame);
// 	int pYDos = getYDos(&f, P.yFrame);
	
// 	int ppXDos = pXDos;
// 	int ppYDos = pYDos;
// 	if(ListPointX[counter] == -2){		
// 		current = getpixel(P.xFrame, P.yFrame);		
// 		if(current != boundaryColor && current != fillColor){
// 			ListPointX[counter] = ppXDos;
// 			ListPointY[counter] = ppYDos;	
// 			while(ListPointX[counter]  > 0){
// 				tempXDos = ListPointX[counter];
// 				tempYDos = ListPointY[counter];
// 				ListPointX[counter] = -2;
// 				ListPointY[counter] = -3;
// 				// printf(" %d&%d||%d %d ",ListPointX[counter],ListPointY[counter],temp.xFrame, temp.yFrame);
// 				current = getpixel(tempXDos, tempYDos);
// 				if(((current != boundaryColor) && (current != fillColor) && (tempXDos!=-1)) || counter ==0){
// 					//geser kanan dan kiri
// 					wXDos = tempXDos+1;
// 					//printf(" %d", W.xFrame);
// 					eXDos = tempXDos;
// 					wYDos = tempYDos;
// 					eYDos = tempYDos;
// 					currentW = getpixel(wXDos, wYDos);
// 					currentE = getpixel(eXDos, eYDos);					
					
// 					int j=counter;
				
// 					while(currentW != boundaryColor && currentW != fillColor){
// 						putpixel(wXDos,wYDos,fillColor);						
// 						if(getpixel(wXDos, wYDos+1) != boundaryColor && getpixel(wXDos, wYDos+1) != fillColor){
// 							ppXDos = wXDos;
// 							ppYDos = wYDos+1;
// 							ListPointX[j+1] = ppXDos;
// 							ListPointY[j+1] = ppYDos;
// 							j++;
// 						}
// 						if(getpixel(wXDos, wYDos-1) != boundaryColor && getpixel(wXDos , wYDos-1) != fillColor){
// 							ppXDos = wXDos;
// 							ppYDos = wYDos-1;
// 							ListPointX[j+1] =ppXDos;
// 							ListPointY[j+1]= ppYDos;
// 							j++;
// 						}
// 						wXDos ++; //geser kanan
// 						currentW = getpixel(wXDos, wYDos);				
// 						//getch();
// 					}					

// 					while(currentE != boundaryColor && currentE != fillColor){						
// 						putpixel(eXDos, eYDos, fillColor);						
// 						if(getpixel(eXDos, eYDos + 1) != boundaryColor && getpixel(eXDos, eYDos + 1) != fillColor){
// 							ppXDos = eXDos;
// 							ppYDos = eYDos + 1;
// 							ListPointX[j+1] = ppXDos;
// 							ListPointY[j+1] = ppYDos;	
// 							j++;
// 						}
// 						if(getpixel(eXDos , eYDos - 1) != boundaryColor && getpixel(eXDos , eYDos -1) != fillColor){
// 							ppXDos = eXDos;
// 							ppYDos = eYDos-1;
// 							ListPointX[j+1] = ppXDos;
// 							ListPointY[j+1] = ppYDos;
// 							j++;
// 						}
// 						eXDos--; //geser kiri
// 						currentE = getpixel(eXDos, eYDos);
// 					}
// 				}
// 				counter ++;
// 			}				
// 		}
// 	}
// }

void fillMobil(Frame f, Point P, int fillColor, int boundaryColor, int plus) {
	int ListPointX[10000];
	int ListPointY[10000];
	int current,counter;
	int currentW,currentE;
	int wXDos, wYDos, eXDos, eYDos, tempXDos, tempYDos;

	counter = 0;
	
	for(int i=0;i<1000;i++){
		ListPointX[i] = -2;
		ListPointY[i] = -3;
	}

	int pXDos = getXDos(&f, P.xFrame);
	int pYDos = getYDos(&f, P.yFrame);
	
	int ppXDos = pXDos;
	int ppYDos = pYDos;
	if(ListPointX[counter] == -2){			
		current = getpixel(pXDos, pYDos);		
		// printf("%d : %d : %d\n", current, boundaryColor, fillColor);		
		if(current != boundaryColor && current != fillColor){			
			ListPointX[counter] = ppXDos;
			ListPointY[counter] = ppYDos;	
			while(ListPointX[counter]  > 0){
				tempXDos = ListPointX[counter];
				tempYDos = ListPointY[counter];
				ListPointX[counter] = -2;
				ListPointY[counter] = -3;
				// printf(" %d&%d||%d %d ",ListPointX[counter],ListPointY[counter],temp.xFrame, temp.yFrame);
				current = getpixel(tempXDos, tempYDos);
				if(((current != boundaryColor) && (current != fillColor) && (tempXDos!=-1)) || counter ==0){
					//geser kanan dan kiri
					wXDos = tempXDos+1;					
					eXDos = tempXDos;
					wYDos = tempYDos;
					eYDos = tempYDos;
					currentW = getpixel(wXDos, wYDos);
					// currentE = getpixel(eXDos, eYDos);					
					currentE = current;
					
					int j=counter;
				
					while(currentW != boundaryColor && currentW != fillColor){
						putpixel(wXDos,wYDos,fillColor);	
						int pixelW = getpixel(wXDos, wYDos+1);
						if(pixelW != boundaryColor && pixelW != fillColor){
							ppXDos = wXDos;
							ppYDos = wYDos+1;
							ListPointX[j+1] = ppXDos;
							ListPointY[j+1] = ppYDos;
							j++;
						} else if((pixelW == boundaryColor) && plus){
							putpixel(wXDos, wYDos+1,fillColor);
						}

						pixelW = getpixel(wXDos, wYDos-1);
						if(pixelW != boundaryColor && pixelW != fillColor){
							ppXDos = wXDos;
							ppYDos = wYDos-1;
							ListPointX[j+1] =ppXDos;
							ListPointY[j+1]= ppYDos;
							j++;
						} else if((pixelW == boundaryColor) && plus){
							putpixel(wXDos, wYDos-1,fillColor);
						}

						wXDos ++; //geser kanan
						currentW = getpixel(wXDos, wYDos);				
						//getch();
					}	

					if((currentW == boundaryColor) && plus){
						putpixel(wXDos,wYDos,fillColor);
					}				

					while(currentE != boundaryColor && currentE != fillColor){						
						putpixel(eXDos, eYDos, fillColor);	
						int pixelE = getpixel(eXDos, eYDos + 1);					
						if(pixelE != boundaryColor && pixelE != fillColor){
							ppXDos = eXDos;
							ppYDos = eYDos + 1;
							ListPointX[j+1] = ppXDos;
							ListPointY[j+1] = ppYDos;	
							j++;
						} else if((pixelE == boundaryColor) && plus){
							putpixel(eXDos, eYDos+1,fillColor);
						}

						pixelE = getpixel(eXDos , eYDos - 1);
						if(pixelE != boundaryColor && pixelE != fillColor){
							ppXDos = eXDos;
							ppYDos = eYDos-1;
							ListPointX[j+1] = ppXDos;
							ListPointY[j+1] = ppYDos;
							j++;
						} else if((pixelE == boundaryColor) && plus){
							putpixel(eXDos, eYDos-1,fillColor);
						}

						eXDos--; //geser kiri
						currentE = getpixel(eXDos, eYDos);
					}

					if((currentE == boundaryColor) && plus){
						putpixel(eXDos,eYDos,fillColor);
					}
				} else if((current == boundaryColor) && plus){
					putpixel(tempXDos,tempYDos, fillColor);					
				}

				counter ++;
			}				
		}
	}
}

/*
 	p1......p2
   .          .
  .            .
p4..............p3
*/

void drawMobil(Mobil &m, Frame f, int color) {
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

	// Point center = makePoint(m.position.xFrame, m.position.yFrame + m.height/2);
	
	// if(color == BLACK) {		
	// 	fillMobil(f, center, color, color, 1);
	// }
	// else
	// 	fillMobil(f, center, color, color, 0);

	resetBoundary(m);
	setBoundary(m, l1);
	setBoundary(m, l2);
	setBoundary(m, l3);
	setBoundary(m, l4);
}

void runMobil(Mobil listM[], Frame frame, Lintasan l, Mobil p) {
	int stop = 0;
	srand(time(NULL));	
	drawMobil(p, frame, GREEN);	
	drawMobil(listM[0], frame, GREEN);

	int i = 0;
	while(!stop) {
		if(i == 11) {			
	    	drawMobil(listM[1], frame, GREEN);	    		    	
	    }

		if(i > 10) {
			drawLintasan(l, frame, RED);
			drawMobil(listM[0], frame, BLACK);
	    	drawMobil(listM[1], frame, BLACK);	

	    	double deltaMove = 5 + 4 * (300 - listM[0].position.yFrame - l.position.yFrame) / 300;
		    listM[0].position.yFrame -= deltaMove;

		    if (listM[0].position.yFrame < -222) {
		        listM[0].position.yFrame = 100;
		        
		        int randX = (rand() % 3) * 73;
		        listM[0].position.xFrame = randX - l.topWidth/4;
		    }

		    if (listM[0].position.xFrame - l.position.xFrame > 0) {
		    	listM[0].position.xFrame = l.position.xFrame + (100 * (78 - listM[0].position.yFrame)) / 300 + 73.333;
		    } else if (listM[0].position.xFrame - l.position.xFrame < 0) {
		    	listM[0].position.xFrame = l.position.xFrame - ((100 * (78 - listM[0].position.yFrame)) / 300 + 73.333);
		    }

		    deltaMove = 5 + 4 * (300 - listM[1].position.yFrame - l.position.yFrame) / 300;
		    listM[1].position.yFrame -= deltaMove;

		    if (listM[1].position.yFrame < -222) {
		        listM[1].position.yFrame = 100;
		        
		        int randX = (rand() % 3) * 73;
		        listM[1].position.xFrame = randX - l.topWidth/4;
		    }

		    if (listM[1].position.xFrame - l.position.xFrame > 0) {
		    	listM[1].position.xFrame = l.position.xFrame + (100 * (78 - listM[1].position.yFrame)) / 300 + 73.333;
		    } else if (listM[1].position.xFrame - l.position.xFrame < 0) {
		    	listM[1].position.xFrame = l.position.xFrame - ((100 * (78 - listM[1].position.yFrame)) / 300 + 73.333);
		    }

		    if (kbhit()) {
		        char c = getch();
		        if (c == 's') {
		            stop = 1;
		            printf("stop\n");
		        } else if (c == 'M') { //key kanan
		        	if (l.position.xFrame > -173) {
		        		drawLintasan(l, frame, BLACK);
			            drawMobil(listM[0], frame, BLACK);          			            
		            	drawMobil(listM[1], frame, BLACK);
		            	listM[1].position.xFrame -= 44;			            
			            l.position.xFrame -= 44;	            
			            listM[0].position.xFrame -= 44;
			            drawMobil(p, frame, GREEN);
			            drawLintasan(l, frame, RED);
		        	}	                                            	           
		        } else if (c == 'K') { //key kiri
		        	if (l.position.xFrame < 173) {
		        		drawLintasan(l, frame, BLACK);
			            drawMobil(listM[0], frame, BLACK);			            
		            	drawMobil(listM[1], frame, BLACK);
		            	listM[1].position.xFrame += 44;			            
			            l.position.xFrame += 44;                
			            listM[0].position.xFrame += 44;
			            drawMobil(p, frame, GREEN);
			            drawLintasan(l, frame, RED);
		        	}	              	           
		        } 
		    }

		    autoScaleMobil(listM[0], l);
		    drawMobil(listM[0], frame, GREEN);		    
	    	autoScaleMobil(listM[1], l);
	    	drawMobil(listM[1], frame, GREEN);

			if(isCollide(listM[0], p)) {
		    	stop = 1;
		    	drawMobil(listM[0], frame, RED);
		    	drawMobil(p, frame, GREEN);
		    	printf("tabrakan!\n");	    	
		    }		    
	    	
	    	if(isCollide(listM[1], p)) {
		    	stop = 1;
		    	drawMobil(listM[1], frame, RED);
		    	drawMobil(p, frame, GREEN);
		    	printf("tabrakan!\n");	    	
		    }
		} else {
			drawLintasan(l, frame, RED);							
		    drawMobil(listM[0], frame, BLACK);	  	     

		    double deltaMove = 5 + 4 * (300 - listM[0].position.yFrame - l.position.yFrame) / 300;
		    listM[0].position.yFrame -= deltaMove;

		    if (listM[0].position.yFrame < -222) {
		        listM[0].position.yFrame = 100;
		        
		        int randX = (rand() % 3) * 73;
		        listM[0].position.xFrame = randX - l.topWidth/4;
		    }

		    if (listM[0].position.xFrame - l.position.xFrame > 0) {
		    	listM[0].position.xFrame = l.position.xFrame + (100 * (78 - listM[0].position.yFrame)) / 300 + 73.333;
		    } else if (listM[0].position.xFrame - l.position.xFrame < 0) {
		    	listM[0].position.xFrame = l.position.xFrame - ((100 * (78 - listM[0].position.yFrame)) / 300 + 73.333);
		    }		    

		    if (kbhit()) {
		        char c = getch();
		        if (c == 's') {
		            stop = 1;
		            printf("stop\n");
		        } else if (c == 'M') { //key kanan
		        	if (l.position.xFrame > -173) {
		        		drawLintasan(l, frame, BLACK);
			            drawMobil(listM[0], frame, BLACK);          		            
			            l.position.xFrame -= 44;	            
			            listM[0].position.xFrame -= 44;
			            drawMobil(p, frame, GREEN);
			            drawLintasan(l, frame, RED);
		        	}	                                            	           
		        } else if (c == 'K') { //key kiri
		        	if (l.position.xFrame < 173) {
		        		drawLintasan(l, frame, BLACK);
			            drawMobil(listM[0], frame, BLACK);		            
			            l.position.xFrame += 44;                
			            listM[0].position.xFrame += 44;
			            drawMobil(p, frame, GREEN);
			            drawLintasan(l, frame, RED);
		        	}	              	           
		        } 
		    }
		    
		    autoScaleMobil(listM[0], l);
		    drawMobil(listM[0], frame, GREEN);	        

		    if(isCollide(listM[0], p)) {
		    	stop = 1;
		    	drawMobil(listM[0], frame, RED);
		    	drawMobil(p, frame, GREEN);
		    	printf("tabrakan!\n");	    	
		    }
		}			   

	    i++;
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
