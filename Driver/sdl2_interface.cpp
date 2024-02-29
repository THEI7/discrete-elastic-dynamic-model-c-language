//
// Created by THE13 on 2024/2/5.
//
#include "sdl2_interface.h"
#include "driver_interface.h"

SDL_Window *window;
SDL_Renderer *renderer;
sdl2_t sdl2;
SDL2_ SDL2;

void sdl2_init(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("CHICHIBOOMUI Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 240, 240, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    sdl2.renderer = renderer;
    sdl2.mode == NORMAL;
    sdl2.draw_color = WHITE;
    sdl2.bg_color = BLACK;

    SDL_RenderClear(renderer);
}












#if 0 //demo1
int main(){
    /*init the screen*/
    sdl2_init();

    /* 1.设置BUFFER全为白色*/
    sdl2_cleanBuffer();

    for(;;)
    {
        /*1.设置绘画模式*/
        sdl2_setMode(&sdl2,NORMAL);
        /*2.设置画笔颜色*/
        sdl2_setPencil(&sdl2,BLUE,WHITE);
        /*3.画一个框*/
        sdl2_DrawFrame(&sdl2, 0, 0, 100, 100);

        sdl2_sendbuffer(&sdl2);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

#endif

#if 0 //demo2
int main(){
    /*init the screen*/
    sdl2_init();

    /* 1.设置BUFFER全为白色*/
    sdl2_cleanBuffer();

    for(;;)
    {
//        /*1.画一个框*/
//        SDL2.setPencilMode(NORMAL,BLACK,WHITE);//设置画笔模式
//        SDL2.drawFrame(0, 0, 100, 100);
//        /*2.画字符串*/
//        SDL2.setPencilMode(XOR,BLACK,WHITE);
//        SDL2.drawString(0,100,sys_info.now->name,Font_JetBrainsMonoExtrabold2034 );
//        /*3.画圆*/
//        SDL2.setPencilMode(NORMAL,RED,WHITE);
//        SDL2.drawCircle(140,140,10,SDL2_DRAW_ALL);
//        /*4.画椭圆*/
//        SDL2.setPencilMode(NORMAL,BLUE,WHITE);
//        SDL2.drawRBox(40,140,40,40,1);
//        /* end.send the buff*/
//        SDL2.sendBuff();
//        /* end.clean the buff*/
//        SDL2.cleanBuff();
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
#endif
