#ifndef BLIND_SHOOTER_MAP_H
#define BLIND_SHOOTER_MAP_H

#include <SDL.h>
#include "DataTypes.h"
#include "Renderer.h"

class Map {
    int width;
    int height;
    Renderer *renderer;
    int borderWidth;
    int borderHeight;
    Color bgColor;
    Color borderColor;

public:
    Map(int width, int height, Renderer *renderer);
    ~Map();
    void render() const;
    void renderBorder() const;
    void update();
};

#endif //BLIND_SHOOTER_MAP_H
