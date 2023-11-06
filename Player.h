
#ifndef BLIND_SHOOTER_PLAYER_H
#define BLIND_SHOOTER_PLAYER_H

#include "Entity.h"
#include "Renderer.h"

class Player : public Entity {
   int x;
   int y;
   float vx;
   float vy;
   float speed = 3;
   Color color;
   Renderer *renderer;

public:
    Player(int x, int y, Color color, Renderer *renderer);
    ~Player();
    void render();
    void update();
    void shoot();
    void move(Direction direction);
};


#endif //BLIND_SHOOTER_PLAYER_H
