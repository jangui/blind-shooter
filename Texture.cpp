#include "Texture.h"
#include "Game.h"

Texture::Texture(const char *filePath, SDL_Renderer *renderer) {
    tex = loadTexture(filePath, renderer);
}

Texture::~Texture() {
    SDL_DestroyTexture(tex);
}

SDL_Texture *Texture::loadTexture(const char *filePath, SDL_Renderer *renderer) {
    // load surface
    SDL_Surface *loadedSurface = IMG_Load(filePath);
    if (loadedSurface == nullptr) {
        fprintf(stderr, "Error loading surface '%s': %s", filePath, IMG_GetError());
        return nullptr;
    }
    // handle transparent images
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

    // get dimensions
    width = loadedSurface->w;
    height = loadedSurface->h;

    // create texture from surface
    SDL_Texture *loadedTexture = nullptr;
    loadedTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (loadedTexture == nullptr) {
        fprintf(stderr, "Error creating texture from surface '%s': %s", filePath, SDL_GetError());
        return nullptr;
    }

    SDL_FreeSurface(loadedSurface);
    return loadedTexture;
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
SDL_Surface *loadSurface(std::string filePath, SDL_Surface *surface) {
    // load surface
    SDL_Surface *loadedSurface = IMG_Load(filePath.c_str());
    if (loadedSurface == nullptr) {
        fprintf(stderr, "Error loading surface '%s': %s\n", filePath.c_str(), IMG_GetError());
        return nullptr;
    }

    // convert loaded surface to optimized surface
    SDL_Surface *optimizedSurface = nullptr;
    optimizedSurface = SDL_ConvertSurface(loadedSurface, surface->format, 0);
    if (optimizedSurface == nullptr) {
        fprintf(stderr, "Error converting optimized surface '%s': %s\n", filePath.c_str(), SDL_GetError());
        return nullptr;
    }

    SDL_FreeSurface(loadedSurface);
    return optimizedSurface;
}
 */

