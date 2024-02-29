//
// Created by THE13 on 2024/2/5.
//
#include "sdl2_interface.h"


//绘制水平线
void sdl2_DrawHLine(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t len)
{
    sdl2_DrawHVLine( sdl2, x, y, len, 0);
}

//绘制垂直线
void sdl2_DrawVLine(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t len)
{
    sdl2_DrawHVLine( sdl2, x, y, len, 1);
}


void sdl2_DrawHVLine(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t len, uint8_t dir)
{
    if(dir == 0)//绘制水平线
    {
        draw_line(sdl2,x,y,x+len-1,  y);
    }
    if(dir == 1)//绘制垂直线
    {
        draw_line(sdl2,x,  y,  x,  y+len);
    }
}