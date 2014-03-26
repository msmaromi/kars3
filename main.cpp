
#include "lintasan.h"
#include <conio.h>
#include <stdio.h>


void main() {

    Frame frame;
    int graphdriver = DETECT, graphmode, color;
    int i, j;
    int endGame = 0;
    int currentX;
    int currentY;

    initgraph(&graphdriver, &graphmode, "C:\\TC\\BGI");
    frame = makeFrame(320, 240);
    // tcc -eBARCA GRAPHICS.LIB FRAME.C MAIN.C

    currentX = 0;
    currentY = -222;
    Point p = makePoint(currentX, currentY);
    

    Lintasan l = makeLintasan(p, 200, 500, 300);
    drawLintasan(l, frame, RED);

    while (!endGame) {
        char c = getch();
        //kanan M
        // kiri K
        // if ();
        if (c == 's') {
            endGame = 1;
        } else if (c == 'M') { //geser kanan
            drawLintasan(l, frame, BLACK);
            currentX += 10;
            p = makePoint(currentX, currentY);
            l = makeLintasan(p, 200, 500, 300);
            drawLintasan(l, frame, RED);
        } else if (c == 'K') { //geser kiri
            drawLintasan(l, frame, BLACK);
            currentX -= 10;
            p = makePoint(currentX, currentY);
            l = makeLintasan(p, 200, 500, 300);
            drawLintasan(l, frame, RED);
        }          
    }    
}
