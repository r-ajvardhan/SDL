#include "Ball.h"
#include <cstdlib>

Ball::Ball()
{
    speed = 5.f;

    pos.x = screenWidth / 2 - size / 2;
    pos.y = screenHeight / 2 - size / 2;

    vel.x = 1;
    vel.y = -1;

    rect.x = (int)pos.x;
    rect.y = (int)pos.y;
    rect.w = rect.h = size;
}

void Ball::update(Paddle* L_Paddle , Paddle* R_Paddle)
{
    pos.x = pos.x + vel.x * speed * hits;
    pos.y = pos.y + vel.y * speed * hits;

    handleCollision(L_Paddle);
    handleCollision(R_Paddle);

    if(pos.x + size > screenWidth || pos.x < 0)
    {
        randomVel();
        hits = 1;
    }

    if (pos.y < 0)
    {
        pos.y = 0;
        vel.y *= -1;
    }
    else if (pos.y + size > screenHeight)
    {
        pos.y = screenHeight - size;
        vel.y *= -1;
    }

    rect.x = (int)pos.x;
    rect.y = (int)pos.y;
}

void Ball::handleCollision(Paddle *paddle)
{
    if (pos.x + size >= paddle->getPos().x && pos.x <= paddle->getPos().x + paddle->getRect()->w &&
        pos.y + size >= paddle->getPos().y && pos.y <= paddle->getPos().y + paddle->getRect()->h)
    {   
        hits += 0.1;
        vel.x *= -1;

        if (paddle->getID() == 0)
        {
            pos.x = paddle->getPos().x + paddle->getRect()->w;
        }
        else if (paddle->getID() == 1)
        {
            pos.x = paddle->getPos().x - size;
        }
    }
}

SDL_Rect *Ball::getRect()
{
    return &rect;
}

void Ball::randomVel()
{   
    pos.x = screenWidth / 2 - size / 2;
    pos.y = screenHeight / 2 - size / 2;

    SDL_Delay(100);

    vel.x *= -1;
    vel.y *= -1;
}