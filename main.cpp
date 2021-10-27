#include <stdio.h>

#include "Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// TODO check includes & headers files

int main(int argc, char *argv[]) {
    // initialize game
    Game *game = new Game();
    bool init = game->init("Blind Shooter", SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!init) {
        fprintf(stderr, "Error initializing game\n");
        return 1;
    }

    // main game loop
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

   // clean up
   game->clean();
   return 0;
}



/*
// get surface and draw white background
//SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

//SDL_Texture *texture = nullptr;
//texture = loadTexture("./red.png", renderer);

// clear screen
//SDL_SetRenderDrawColor( renderer,0xFF,0xFF,0xFF,0xFF );

// render textures to screen
//SDL_RenderCopy(renderer, texture, nullptr, nullptr);

// render rect
SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
SDL_RenderFillRect( renderer, &fillRect );
SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0x00 );

for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
    SDL_RenderDrawPoint( renderer, SCREEN_WIDTH / 2, i );
}


// update window
//SDL_UpdateWindowSurface(window);
 */
