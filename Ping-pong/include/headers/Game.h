#pragma once


#include "Paddle.h"
#include "Ball.h"

class Game
{
public:
    bool Init();
    void gameLoop();
    void shutDown();

private:
    void draw();
    void handleInputs();
    void update();
    bool isRunning = true;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Paddle *leftPaddle, *rightPaddle;
    Ball *ball;
};