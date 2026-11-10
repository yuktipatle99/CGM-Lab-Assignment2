#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
using namespace std;

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetMainReady();

    SDL_Window* window = SDL_CreateWindow(
        "Basic Graphics Primitives",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_SOFTWARE
    );

    // Background color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // 1. Straight Line
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 50, 100, 250, 100);

    // 2. Circle
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    int cx = 400, cy = 150, radius = 60;

    for (int angle = 0; angle < 360; angle++)
    {
        double rad = angle * 3.14159 / 180;

        int x = cx + radius * cos(rad);
        int y = cy + radius * sin(rad);

        SDL_RenderDrawPoint(renderer, x, y);
    }

    // 3. Rectangle
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_Rect rect = {50, 250, 200, 120};
    SDL_RenderDrawRect(renderer, &rect);

    // 4. Triangle
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

    SDL_RenderDrawLine(renderer, 400, 350, 550, 350);
    SDL_RenderDrawLine(renderer, 400, 350, 475, 220);
    SDL_RenderDrawLine(renderer, 475, 220, 550, 350);

    SDL_RenderPresent(renderer);

    cout << "Basic Graphics Primitives Drawn Successfully!";

    SDL_Event event;
    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;
        }
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}