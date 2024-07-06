#include <player.h>

void updatePlayerPos(player_t* p1, short WPressed, short SPressed) {
    p1->direction = 0;
    if (WPressed && SPressed) {
        p1->direction = 0;
    } else if (WPressed) {
        p1->direction = -1;
    } else if (SPressed) {
        p1->direction = 1;
    }
    if (p1->direction != 0)
        (p1->playerRect).y += (p1->velocity)*(p1->direction);

    if ((p1->playerRect).y < 0)
        (p1->playerRect).y = 0;
    if ((p1->playerRect).y > 570)
        (p1->playerRect).y = 570;
}

void setPlayerDefaults(player_t* p1) {
    (p1->playerRect).x = 0;
    (p1->playerRect).y = 200;
    (p1->playerRect).w = 30;
    (p1->playerRect).h = 150;
    p1->points = 0;
    p1->velocity = 8;
}