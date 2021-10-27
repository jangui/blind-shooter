#include "Entity.h"
#include "Texture.h"

Entity::Entity(const char *textureFilePath, int x, int y, SDL_Renderer *renderer) {
    texture =  new Texture(textureFilePath, renderer);
    rect.x = x;
    rect.y = y;
    rect.w = texture->getWidth();
    rect.h = texture->getHeight();
}

void Entity::update() {
    return;
}

void Entity::render(SDL_Renderer *renderer) {
    SDL_RenderCopy( renderer, texture->getTexture(), NULL, &rect);
}
