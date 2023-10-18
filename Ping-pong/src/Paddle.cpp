#include "Paddle.h"

Paddle::Paddle(int i)
{
    id = i;
    speed = 12.f;

    if( id == 0)
    {
        pos.x = 0;
    }
    else if ( id == 1 )
    {
        pos.x = screenWidth - width;
    }

    pos.y = screenHeight/2 - height/2;

    rect.x = (int)pos.x;
    rect.y = (int)pos.y;
    rect.h = height;
    rect.w = width;
}
void Paddle::update()
{
    pos.y = pos.y + speed*direction;

    if(pos.y < 0)
    {
        pos.y = 0;
    }
    else if( pos.y + height > screenHeight)
    {
        pos.y = screenHeight - height;
    }

    rect.y = pos.y;
}
void Paddle::setDirection(int dir)
{
    direction = dir;
}
    
SDL_Rect* Paddle::getRect()
{
    return &rect;
}

Vec2 Paddle::getPos()
{
    return pos;
}

int Paddle::getID()
{
    return id;
}