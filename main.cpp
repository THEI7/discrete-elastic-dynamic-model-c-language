#include <iostream>
#include <SDL2/SDL.h>
#include <cstdint>
#include <cstring>
using namespace std;
#include ".\Driver\sdl2_interface.h"
#include ".\Driver\driver_interface.h"

#undef main


#define GRAVITY 9.8f

typedef struct Elastic_system_model{
    /*user set*/
    float mass;
    float stiffnes;
    float damping;
    float tar;
    float now;
    float last;
    float v0;
    float a;
    float T;
}ElasticSystemModel_t;

ElasticSystemModel_t  esm = {
        .mass = 2,
        .stiffnes = 1,
        .damping = 0.1,
        .tar = 200,
        .now = 0,
        .last = 0,
        .v0 = 0,
        .a = 0,
        .T = 1,



};

float Elastic_system_model_update(ElasticSystemModel_t * elastic)
{
    static float output = 0.0f;
    //1. 计算上一帧的信息
    elastic->v0=elastic->v0+ elastic->a*elastic->T;
    elastic->a =(  ( (elastic->tar - elastic->now) * elastic->stiffnes ) - (elastic->mass * GRAVITY * elastic->damping)   )/ elastic->mass;
//    if((elastic->mass * GRAVITY * elastic->damping) >= ((elastic->tar - elastic->now) * elastic->stiffnes )) elastic->a = 0;//小球系统近似于谐振子系统
    //2. 计算当前帧
    elastic->now = (elastic->v0 * elastic->T) + (elastic->a * elastic->T * elastic->T / 2);
    output = elastic->now;

    elastic->last = elastic->now;
    printf("v0:%f a:%f  last:%f now:%f\r\n",elastic->v0,elastic->a,elastic->last,elastic->now);
    return output;
}
float outputt  = 0.0f;
int main() {
    SDL2.init();

    for(;;)
    {
        SDL2.cleanBuff();

        outputt = Elastic_system_model_update(&esm);
        if(abs(outputt) >240)outputt = 240;
//        printf("%f\r\n",outputt);
        SDL2.drawBox((uint8_t)outputt,10,10,10);
        SDL2.sendBuff();
    }
    return 0;
}
