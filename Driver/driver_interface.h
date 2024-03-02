//
// Created by THE13 on 2024/2/5.
//

#ifndef CHICHIBOOM_UI_SIMLATOR_DRIVER_INTERFACE_H
#define CHICHIBOOM_UI_SIMLATOR_DRIVER_INTERFACE_H

#include <cstdint>

#include "sdl2_interface.h"

class SDL2_{


public:
    /*0.init all*/
    void init()
    {
        screen_init();//create and init the screen
        driver_init();//init the driver
        isInitialized = true;
    }
    /*1.set pencil*/
    static void setPencilMode(uint8_t mode ,int drawColor,int bgColor)
    {
        /*1.设置绘画模式*/
        sdl2_setMode(&sdl2,mode);
        /*2.设置画笔颜色*/
        sdl2_setPencil(&sdl2,drawColor,bgColor);
    }

    /*-------------------------------- draw funciton --------------------------------*/
    /*2.draw string*/
    void drawString(int16_t x, int16_t y, const char *str, FontDefv2 font)
    {
        if(!isInitialized)init();
        sdl2_draw_string(&sdl2,x,y,str,font);
    }
    /*3.draw box*/
    void drawBox(int16_t x, int16_t y, uint16_t w, uint16_t h)
    {
        if(!isInitialized)init();
        sdl2_DrawBox(&sdl2, x, y,  w,  h);
    }
    /*4.draw box*/
    void drawRBox(int16_t x, int16_t y, uint16_t w, uint16_t h,uint16_t r)
    {
        if(!isInitialized)init();
        sdl2_DrawRBox(&sdl2, x, y,  w,  h,r);
    }
    /*5.draw frame*/
    void drawFrame(int16_t x, int16_t y, uint16_t w, uint16_t h)
    {
        if(!isInitialized)init();
        sdl2_DrawFrame(&sdl2, x, y,  w,  h);
    }
    /*4.draw box*/
    void drawRFrame(int16_t x, int16_t y, uint16_t w, uint16_t h,uint16_t r)
    {
        if(!isInitialized)init();
        sdl2_DrawRFrame(&sdl2, x, y,  w,  h,r);
    }
    /*5.draw h line*/
    void drawHLine(int16_t x, int16_t y, uint16_t len)
    {
        if(!isInitialized)init();
        sdl2_DrawHLine(&sdl2, x, y,  len);
    }
    /*6.draw v line*/
    void drawVLine(int16_t x, int16_t y, uint16_t len)
    {
        if(!isInitialized)init();
        sdl2_DrawVLine(&sdl2, x, y,  len);
    }
    /*7.draw  line*/
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
    {
        if(!isInitialized)init();
        draw_line(&sdl2, x0, y0,  x1,y1);
    }
    /*8.draw  circle*/
    void drawCircle(int16_t x, int16_t y, uint16_t rad, uint8_t option)
    {
        if(!isInitialized)init();
        sdl2_DrawCircle(&sdl2,x,y,rad,option);
    }
    /*8.draw  disc*/
    void drawDisc(int16_t x, int16_t y, uint16_t rad, uint8_t option)
    {
        if(!isInitialized)init();
        sdl2_DrawDisc(&sdl2,x,y,rad,option);
    }

    /*8.draw  circle*/
    void drawEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint8_t option)
    {
        if(!isInitialized)init();
        sdl2_DrawEllipse(&sdl2,x0,y0,rx,ry,option);
    }
    /*8.draw  disc*/
    void drawFilledEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint8_t option)
    {
        if(!isInitialized)init();
        sdl2_DrawFilledEllipse(&sdl2,x0,y0,rx,ry,option);
    }
    /*-------------------------------- buff funciton --------------------------------*/
    /*5.send buff*/
    void sendBuff()
    {
        if(!isInitialized)init();//CHECK THE STATE
        sdl2_sendbuffer(&sdl2);
    }
    /*6.clean buff*/
    void clearBuff()
    {
        if(!isInitialized)init();//CHECK THE STATE
        sdl2_cleanBuffer();
    }


private:
    static void screen_init()//create the screen
    {
        sdl2_init();
    }

    static void driver_init()//init the driver
    {
        /*1.设置BUFFER全为白色*/
        sdl2_cleanBuffer();
        /*2.设置绘画模式*/
        sdl2_setMode(&sdl2,NORMAL);
        /*3.设置画笔颜色*/
        sdl2_setPencil(&sdl2,BLACK,WHITE);
    }

    bool isInitialized = false;
};//end class SDL2_ SDL2

/*sdl2_interface.c*/
extern SDL2_ SDL2;
#endif //CHICHIBOOM_UI_SIMLATOR_DRIVER_INTERFACE_H
