
#include "lintasan.h"
#include "mobil.h"
#include <conio.h>
#include <stdio.h>
#include <dos.h>


void main() {

    Frame frame;
    int graphdriver = DETECT, graphmode, color;
    int i, j;
    int endGame = 0;    

    initgraph(&graphdriver, &graphmode, "C:\\TC\\BGI");
    frame = makeFrame(320, 240);
    // tcc -eBARCA GRAPHICS.LIB FRAME.C MAIN.C
    
    Point p = makePoint(0, -222);    
    Lintasan l = makeLintasan(p, 200, 500, 300);
    drawLintasan(l, frame, RED);


    Point posMobil = makePoint(0, 100);
    Mobil m = makeMobil(posMobil, 100, 50);    

    while (!endGame) {                     
        drawMobil(m, frame, GREEN);       
        delay(333);
        drawMobil(m, frame, BLACK);
        m.position.yFrame -= 5;        
        if (kbhit()) {
            char c = getch();
            if (c == 's') {
                endGame = 1;
            } else if (c == 'M') { //key kanan
                drawLintasan(l, frame, BLACK);
                drawMobil(m, frame, BLACK);             
                l.position.xFrame -= 10;   
                m.position.xFrame -= 10;                                
                drawLintasan(l, frame, RED);
                drawMobil(m, frame, GREEN);
            } else if (c == 'K') { //key kiri
                drawLintasan(l, frame, BLACK);
                drawMobil(m, frame, BLACK);
                l.position.xFrame += 10;                
                m.position.xFrame += 10;                        
                drawLintasan(l, frame, RED);
                drawMobil(m, frame, GREEN);
            } 
        }
        drawMobil(m, frame, GREEN);                
    }    
}
