#include "Game.h"

Game::Game() {
    return;
}

Game::~Game() {
    return;
}

void Game::render() {
    // clear screen
    SDL_RenderClear(renderer);

    // render entities
    /*
    for (auto entity = entities.begin(); i != entities.end(); entity++) {
        entity->render(renderer);
    }
     */
    entity->render(renderer);

    // update screen
    SDL_RenderPresent(renderer);
}

void Game::update() {
    /*
    for (auto entity = entities.begin(); i != entities.end(); entity++) {
        entity->update();
    }
    */
    Player *player = static_cast<Player*>(entity);
    player->update();
}

bool Game::init(const char *title, const int width, const int height) {
    //bool initGame(SDL_Window **window, SDL_Surface **screenSurface, SDL_Renderer **renderer) {
    // initialize SDL Video
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return false;
    }

    // create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return false;
    }

    // create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // init png loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        fprintf(stderr, "Error initializing PNG loading: %s\n", IMG_GetError());
        return false;
    }

    /* TODO
    // create surface
    *screenSurface = SDL_GetWindowSurface(*window);
    if (*screenSurface == nullptr) {
        fprintf(stderr, "Error creating surface: %s\n", SDL_GetError());
        return false;
    }
     */

    // init entities
    entity = new Player("./red.png", 200, 100, renderer);

    isRunning = true;
    return true;
}

void Game::handleEvents() {
    // poll for events
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            isRunning = false;
        } else if (e.type == SDL_KEYDOWN) {
            // handle keydown events
            Player *player = static_cast<Player*>(entity);
            switch(e.key.keysym.sym) {
                case SDLK_w:
                    if (player != nullptr) player->modifyYVelocity(-1);
                    break;
                case SDLK_s:
                    if (player != nullptr) player->modifyYVelocity(1);
                    break;
                case SDLK_a:
                    if (player != nullptr) player->modifyXVelocity(-1);
                    break;
                case SDLK_d:
                    if (player != nullptr) player->modifyXVelocity(1);
                    break;
                //case SDLK_SPACE:
                case SDLK_DELETE:
                    isRunning = false;
                    break;
                default:
                    break;
            }
        }
    }
}

bool Game::running() {
    return isRunning;
}

/*
SDL_Renderer *Game::getRenderer() {
    return renderer;
}
*/

void Game::clean() {
    //SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}

