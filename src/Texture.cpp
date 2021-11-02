#include "Texture.h"
#include "Game.h"

Texture::Texture(const char *filePath, SDL_Renderer *renderer) : renderer(renderer) {
    tex = loadTexture(filePath);
}

Texture::~Texture() {
    SDL_DestroyTexture(tex);
}

// TODO needs documentation
void Texture::render(int x, int y, float scale, SDL_Rect *srcRect) {
    SDL_Rect dstRect = {x, y, width, height};

    if (srcRect != NULL) {
        dstRect.w = srcRect->w;
        dstRect.h = srcRect->h;
    }

    dstRect.w = (int)(dstRect.w * scale);
    dstRect.h = (int)(dstRect.h * scale);

    SDL_RenderCopy( renderer, tex, srcRect, &dstRect);
}

SDL_Texture *Texture::loadTexture(const char *filePath) {
    // load surface
    SDL_Surface *loadedSurface = IMG_Load(filePath);
    if (loadedSurface == nullptr) {
        fprintf(stderr, "Error loading surface '%s': %s\n", filePath, IMG_GetError());
        return nullptr;
    }

    // get dimensions
    width = loadedSurface->w;
    height = loadedSurface->h;

    // create texture from surface
    SDL_Texture *loadedTexture = nullptr;
    loadedTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (loadedTexture == nullptr) {
        fprintf(stderr, "Error creating texture from surface '%s': %s\n", filePath, SDL_GetError());
        return nullptr;
    }

    SDL_FreeSurface(loadedSurface);
    return loadedTexture;
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(tex, red, green, blue);
}

int Texture::getWidth() {
    return width;
}

int Texture::getHeight() {
    return height;
}

SDL_Texture *Texture::getTexture() {
    return tex;
}







/*
    SDL_Surface *optimizedSurface = nullptr;
    optimizedSurface = SDL_ConvertSurface(loadedSurface, surface->format, 0);
    if (optimizedSurface == nullptr) {
        fprintf(stderr, "Error converting optimized surface '%s': %s\n", filePath.c_str(), SDL_GetError());
        return nullptr;
    }
}
 */

