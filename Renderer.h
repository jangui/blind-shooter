#ifndef BLIND_SHOOTER_RENDERER_H
#define BLIND_SHOOTER_RENDERER_H

#include <SDL.h>
#include "DataTypes.h"

class Renderer {
    SDL_Renderer *r;
    int virtualWidth;
    int virtualHeight;
    int screenWidth;
    int screenHeight;
    float xScaleFactor;
    float yScaleFactor;

public:
    Renderer(SDL_Renderer *renderer, int virtualWidth, int virtualHeight, int screenWidth, int screenHeight);
    ~Renderer();
    void render() const;
    Coordinates virtualToScreen(int x, int y) const;
    void clearScreen(Color color) const;
    void drawRect(int x, int y, int width, int height, Color color) const;
};


#endif //BLIND_SHOOTER_RENDERER_H
