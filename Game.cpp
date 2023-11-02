
#include "Game.h"

Game::Game() {
    screenWidth = 1440;
    screenHeight = 900;
}

Game::~Game() {
    if (map) { delete map; map = nullptr; }
    if (renderer) { delete renderer; renderer = nullptr; }
    if (gameWindow) { delete gameWindow; gameWindow = nullptr; }
    for (auto entity : entities) {
        if (entity) { delete entity; entity = nullptr; }
    }
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

    // init entities
    Color playerColor = {200, 40, 0, 255};
    player = new Player(200, 300, playerColor, renderer);
    entities.push_back(player);

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
        // Check for keypress events
        else if (e.type == SDL_KEYDOWN) {
            // Check which key was pressed
            switch (e.key.keysym.sym) {
                case SDLK_SPACE:
                    player->shoot();
                    break;
                case SDLK_UP:
                    player->move(UP);
                    break;
                case SDLK_DOWN:
                    player->move(DOWN);
                    break;
                case SDLK_LEFT:
                    player->move(LEFT);
                    break;
                case SDLK_RIGHT:
                    player->move(RIGHT);
                    break;
            }
        }
    }

}

void Game::update() {
    for (auto entity : entities) {
        entity->update();
    }
}

void Game::render() const {
    // render map
    map->render();

    // render entities
    for (auto entity : entities) {
        if (entity) { entity->render(); }
    }

    // Update screen
    renderer->render();
}
