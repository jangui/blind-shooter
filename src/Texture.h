#ifndef Texture_H
#define Texture_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {
public:
    Texture(const char *filePath, SDL_Renderer *renderer);
    ~Texture();
    SDL_Texture *loadTexture(const char *filePath);
    void render(int x, int y, float scale, SDL_Rect *srcRect);
    void setColor(Uint8, Uint8 green, Uint8 blue);
    int getWidth();
    int getHeight();
    SDL_Texture *getTexture();
private:
    int width;
    int height;
    SDL_Texture *tex;
    SDL_Renderer *renderer;
};


#endif // Texture_H
