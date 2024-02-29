//
// Created by THE13 on 2024/2/5.
//


#include "sdl2_interface.h"


static void sdl2_draw_font(sdl2_t *sdl2,int16_t x, int16_t y,char ch,FontDefv2 font);

void sdl2_draw_string(sdl2_t *sdl2,int16_t x, int16_t y, const char *str, FontDefv2 font)
{
    while (*str)
    {
        if (x + font.width >= SCREEN_WIDTH)
        {
            x = 0;
            y += font.height;
            if (y + font.height >= SCREEN_HEIGHT)
            {
                break;
            }

            if (*str == ' ')
            {
                // skip spaces in the beginning of the new line
                str++;
                continue;
            }
        }

        sdl2_draw_font(sdl2,x, y, *str, font);
        x += font.width;
        str++;
    }
}

static void sdl2_draw_font(sdl2_t *sdl2,int16_t x, int16_t y,char ch,FontDefv2 font)
{
    uint16_t font_byte_size =  font.height * font.width / 8;// 8 is the font bit size
    uint16_t font_bit_size = font.height * font.width;// 8 is the font bit size
    uint16_t move_bit_total_cnt = 0;// 8 is the font bit size
    uint16_t offset_y = 0;// 8 is the font bit size
    uint16_t offset_x = 0;// 8 is the font bit size
    uint16_t ch_offset = (ch -32)* font_byte_size;// 32 is the first font character

    if(font.width%8!=0) {//如果不足以8字节就进行部补位
        font_byte_size = font.height * (font.width / 8 + 1);// 8 is the font bit size
        font_bit_size =  font_byte_size *8;
        ch_offset = (ch -32)* font_byte_size;
    }

    for (uint16_t j = 0; j<font_byte_size; j++) {
        for (uint8_t ii = 0; ii < 8; ii++) {
            /*check the state*/
            if((y + offset_y>=SCREEN_HEIGHT)||(y + offset_y<0))continue;
            if((x + offset_x>=SCREEN_WIDTH)||(y + offset_y<0))continue;

            if (((font.data[ch_offset+j]>> ii) & 0x01) == 0x01)
            {
                sdl2_setPixBuffer(sdl2,x + offset_x,y + offset_y);
            }
            move_bit_total_cnt++;
            offset_x = (move_bit_total_cnt % font.width);// 8 is the font bit size
            offset_y = (move_bit_total_cnt / font.width);// 8 is the font bit size
            if(offset_x==0)break;
        };//end for ii
    };//end for j
}