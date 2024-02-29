//
// Created by THE13 on 2024/2/5.
//
#include "sdl2_interface.h"

int disp_buf[SCREEN_HEIGHT][SCREEN_WIDTH];

//反色 Inverse color
int XorColor(int color)
{
    int xorColor = color;
    xorColor =WHITE^color;
    return xorColor;
}

//透明 transparent color
//TODO:在模式设置的函数下，增加一个入口参数为前景色颜色,SDL2.setPencilMode(NORMAL,BLACK,WHITE);
int TraColor(int color)
{
    float alpha = 0.5;//0.5
    int xorColor = color;
    int foreground_color = 0xFFBC14;

    int red1 = (color >> 16) & 0xFF;
    int green1 = (color >> 8) & 0xFF;
    int blue1 = color & 0xFF;

    int red2 = (foreground_color >> 16) & 0xFF;
    int green2 = (foreground_color >> 8) & 0xFF;
    int blue2 = foreground_color & 0xFF;

    int redout = (red1 * (1-alpha) + (red2 * alpha));
    int greenout = (green1 * (1-alpha) + (green2 * alpha));
    int blueout = (blue1 * (1-alpha) + (blue2 * alpha));

    xorColor = (((redout<<16) & 0xFF0000)|((greenout<<8) & 0x00FF00)|((blueout) & 0x0000FF));
    return xorColor;
}

//对单个像素操作
int sdl2_setPixBuffer(sdl2_t *sdl2,int x0,int y0)
{
    //1.check the state:if out of the range , don't operate the buffer;
    if((x0>=SCREEN_WIDTH)&&(x0<0)&&(y0>=SCREEN_HEIGHT)&&(y0<0)) return 0;
    //2.operate the buffer;
    if(sdl2 ->mode == NORMAL){//Draw the color
        disp_buf[y0][x0] = sdl2->draw_color;
        return disp_buf[y0][x0];
    }
    if(sdl2->mode == XOR){//Inverse the color
        disp_buf[y0][x0] = XorColor(disp_buf[y0][x0]);
        return disp_buf[y0][x0];
    }
    if(sdl2->mode == TRA){//Transparent the color
        disp_buf[y0][x0] = TraColor(disp_buf[y0][x0]);
        return disp_buf[y0][x0];
    }
    return 0;//return error
}

void sdl2_setMode(sdl2_t *sdl2,uint8_t mode)
{
    sdl2->mode = mode;
}

void sdl2_setPencil(sdl2_t *sdl2,int draw_color,int bg_color)
{
    sdl2->draw_color = draw_color;
    sdl2->bg_color   = bg_color;
}

void sdl2_cleanBuffer(void)
{
    memset(disp_buf, WHITE, sizeof(disp_buf));
}

void sdl2_sendbuffer(sdl2_t *sdl2)
{
    SDL_Point  point[1];
    int color;
    for(uint16_t j = 0;j<SCREEN_HEIGHT;j++)
    {
        for(uint16_t i = 0;i<SCREEN_WIDTH;i++)
        {
            /*1.get the color*/
            color = disp_buf[j][i];
            int red = (color >> 16) & 0xFF;
            int green = (color >> 8) & 0xFF;
            int blue = color & 0xFF;
            /*2.draw the points*/
            SDL_SetRenderDrawColor(sdl2->renderer, red, green, blue, 255);
            point[0]={i,j};
            SDL_RenderDrawPoints(sdl2->renderer,point,1);
        }
    }

    SDL_RenderPresent(sdl2->renderer);// 在这里调用renderer以显示渲染器中的内容

}

void sdl2_DrawPixel_buffer(sdl2_t *sdl2,uint16_t x, uint16_t y)
{
    sdl2_DrawHVLine(sdl2, x,  y,  1,  0);
}


