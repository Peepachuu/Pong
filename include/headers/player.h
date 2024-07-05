#include <SDL.h>

typedef struct player {
    SDL_Rect playerRect;
    int points;
    int direction;
    int velocity;
} player_t;

void updatePlayerPos(player_t* p1, short WPressed, short SPressed);
void setPlayerDefaults(player_t* p1);