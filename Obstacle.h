#ifndef BLIND_SHOOTER_OBSTACLE_H
#define BLIND_SHOOTER_OBSTACLE_H

#include "MapEntity.h"
#include "Renderer.h"
#include "DataTypes.h"

class Obstacle : public MapEntity {
    int x;
    int y;
    int width;
    int height;
    Color color;
    Renderer *renderer;

public:
    Obstacle(int x, int y, int width, int height, Color color, Renderer *renderer);
    ~Obstacle();
    void render();

};


#endif //BLIND_SHOOTER_OBSTACLE_H
