
#include "Game.h"

Game::Game() :
    renderer(nullptr), gameWindow(nullptr), map(nullptr), isRunning(false), name("Blind Shooter"),
    virtualWidth(3200), virtualHeight(2000)
    {
    screenWidth = 1440;
    screenHeight = 900;
    }

Game::~Game() {
    if (map) { delete map; map = nullptr; }
    if (renderer) { delete renderer; renderer = nullptr; }
    if (gameWindow) { delete gameWindow; gameWindow = nullptr; }
}

bool Game::init() {
    // init game window
    gameWindow = new GameWindow(name, screenWidth, screenHeight);
    gameWindow->init();

    // init renderer
    SDL_Renderer *r = gameWindow->getRenderer();
    renderer = new Renderer(r, virtualWidth, virtualHeight, screenWidth, screenHeight);

    // init map
    Color backgroundColor = {40,0,0,255};
    Color borderColor = {0, 0, 40, 255};
    int borderWidth = 20;
    int borderHeight = 20;
    int borderSpacer = 20;
    MapSettings mapSettings = {backgroundColor, borderColor, borderWidth, borderHeight, borderSpacer};
    map = new Map(virtualWidth, virtualHeight, mapSettings, renderer);

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

void Game::render() const {
    map->render();

    // Update screen
    renderer->render();
}
