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
    float mass;//重量
    float stiffnes;//刚力
    float damping;//阻尼
    float obj_tar;//目标位置
    float obj_now;//当前位置
    float obj_last;//上一帧的位置
    float v0;//初始速度
    float a;//加速度
    float T;//每一帧之间的时间间隔
}ElasticSystemModel_t;

ElasticSystemModel_t  esm = {
        .mass = 2,//重量
        .stiffnes = 1.2,//刚力
        .damping = 0.001,//阻尼

        .obj_tar = 200,//目标位置
        .obj_now = 10,//当前位置
        .obj_last = 0,//上一帧的位置

        .v0 = 0,//初始速度
        .a = 0,//加速度
        .T = 1,//每一帧之间的时间间隔
};

float Elastic_system_model_update(ElasticSystemModel_t * elastic)
{
    static float output = 0.0f;
    //1. 计算上一帧的信息
    elastic->v0=elastic->v0+ elastic->a*elastic->T;
    //elastic->a =(  ( (elastic->obj_tar - elastic->obj_now) * elastic->stiffnes ) - (elastic->mass * GRAVITY * elastic->damping)   )/ elastic->mass;
    elastic->a = (  ( (elastic->obj_tar - elastic->obj_now) * elastic->stiffnes ) +(elastic->v0 * elastic->damping)   )/ elastic->mass;
    //2. 计算当前帧
    elastic->obj_now = (elastic->v0 * elastic->T) + (elastic->a * elastic->T * elastic->T / 2);
    //3. 更新上一帧的信息
    elastic->obj_last = elastic->obj_now;
    printf("v0:%f a:%f  last:%f now:%f\r\n",elastic->v0,elastic->a,elastic->obj_last,elastic->obj_now);
    return elastic->obj_now;
}

float output ;

int main() {

    SDL2.init();//初始化驱动
    static int32_t i = 0;
    for(;;)
    {
        i++;
        if(i>200)esm.obj_tar = 20;
        if(i>500)esm.obj_tar = 100;
        SDL2.cleanBuff();

        output = Elastic_system_model_update(&esm);
        SDL2.drawLine(200+20,40,200+20,60);
        SDL2.drawLine(200+20,50,(uint8_t)output,50);
        SDL2.drawDisc((uint8_t)output,50,10,SDL2_DRAW_ALL);
        SDL2.sendBuff();

    }
    return 0;
}
