
#include "Game.h"

Game::Game() : renderer(nullptr), window(nullptr), isRunning(false) {
    name = "Blind Shooter";
    width = 1200;
    height = 900;
}

Game::~Game() {}

bool Game::init() {
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
            width,                      // Width, in pixels
            height,                      // Height, in pixels
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

    isRunning = true;
    return true;
}

bool Game::running() const {
    return isRunning;
}

void Game::handleEvents() {
    // Event handler
    SDL_Event e;

    // Handle events on queue
    while (SDL_PollEvent(&e) != 0) {
        // User requests quit
        if (e.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Game::update() {

}

void Game::render() {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // TODO set color
    SDL_RenderClear(renderer);

    // Update screen
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    // Free resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
