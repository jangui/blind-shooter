//
// Created by Jaime on 10/30/23.
//

#include "GameWindow.h"

GameWindow::GameWindow(std::string name, int screenWidth, int screenHeight) :
   name(name), screenWidth(screenWidth), screenHeight(screenHeight),
   window(nullptr), renderer(nullptr) {}

GameWindow::~GameWindow() {
    // Free resources
    if (renderer != nullptr) { SDL_DestroyRenderer(renderer); }
    if (window != nullptr) { SDL_DestroyWindow(window); }
    SDL_Quit();
}

bool GameWindow::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    // Create a window
    window = SDL_CreateWindow(
            name.c_str(),            // Window title
            SDL_WINDOWPOS_UNDEFINED,  // Initial x position
            SDL_WINDOWPOS_UNDEFINED,  // Initial y position
            screenWidth,                      // Width, in pixels
            screenHeight,                      // Height, in pixels
            SDL_WINDOW_SHOWN          // Flags
    );
    if (window == nullptr) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
}

SDL_Renderer *GameWindow::getRenderer() const {
    return renderer;
}
