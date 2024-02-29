//
// Created by THE13 on 2024/2/5.
//

#ifndef CHICHIBOOM_UI_SIMLATOR_SDL2_INTERFACE_H
#define CHICHIBOOM_UI_SIMLATOR_SDL2_INTERFACE_H

#include <SDL2/SDL.h>
#include <stdint.h>

#include "sdl2_font_buffer.h"

#define  SCREEN_HEIGHT 240
#define  SCREEN_WIDTH 240

/* color const param*/
#define WHITE   0XFFFFFF
#define BLACK   0x000000
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000ff

/* draw mode config */
#define NORMAL 0
#define XOR 1   //反色
#define TRA 2 //透明
#define SDL2_DRAW_UPPER_RIGHT 0x01
#define SDL2_DRAW_UPPER_LEFT  0x02
#define SDL2_DRAW_LOWER_LEFT 0x04
#define SDL2_DRAW_LOWER_RIGHT  0x08
#define SDL2_DRAW_ALL (SDL2_DRAW_UPPER_RIGHT|SDL2_DRAW_UPPER_LEFT|SDL2_DRAW_LOWER_LEFT|SDL2_DRAW_LOWER_RIGHT)

/* math fun */
#define ABS(x) ((x) > 0 ? (x) : -(x))

typedef struct sdl2_struct
{

    SDL_Renderer * renderer;

    /*以像素为单位显示用户的尺寸 display dimensions in pixel for the user, calculated in u8g2_update_dimension_common()  */
    uint8_t width;
    uint8_t height;

    /* information about the current font */
    const uint8_t* font;             /* current font for all text procedures */
    // removed: const u8g2_kerning_t *kerning;		/* can be NULL */
    // removed: u8g2_get_kerning_cb get_kerning_cb;
    uint8_t  mode;//颜色是否取反
    int bg_color;//背景颜色
    int draw_color;        /* 0: clear pixel, 1: set pixel, modified and restored by font procedures */
}sdl2_t;


extern sdl2_t sdl2;
/* data buffer */
extern int disp_buf[SCREEN_HEIGHT][SCREEN_WIDTH];
/* sdl2 init param */
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern sdl2_t sdl2;



/*==========================================*/
/* sdl2_line.c */
void draw_line(sdl2_t *sdl2,int16_t x0, int16_t y0, int16_t x1, int16_t y1);


/*==========================================*/
/* sdl2_hvline.c */
void sdl2_DrawHLine(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t len);
void sdl2_DrawVLine(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t len);
void sdl2_DrawHVLine(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t len, uint8_t dir);

/*==========================================*/
/* sdl2_box.c */
void sdl2_DrawBox(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t w, uint16_t h);
void sdl2_DrawFrame(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t w, uint16_t h);
void sdl2_DrawRBox(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t r);
void sdl2_DrawRFrame(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t r);
/*==========================================*/
/* sdl2_buffer.c */
int XorColor(int color);
int TraColor(int color);
int sdl2_setPixBuffer(sdl2_t *sdl2,int x0,int y0);
void sdl2_setPencil(sdl2_t *sdl2,int draw_color,int bg_color);
void sdl2_cleanBuffer(void);
void sdl2_sendbuffer(sdl2_t *sdl2);
void sdl2_setMode(sdl2_t *sdl2,uint8_t mode);
void sdl2_DrawPixel_buffer(sdl2_t *sdl2,uint16_t x, uint16_t y);
/*==========================================*/
/* sdl2_interface.c */
void sdl2_init(void);

/*==========================================*/
/* sdl2_font.c */
void sdl2_draw_string(sdl2_t *sdl2,int16_t x, int16_t y, const char *str, FontDefv2 font);


/*==========================================*/
/* sdl2_circle.c */
void sdl2_DrawCircle(sdl2_t *sdl2,int16_t x, int16_t y, uint16_t rad, uint8_t option);
void sdl2_DrawDisc(sdl2_t *sdl2, int16_t x, int16_t y, uint16_t rad, uint8_t option);
void sdl2_DrawEllipse(sdl2_t *sdl2, int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint8_t option);
void sdl2_DrawFilledEllipse(sdl2_t *sdl2, int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint8_t option);
#endif //CHICHIBOOM_UI_SIMLATOR_SDL2_INTERFACE_H
