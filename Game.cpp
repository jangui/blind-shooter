
#include "Game.h"

Game::Game() :
    renderer(nullptr), gameWindow(nullptr), map(nullptr), isRunning(false), name("Blind Shooter"),
    virtualWidth(3200), virtualHeight(2000)
    {
    screenWidth = 1440;
    screenHeight = 900;
    }

Game::~Game() {
    delete map; map = nullptr;
    delete renderer; renderer = nullptr;
    delete gameWindow; gameWindow = nullptr;
}

bool Game::init() {
    // init game window
    gameWindow = new GameWindow(name, screenWidth, screenHeight);
    gameWindow->init();

    // init renderer
    SDL_Renderer *r = gameWindow->getRenderer();
    renderer = new Renderer(r, virtualWidth, virtualHeight, screenWidth, screenHeight);

    // init map
    map = new Map(virtualWidth, virtualHeight, renderer);

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
    map->render();

    // Update screen
    renderer->render();
}
