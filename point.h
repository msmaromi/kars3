//
//  Point.h
//  
//
//  Created by Muhammad S Maromi on 2/17/14.
//
//

#ifndef _Point_h
#define _Point_h

#include "frame.h"

typedef struct {
    long xFrame;  //dihitung terhadap frame
    long yFrame;  //dihitung terhadap frame
} Point;

Point makePoint(long x, long y);
void drawPoint(Point *point, Frame *frame, int color);


#endif
