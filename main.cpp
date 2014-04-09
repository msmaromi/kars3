
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

    initgraph(&graphdriver, &graphmode, "../TC/BGI");
    frame = makeFrame(320, 240);
    // tcc -eBARCA GRAPHICS.LIB FRAME.C MAIN.C
    int topWidthLintasan = 220;
    int bottomWidthLintasan = 520;
    int heightLintasan = 300;
    Point p = makePoint(0, -222);    
    Lintasan l = makeLintasan(p, topWidthLintasan, bottomWidthLintasan, heightLintasan);    

    srand(time(NULL));

    int randX = (rand() % 3) * 73;
    Point posMobil = makePoint(randX - l.topWidth/4, 78);
    Mobil m = makeMobil(posMobil, 73, 50);
    
    randX = (2 * (rand() % 3) + 1) * 73;
    posMobil = makePoint(randX, 100);
    Mobil m2 = makeMobil(posMobil, l.topWidth / 4, 78);

    Mobil listM[2];
    listM[0] = m;
    listM[1] = m2;

    Point playerPoint = makePoint(0, -222);
    Mobil playerMobil = makeMobil(playerPoint, 520/3, 110);
    // drawMobil(playerMobil, frame, GREEN);
    // delay(1000);
    // drawMobil(playerMobil, frame, BLACK);
    
    runMobil(listM, frame, l, playerMobil);
}
