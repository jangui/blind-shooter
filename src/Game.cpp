#include "Game.h"

Game::Game(Settings *settings) : s(settings) {
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
        entity->render();
    }
     */
    entity->render();

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

bool Game::init() {
    // initialize SDL Video
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return false;
    }

    // create window
    window = SDL_CreateWindow("Blind Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, s->screenWidth, s->screenHeight, SDL_WINDOW_SHOWN);
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

    // init textures
    // TODO: make this own function, and fix hardcoded values with settings values (sprite sheet path, rows, etc)
    //       refractor rest of game.init()
    //       specific entities should know the
    spriteSheet = new Texture("../assets/sprite-sheet.png", renderer);
    int xOffset, yOffset;
    int spriteWidth = spriteSheet->getWidth() / 4; // TODO spriteSheet->numRows
    int spriteHeight = spriteSheet->getHeight() / 4;
    SDL_Rect *currClip;
    for (int i = 0; i < 16; i++) {
        xOffset = (i % 4) * spriteSheet->getWidth() / 4;
        yOffset = ((int)i/4 ) * spriteSheet->getHeight() / 4;
        currClip = new SDL_Rect();
        currClip->x = xOffset;
        currClip->y = yOffset;
        currClip->w = spriteWidth;
        currClip->h = spriteHeight;
        spriteClips.push_back(currClip);
    }

    // init entities
    entity = new Player(200, 100, spriteSheet, spriteClips[1]);

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

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}

