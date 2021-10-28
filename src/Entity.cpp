#include "Entity.h"
#include "Texture.h"

Entity::Entity(int x, int y, Texture *texture, SDL_Rect *clip) :
    x(x), y(y), texture(texture), clip(clip) {
    return;
}

void Entity::update() {
    return;
}

void Entity::render() {
    scale = 0.01;
    texture->render(x, y, scale, clip);
}
