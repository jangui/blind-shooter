#ifndef _Texture_H_
#define _Texture_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {
public:
    Texture(const char *filePath, SDL_Renderer *renderer);
    ~Texture();
    SDL_Texture *loadTexture(const char *filePath, SDL_Renderer *renderer);
    int getWidth();
    int getHeight();
    SDL_Texture *getTexture();
private:
    int width;
    int height;
    SDL_Texture *tex;
};


#endif // _Texture_H_
