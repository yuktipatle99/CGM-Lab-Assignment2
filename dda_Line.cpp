#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int x1, y1, x2, y2;

    cout << "Enter starting point (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter ending point (x2, y2): ";
    cin >> x2 >> y2;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xIncrement = (float)dx / max(steps, 1);
    float yIncrement = (float)dy / max(steps, 1);

    float x = x1;
    float y = y1;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL Initialization Failed!";
        return 1;
    }

    SDL_SetMainReady();

    SDL_Window* window = SDL_CreateWindow(
        "DDA Line Drawing Algorithm",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_SOFTWARE
    );

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int i = 0; i <= steps; i++)
    {
        SDL_RenderDrawPoint(renderer, round(x), round(y));

        x += xIncrement;
        y += yIncrement;
    }

    SDL_RenderPresent(renderer);

    cout << "DDA Line Drawn Successfully!";

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