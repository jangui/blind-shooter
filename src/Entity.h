#ifndef Entity_H
#define Entity_H

#include "SDL2/SDL.h"

#include "Texture.h"
#include "Settings.h"

class Entity {
public:
    Entity(int x, int y, Texture *texture, SDL_Rect *clip);
    virtual void update();
    void render();
protected:
    int x, y;
    float scale;
    Texture *texture;
    SDL_Rect *clip;
    Settings *s;
};


#endif // Entity_H
