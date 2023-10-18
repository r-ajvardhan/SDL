#pragma once

#include "Paddle.h"

class Ball
{
public:
    Ball();
    void update(Paddle* L_Paddle, Paddle* R_Paddle);
    void handleCollision(Paddle* paddle);

    void randomVel();
    SDL_Rect* getRect();

private:
    int size = 20;
    int direction = 0;
    float speed;

    float hits=1;
    
    Vec2 pos;
    Vec2 vel;
    SDL_Rect rect;

};