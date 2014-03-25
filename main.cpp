
#include "lintasan.h"
#include <conio.h>

void main() {

    Frame frame;
    int graphdriver = DETECT, graphmode, color;
    int i, j;

    initgraph(&graphdriver, &graphmode, "C:\\TC\\BGI");
    frame = makeFrame(320, 240);

    
    // tcc -eBARCA GRAPHICS.LIB FRAME.C MAIN.C

    
    Point p = makePoint(0, -225);
    

    Lintasan l = makeLintasan(p, 200, 500, 300);
    drawLintasan(l, frame);

    getch();
}
