//
// Created by THE13 on 2024/2/5.
//

#include "sdl2_interface.h"

/*==============================================*/
/* Circle */
static void sdl2_draw_circle_section(sdl2_t *sdl2,int16_t x, int16_t y, uint16_t x0, uint16_t y0, uint8_t option);

static void sdl2_draw_circle_section(sdl2_t *sdl2,int16_t x, int16_t y, uint16_t x0, uint16_t y0, uint8_t option)
{
    /* upper right */
    if ( option & SDL2_DRAW_UPPER_RIGHT )
    {
         sdl2_DrawPixel_buffer(sdl2,x0 + x, y0 - y);
         sdl2_DrawPixel_buffer(sdl2,x0 + y, y0 - x);
    }

    /* upper left */
    if ( option & SDL2_DRAW_UPPER_LEFT )
    {
        sdl2_DrawPixel_buffer(sdl2,x0 - x, y0 - y);
        sdl2_DrawPixel_buffer(sdl2,x0 - y, y0 - x);
    }

    /* lower right */
    if ( option & SDL2_DRAW_LOWER_RIGHT )
    {
        sdl2_DrawPixel_buffer(sdl2,x0 + x, y0 + y);
        sdl2_DrawPixel_buffer(sdl2,x0 + y, y0 + x);
    }

    /* lower left */
    if ( option & SDL2_DRAW_LOWER_LEFT )
    {
        sdl2_DrawPixel_buffer(sdl2,x0 - x, y0 + y);
        sdl2_DrawPixel_buffer(sdl2,x0 - y, y0 + x);
    }
}



static void sdl2_draw_circle(sdl2_t *sdl2, int16_t x0, int16_t y0, uint16_t rad, uint8_t option)
{
    int16_t f;
    int16_t ddF_x;
    int16_t ddF_y;
    int16_t x;
    int16_t y;

    f = 1;
    f -= rad;
    ddF_x = 1;
    ddF_y = 0;
    ddF_y -= rad;
    ddF_y *= 2;
    x = 0;
    y = rad;

    sdl2_draw_circle_section(sdl2, x, y, x0, y0, option);

    while ( x < y )
    {
        if (f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        sdl2_draw_circle_section(sdl2, x, y, x0, y0, option);
    }
}


void sdl2_DrawCircle(sdl2_t *sdl2,int16_t x, int16_t y, uint16_t rad, uint8_t option)
{
    sdl2_draw_circle(sdl2,  x,  y,  rad,  option);
}

/*==============================================*/
/* Disk 实心*/
static void sdl2_draw_disc_section(sdl2_t *sdl2,int16_t x, int16_t y, int16_t x0, int16_t y0, uint8_t option) ;

static void sdl2_draw_disc_section(sdl2_t *sdl2,int16_t x, int16_t y, int16_t x0, int16_t y0, uint8_t option)
{
    /* upper right */
    if ( option & SDL2_DRAW_UPPER_RIGHT )
    {
        sdl2_DrawVLine(sdl2, x0+x, y0-y, y+1);
        sdl2_DrawVLine(sdl2, x0+y, y0-x, x+1);
    }

    /* upper left */
    if ( option & SDL2_DRAW_UPPER_LEFT )
    {
        sdl2_DrawVLine(sdl2, x0-x, y0-y, y+1);
        sdl2_DrawVLine(sdl2, x0-y, y0-x, x+1);
    }

    /* lower right */
    if ( option & SDL2_DRAW_LOWER_RIGHT )
    {
        sdl2_DrawVLine(sdl2, x0+x, y0, y+1);
        sdl2_DrawVLine(sdl2, x0+y, y0, x+1);
    }

    /* lower left */
    if ( option & SDL2_DRAW_LOWER_LEFT )
    {
        sdl2_DrawVLine(sdl2, x0-x, y0, y+1);
        sdl2_DrawVLine(sdl2, x0-y, y0, x+1);
    }
}


static void sdl2_draw_disc(sdl2_t *sdl2, int16_t x0, int16_t y0, uint16_t rad, uint8_t option)
{
    int16_t f;
    int16_t ddF_x;
    int16_t ddF_y;
    int16_t x;
    int16_t y;

    f = 1;
    f -= rad;
    ddF_x = 1;
    ddF_y = 0;
    ddF_y -= rad;
    ddF_y *= 2;
    x = 0;
    y = rad;

    sdl2_draw_disc_section(sdl2, x, y, x0, y0, option);

    while ( x < y )
    {
        if (f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        sdl2_draw_disc_section(sdl2, x, y, x0, y0, option);
    }
}

void sdl2_DrawDisc(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t rad, uint8_t option)
{
    /* draw disc */
    sdl2_draw_disc(sdl2, x, y, rad, option);
}


/*==============================================*/
/* Ellipse 椭圆*/

/*
  Source:
    Foley, Computer Graphics, p 90
*/
static void sdl2_draw_ellipse_section(sdl2_t *sdl2, int16_t x, int16_t y, int16_t x0, int16_t y0, uint8_t option);

static void sdl2_draw_ellipse_section(sdl2_t *sdl2, int16_t x, int16_t y, int16_t x0, int16_t y0, uint8_t option)
{
    /* upper right */
    if ( option & SDL2_DRAW_UPPER_RIGHT )
    {
        sdl2_DrawPixel_buffer(sdl2,x0 + x, y0 - y);
    }

    /* upper left */
    if ( option & SDL2_DRAW_UPPER_LEFT )
    {
        sdl2_DrawPixel_buffer(sdl2,x0 - x, y0 - y);
    }

    /* lower right */
    if ( option & SDL2_DRAW_LOWER_RIGHT )
    {
        sdl2_DrawPixel_buffer( sdl2,x0 + x, y0 + y);
    }

    /* lower left */
    if ( option & SDL2_DRAW_LOWER_LEFT )
    {
        sdl2_DrawPixel_buffer( sdl2,x0 - x, y0 + y);
    }
}


static void sdl2_draw_ellipse(sdl2_t *sdl2, int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint8_t option)
{
    int16_t x, y;
    int32_t xchg, ychg;
    int32_t err;
    int32_t rxrx2;
    int32_t ryry2;
    int32_t stopx, stopy;

    rxrx2 = rx;
    rxrx2 *= rx;
    rxrx2 *= 2;

    ryry2 = ry;
    ryry2 *= ry;
    ryry2 *= 2;

    x = rx;
    y = 0;

    xchg = 1;
    xchg -= rx;
    xchg -= rx;
    xchg *= ry;
    xchg *= ry;

    ychg = rx;
    ychg *= rx;

    err = 0;

    stopx = ryry2;
    stopx *= rx;
    stopy = 0;

    while( stopx >= stopy )
    {
        sdl2_draw_ellipse_section(sdl2, x, y, x0, y0, option);
        y++;
        stopy += rxrx2;
        err += ychg;
        ychg += rxrx2;
        if ( 2*err+xchg > 0 )
        {
            x--;
            stopx -= ryry2;
            err += xchg;
            xchg += ryry2;
        }
    }

    x = 0;
    y = ry;

    xchg = ry;
    xchg *= ry;

    ychg = 1;
    ychg -= ry;
    ychg -= ry;
    ychg *= rx;
    ychg *= rx;

    err = 0;

    stopx = 0;

    stopy = rxrx2;
    stopy *= ry;


    while( stopx <= stopy )
    {
        sdl2_draw_ellipse_section(sdl2, x, y, x0, y0, option);
        x++;
        stopx += ryry2;
        err += xchg;
        xchg += ryry2;
        if ( 2*err+ychg > 0 )
        {
            y--;
            stopy -= rxrx2;
            err += ychg;
            ychg += rxrx2;
        }
    }
}


void sdl2_DrawEllipse(sdl2_t *sdl2, int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint8_t option)
{
    sdl2_draw_ellipse(sdl2, x0, y0, rx, ry, option);
}

/*==============================================*/
/* Filled Ellipse 实心椭圆*/

static void sdl2_draw_filled_ellipse_section(sdl2_t *sdl2, int16_t x, int16_t y, int16_t x0, int16_t y0, uint8_t option);
static void sdl2_draw_filled_ellipse_section(sdl2_t *sdl2, int16_t x, int16_t y, int16_t x0, int16_t y0, uint8_t option)
{
    /* upper right */
    if ( option & SDL2_DRAW_UPPER_RIGHT )
    {
        sdl2_DrawVLine(sdl2, x0+x, y0-y, y+1);
    }

    /* upper left */
    if ( option & SDL2_DRAW_UPPER_LEFT )
    {
        sdl2_DrawVLine(sdl2, x0-x, y0-y, y+1);
    }

    /* lower right */
    if ( option & SDL2_DRAW_LOWER_RIGHT )
    {
        sdl2_DrawVLine(sdl2, x0+x, y0, y+1);
    }

    /* lower left */
    if ( option & SDL2_DRAW_LOWER_LEFT )
    {
        sdl2_DrawVLine(sdl2, x0-x, y0, y+1);
    }
}

static void sdl2_draw_filled_ellipse(sdl2_t *sdl2, int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint8_t option)
{
    uint16_t x, y;
    int32_t xchg, ychg;
    int32_t err;
    int32_t rxrx2;
    int32_t ryry2;
    int32_t stopx, stopy;

    rxrx2 = rx;
    rxrx2 *= rx;
    rxrx2 *= 2;

    ryry2 = ry;
    ryry2 *= ry;
    ryry2 *= 2;

    x = rx;
    y = 0;

    xchg = 1;
    xchg -= rx;
    xchg -= rx;
    xchg *= ry;
    xchg *= ry;

    ychg = rx;
    ychg *= rx;

    err = 0;

    stopx = ryry2;
    stopx *= rx;
    stopy = 0;

    while( stopx >= stopy )
    {
        sdl2_draw_filled_ellipse_section(sdl2, x, y, x0, y0, option);
        y++;
        stopy += rxrx2;
        err += ychg;
        ychg += rxrx2;
        if ( 2*err+xchg > 0 )
        {
            x--;
            stopx -= ryry2;
            err += xchg;
            xchg += ryry2;
        }
    }

    x = 0;
    y = ry;

    xchg = ry;
    xchg *= ry;

    ychg = 1;
    ychg -= ry;
    ychg -= ry;
    ychg *= rx;
    ychg *= rx;

    err = 0;

    stopx = 0;

    stopy = rxrx2;
    stopy *= ry;


    while( stopx <= stopy )
    {
        sdl2_draw_filled_ellipse_section(sdl2, x, y, x0, y0, option);
        x++;
        stopx += ryry2;
        err += xchg;
        xchg += ryry2;
        if ( 2*err+ychg > 0 )
        {
            y--;
            stopy -= rxrx2;
            err += ychg;
            ychg += rxrx2;
        }
    }

}

void sdl2_DrawFilledEllipse(sdl2_t *sdl2, int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint8_t option)
{
    sdl2_draw_filled_ellipse(sdl2, x0, y0, rx, ry, option);
}