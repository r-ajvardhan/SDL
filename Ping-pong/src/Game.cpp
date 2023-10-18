#include "Game.h"

bool Game::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        return false;
    }

    window = SDL_CreateWindow("Ping-Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (!window)
    {
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        return false;
    }

    leftPaddle = new Paddle(0);
    rightPaddle = new Paddle(1);

    ball = new Ball();

    return true;
}

void Game::gameLoop()
{
    while (isRunning)
    {
        handleInputs();
        update();
        draw();
    }
}

void Game::shutDown()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// private member functions:

void Game::handleInputs()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_ESCAPE])
    {
        isRunning = false;
    }
    
    //left paddle
    leftPaddle->setDirection(0);
    if (keystates[SDL_SCANCODE_W])
    {
        leftPaddle->setDirection(-1);
    }
    if (keystates[SDL_SCANCODE_S])
    {
        leftPaddle->setDirection(1);
    }

    //right paddle
    rightPaddle->setDirection(0);
    if (keystates[SDL_SCANCODE_UP])
    {
        rightPaddle->setDirection(-1);
    }
    if (keystates[SDL_SCANCODE_DOWN])
    {
        rightPaddle->setDirection(1);
    }
}

void Game::update()
{
    leftPaddle->update();
    rightPaddle->update();

    ball->update(leftPaddle , rightPaddle);
}

void Game::draw()
{
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    //draw paddles
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, leftPaddle->getRect());
    SDL_RenderFillRect(renderer, rightPaddle->getRect());

    //draw ball
    SDL_SetRenderDrawColor(renderer, 250, 250, 250, 255);
    SDL_RenderFillRect(renderer, ball->getRect());

    SDL_RenderPresent(renderer);
}
