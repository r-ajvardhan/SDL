#pragma once

#include "Common.h"

class Paddle
{
public:
    Paddle(int i);
    void update();
    void setDirection(int dir);
    
    int getID();

    SDL_Rect* getRect();
    Vec2 getPos();

private:
    int id; //leftpaddle id = 0 and rightpaddle id = 1
    int direction = 0; // 0 = sationary , 1 and -1 for up and down
    int width = 20;
    int height = 120;
    float speed;

    Vec2 pos;
    SDL_Rect rect;
};