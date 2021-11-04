#include <stdio.h>

#include "Game.h"
#include "Settings.h"


// TODO check includes & headers files

int main(int argc, char *argv[]) {
    // initialize game
    Settings *settings = new Settings();
    Game *game = new Game(settings);
    bool init = game->init();
    if (!init) {
        fprintf(stderr, "Error initializing game\n");
        return 1;
    }

    Uint32 frameStart;
    int frameTime;
    // main game loop
    while (game->running()) {

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        // cap frame rate
        frameTime = SDL_GetTicks() - frameStart;
        if (settings->frameDelay > frameTime) SDL_Delay(settings->frameDelay - frameTime);

    }

   // clean up
   game->clean();
   return 0;
}
