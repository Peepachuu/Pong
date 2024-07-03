#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;

    window = SDL_CreateWindow(
        "Pong", 
        100, 
        100,
        1280,
        360,
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
    userRect.x = 0;
    userRect.y = 200;
    userRect.w = 30;
    userRect.h = 100;

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

            /*if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_d) {
                    printf("Move right");
                } else if (event.key.keysym.sym == SDLK_a) {
                    printf("Move left");
                } else if (event.key.keysym.sym == SDLK_w) {
                    printf("Move up");
                } else if (event.key.keysym.sym == SDLK_s) {
                    printf("Move down");
                }
            }*/
        }
        if (keyboardState[SDL_SCANCODE_D]) {
                    printf("Move right");
                } else if (keyboardState[SDL_SCANCODE_A]) {
                    printf("Move left");
                } else if (keyboardState[SDL_SCANCODE_W]) {
                    
                    userRect.y += -velocity;
                } else if (keyboardState[SDL_SCANCODE_S]) {
                    
                    userRect.y += velocity;
                }
         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &userRect);
        SDL_RenderFillRect(renderer, &userRect);
        SDL_RenderPresent(renderer);
        prevTime = currentTime;
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}