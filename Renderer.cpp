
#include "Renderer.h"
#include "SDL.h"

Renderer::Renderer(SDL_Renderer *renderer, int virtualWidth, int virtualHeight, int screenWidth, int screenHeight) :
    r(renderer), virtualWidth(virtualWidth), virtualHeight(virtualHeight),
    screenWidth(screenWidth), screenHeight(screenHeight)
{
    xScaleFactor = static_cast<float>(screenWidth) / static_cast<float>(virtualWidth);
    yScaleFactor = static_cast<float>(screenHeight) / static_cast<float>(virtualHeight);
}

Renderer::~Renderer() {}

void Renderer::render() const {
    SDL_RenderPresent(r);
}

Coordinates Renderer::virtualToScreen(int x, int y) const {
    float screenX = static_cast<float>(x) * xScaleFactor;
    float screenY = static_cast<float>(y) * yScaleFactor;
    return {static_cast<int>(screenX), static_cast<int>(screenY)};
}

void Renderer::clearScreen(Color color) const {
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);
    SDL_RenderClear(r);
}

void Renderer::drawRect(int x, int y, int width, int height, Color color) const {
    Coordinates topLeft = virtualToScreen(x, y);
    Coordinates dimensions = virtualToScreen(width, height);
    SDL_Rect rect = {topLeft.x, topLeft.y, dimensions.x, dimensions.y};
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(r, &rect);
}



