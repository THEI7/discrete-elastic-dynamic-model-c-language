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
        .stiffnes = 1,//刚力
        .damping = 0.1,//阻尼

        .obj_tar = 200,//目标位置
        .obj_now = 0,//当前位置
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
    elastic->a =(  ( (elastic->obj_tar - elastic->obj_now) * elastic->stiffnes ) - (elastic->mass * GRAVITY * elastic->damping)   )/ elastic->mass;
//    if((elastic->mass * GRAVITY * elastic->damping) >= ((elastic->tar - elastic->now) * elastic->stiffnes )) elastic->a = 0;//小球系统近似于谐振子系统
    //2. 计算当前帧
    elastic->obj_now = (elastic->v0 * elastic->T) + (elastic->a * elastic->T * elastic->T / 2);
    //3. 更新上一帧的信息
    elastic->obj_last = elastic->obj_now;
    printf("v0:%f a:%f  last:%f now:%f\r\n",elastic->v0,elastic->a,elastic->obj_last,elastic->obj_now);
    return elastic->obj_now;
}


int main() {

    SDL2.init();//初始化驱动

    for(;;)
    {
        SDL2.cleanBuff();
        SDL2.drawBox((uint8_t)Elastic_system_model_update(&esm),10,10,10);
        SDL2.sendBuff();
    }
    return 0;
}
