#ifndef _Entity_H_
#define _Entity_H_

#include "SDL2/SDL.h"

#include "Texture.h"

class Entity {
public:
    Entity(const char *textureFilePath, int x, int y, SDL_Renderer *renderer);
    virtual void update();
    void render(SDL_Renderer *renderer);
protected:
    SDL_Rect rect;
    Texture *texture;
};


#endif // _Entity_H_
