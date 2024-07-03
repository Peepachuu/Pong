#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

const int SCREEN_HEIGHT = 720;
const int SCREEN_WIDTH = 1280;


void PlaceCenterRects(SDL_Renderer* renderer) {
    int currentY = 0;
    const int rectWidth = 10, rectHeight = 55, gap = 95, rectCount = 8;

    for (int i = 0; i < rectCount; ++i) {
        SDL_Rect currentRect;
        currentRect.h = rectHeight;
        currentRect.w = rectWidth;
        currentRect.x = SCREEN_WIDTH/2 - rectWidth/2;
        currentRect.y = currentY;

        SDL_RenderDrawRect(renderer, &currentRect);
        SDL_RenderFillRect(renderer, &currentRect);
        currentY += gap;
    }
}

int main(int argc, char *argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;

    window = SDL_CreateWindow(
        "Pong", 
        100, 
        100,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL
    );

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    
    if (window == NULL) {
        printf("Window was not created properly.");
        return 1;
    }

    const Uint8 *keyboardState;
    int velocity = 8;
    bool gameIsRunning = true;
    SDL_Rect userRect;
    SDL_Rect ball;
    SDL_Rect centerRect;

    userRect.x = 0;
    userRect.y = 200;
    userRect.w = 30;
    userRect.h = 150;

    ball.x = SCREEN_WIDTH/2;
    ball.y = SCREEN_HEIGHT/2;
    ball.w = 15;
    ball.h = 15;

    uint32_t prevTime = SDL_GetTicks();
    uint32_t currentTime;

    while (gameIsRunning) {

        currentTime = SDL_GetTicks();
        if (currentTime - prevTime < (1000/60.0)) {
            continue;
        }
        SDL_RenderClear(renderer);
        SDL_Event event;
        
        keyboardState = SDL_GetKeyboardState(NULL);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameIsRunning = false;
            }
        }
        if (keyboardState[SDL_SCANCODE_W]) {
            userRect.y += -velocity;
        } else if (keyboardState[SDL_SCANCODE_S]) {
            userRect.y += velocity;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // SDL_RenderDrawLine(renderer, SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT);
        PlaceCenterRects(renderer);
        SDL_RenderDrawRect(renderer, &userRect);
        SDL_RenderFillRect(renderer, &userRect);
        SDL_RenderDrawRect(renderer, &ball);
        SDL_RenderFillRect(renderer, &ball);
        SDL_RenderPresent(renderer);
        prevTime = currentTime;
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}