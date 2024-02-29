//
// Created by THE13 on 2024/2/5.
//

#include "sdl2_interface.h"


void draw_line(sdl2_t *sdl2,int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
    uint16_t swap;
    uint16_t steep = ABS(y1 - y0) > ABS(x1 - x0);
    if (steep) {
        swap = x0;
        x0 = y0;
        y0 = swap;

        swap = x1;
        x1 = y1;
        y1 = swap;
        //_swap_int16_t(x0, y0);
        //_swap_int16_t(x1, y1);
    }

    if (x0 > x1) {
        swap = x0;
        x0 = x1;
        x1 = swap;

        swap = y0;
        y0 = y1;
        y1 = swap;
        //_swap_int16_t(x0, x1);
        //_swap_int16_t(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = ABS(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0<=x1; x0++)
    {
        if (steep)
        {
            sdl2_setPixBuffer(sdl2,y0,x0);
        }
        else
        {
            sdl2_setPixBuffer(sdl2,x0,y0);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}