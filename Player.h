#ifndef _Player_H_
#define _Player_H_

#include "Entity.h"

class Player: public Entity {
public:
    Player(const char *textureFilePath, int x, int y, SDL_Renderer *renderer);
    void update();
    void modifyXVelocity(int velocity);
    void modifyYVelocity(int velocity);

private:
    int xVelocity;
    int yVelocity;
    int speed;
};


#endif // _Player_H_
