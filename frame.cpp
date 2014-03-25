#include "FRAME.H"

Frame makeFrame(int x, int y) {
    int i, j, xSide, ySide;
    Frame frame;
    
    xSide = 600;
    ySide = 450;
    frame.xDos = x;
    frame.yDos = y;

    for(i = 0; i < xSide; i++) {
        putpixel(frame.xDos - xSide/2 + i, frame.yDos + ySide/2, BLUE);
    }

    for(i = 0; i < xSide; i++) {
        putpixel(frame.xDos - xSide/2 + i, frame.yDos - ySide/2, BLUE);
    }

    for (j = 0; j < ySide; j++) {
        putpixel(frame.xDos + xSide/2, frame.yDos - ySide/2 + j, BLUE);
    }

    for (j = 0; j < ySide; j++) {
        putpixel(frame.xDos - xSide/2, frame.yDos - ySide/2 + j, BLUE);
    }

    return frame;
}

int getXDos(Frame *frame, int x) {
    return (frame->xDos + x);
}

int getYDos(Frame *frame, int y) {
    return (frame->yDos - y);
}
