//
// Created by THE13 on 2024/2/5.
//
#include "sdl2_interface.h"





/*
  draw a filled box
  restriction: does not work for w = 0 or h = 0
*/
void sdl2_DrawBox(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t w, uint16_t h)
{
/*2. draw box idea*/
		{
			while( h != 0 )
			{
                sdl2_DrawHVLine(sdl2, x, y, w, 0);
					y++;
					h--;
			}
		}
}



/*
  draw a frame (empty box)
  restriction: does not work for w = 0 or h = 0
*/
void sdl2_DrawFrame(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t w, uint16_t h)
{
    uint16_t xtmp = x;

    sdl2_DrawHVLine(sdl2, x, y, w, 0);

    if (h >= 2) {
        h-=2;
        y++;
        if (h > 0) {
            sdl2_DrawHVLine(sdl2, x, y, h, 1);
            x+=w;
            x--;
            sdl2_DrawHVLine(sdl2, x, y, h, 1);
            y+=h;
        }
        sdl2_DrawHVLine(sdl2,xtmp, y, w, 0);
    }
}


void sdl2_DrawRBox(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t r)
{
    int16_t xl, yu;
    int16_t yl, xr;

    xl = x;
    xl += r;
    yu = y;
    yu += r;

    xr = x;
    xr += w;
    xr -= r;
    xr -= 1;


    yl = y;
    yl += h;
    yl -= r;
    yl -= 1;

    sdl2_DrawDisc(sdl2, xl, yu, r, SDL2_DRAW_UPPER_LEFT);
    sdl2_DrawDisc(sdl2, xr, yu, r, SDL2_DRAW_UPPER_RIGHT);
    sdl2_DrawDisc(sdl2, xl, yl-1, r, SDL2_DRAW_LOWER_LEFT);
    sdl2_DrawDisc(sdl2, xr, yl-1, r, SDL2_DRAW_LOWER_RIGHT);
    {
        uint16_t ww, hh;

        ww = w;
        ww -= r;
        ww -= r;
        xl++;
        yu++;

        if ( ww >= 3 )
        {
            ww -= 2;
            sdl2_DrawBox(sdl2, xl, y, ww, r+1);
            sdl2_DrawBox(sdl2, xl, yl, ww, r+1);
        }

        hh = h;
        hh -= r;
        hh -= r;
        //h--;
        if ( hh >= 3 )
        {
            hh -= 2;
            sdl2_DrawBox(sdl2, x, yu, w, hh);
        }
    }
}



void sdl2_DrawRFrame(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t r)
{
    uint16_t xl, yu;


    xl = x;
    xl += r;
    yu = y;
    yu += r;

    {
        uint16_t yl, xr;

        xr = x;
        xr += w;
        xr -= r;
        xr -= 1;

        yl = y;
        yl += h;
        yl -= r;
        yl -= 1;

        sdl2_DrawCircle(sdl2, xl, yu, r, SDL2_DRAW_UPPER_LEFT);
        sdl2_DrawCircle(sdl2, xr, yu, r, SDL2_DRAW_UPPER_RIGHT);
        sdl2_DrawCircle(sdl2, xl, yl, r, SDL2_DRAW_LOWER_LEFT);
        sdl2_DrawCircle(sdl2, xr, yl, r, SDL2_DRAW_LOWER_RIGHT);
    }

    {
        uint16_t ww, hh;

        ww = w;
        ww -= r;
        ww -= r;
        hh = h;
        hh -= r;
        hh -= r;

        xl++;
        yu++;

        if ( ww >= 3 )
        {
            ww -= 2;
            h--;
            sdl2_DrawHLine(sdl2, xl, y, ww);
            sdl2_DrawHLine(sdl2, xl, y+h, ww);
        }

        if ( hh >= 3 )
        {
            hh -= 2;
            w--;
            sdl2_DrawVLine(sdl2, x, yu, hh);
            sdl2_DrawVLine(sdl2, x+w, yu, hh);
        }
    }
}

