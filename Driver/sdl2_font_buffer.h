//
// Created by THE13 on 2024/2/5.
//

#ifndef CHICHIBOOM_UI_SIMLATOR_SDL2_FONT_BUFFER_H
#define CHICHIBOOM_UI_SIMLATOR_SDL2_FONT_BUFFER_H
#include "stdint.h"

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint8_t *data;
} FontDefv2;

//Font lib.
extern FontDefv2 Font_Consolas1632;
extern FontDefv2 Font_ConsolasBlodIntailc1632;
extern FontDefv2 Font_JetBrainsMono1632;
extern FontDefv2 Font_JetBrainsMonoSemibold16x32;
extern FontDefv2 Font_JetBrainsMono1624;
extern FontDefv2 Font_JetBrainsMono824;
extern FontDefv2 Font_JetBrainsMono816;
extern FontDefv2 Font_JetBrainsMono1224;
extern FontDefv2 Font_ConsolasBlodIntailc1836;
extern FontDefv2 Font_JetBrainsMonoSemibold1836;
extern FontDefv2 Font_JetBrainsMonoMedium1326;

extern FontDefv2 Font_JetBrainsMono2034;
extern FontDefv2 Font_JetBrainsMonoExtrabold1118;
extern FontDefv2 Font_JetBrainsMonoExtrabold2034;
#endif //CHICHIBOOM_UI_SIMLATOR_SDL2_FONT_BUFFER_H
