
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
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) {
        player->move(UP);
    }
    if (state[SDL_SCANCODE_DOWN]) {
        player->move(DOWN);
    }
    if (state[SDL_SCANCODE_LEFT]) {
        player->move(LEFT);
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        player->move(RIGHT);
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

void Game::calcDeltaTime() {
    currentFrameTime = SDL_GetTicks();
    deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;
}

void Game::capFPS() {
    Uint32 frameDuration = SDL_GetTicks() - currentFrameTime;
    if ( (1000 / fps) > frameDuration ) {
        SDL_Delay( (1000/fps) - frameDuration);
    }
}
