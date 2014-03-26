
#include "lintasan.h"
#include "mobil.h"
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>


void main() {

    Frame frame;
    int graphdriver = DETECT, graphmode, color;
    int i, j;   

    initgraph(&graphdriver, &graphmode, "C:\\TC\\BGI");
    frame = makeFrame(320, 240);
    // tcc -eBARCA GRAPHICS.LIB FRAME.C MAIN.C
    
    Point p = makePoint(0, -222);    
    Lintasan l = makeLintasan(p, 210, 510, 300);
    drawLintasan(l, frame, RED);

    srand(time(NULL));
    int randX = (2 * (rand() % 3) + 1) * 35;
    Point posMobil = makePoint(l.position.xFrame - l.topWidth/2 + randX, 78);
    // Mobil m = makeMobil(posMobil, 100, 50);
    Mobil m = makeMobil(posMobil, l.topWidth / 3, 50);

    randX = (2 * (rand() % 3) + 1) * 35;
    posMobil = makePoint(randX, 100);
    Mobil m2 = makeMobil(posMobil, l.topWidth / 3, 50);

    Point playerPoint = makePoint(0, -222);
    Mobil playerMobil = makeMobil(playerPoint, l.topWidth / 3, 50);
    drawMobil(playerMobil, frame, GREEN);
    
    runMobil(m, frame, l);
}
