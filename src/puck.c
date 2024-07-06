#include <puck.h>
#include <time.h>

void UpdatePuckPos(puck_t* curPuck) {
    (curPuck->puckRect).x += (curPuck->velocityX) * (curPuck->xDir);
    (curPuck->puckRect).y += (curPuck->velocityY) * (curPuck->yDir);
}

void SetPuckDefaults(puck_t* curPuck) {
    srand(time(NULL));
    (curPuck->puckRect).h = 15;
    (curPuck->puckRect).w = 15;
    (curPuck->puckRect).x = 1280/2;
    (curPuck->puckRect).y = 720/2;
    curPuck->velocityX = rand() % (5 + 1 - 2) + 2;
    curPuck->velocityY = rand() % (5 + 1 - 2) + 2;
    curPuck->yDir = (rand() % 2 == 0) ? 1 : -1;
    curPuck->xDir = (rand() % 2 == 0) ? 1 : -1;
}