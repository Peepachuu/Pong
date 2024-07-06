#include <SDL.h>

typedef struct puck {
    SDL_Rect puckRect;
    int velocityX;
    int velocityY;
    int xDir;
    int yDir;
} puck_t;

void UpdatePuckPos(puck_t* curPuck);
void SetPuckDefaults(puck_t* curPuck);

