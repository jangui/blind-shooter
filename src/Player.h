#ifndef Player_H
#define Player_H

#include "Entity.h"

class Player: public Entity {
public:
    Player(int x, int y, Texture *texture, SDL_Rect *clip);
    void update();
    void modifyXVelocity(int velocity);
    void modifyYVelocity(int velocity);

private:
    int xVelocity;
    int yVelocity;
    int speed;
};

#endif // Player_H
