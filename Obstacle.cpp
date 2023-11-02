
#include "Obstacle.h"

Obstacle::Obstacle(int x, int y, int width, int height, Color color, Renderer *renderer) :
    x(x), y(y), width(width), height(height), color(color), renderer(renderer) {}

Obstacle::~Obstacle() {}

void Obstacle::render() {
    renderer->drawRect(x, y, width, height, color);
}
