#include "Game.h"

int main() {
    Game game = Game();
    if (!game.init()) { fprintf(stderr, "Game failed to initialize"); return 1; }

    while (game.running()) {
        game.calcDeltaTime();
        game.handleEvents();
        game.update();
        game.render();
        game.capFPS();
    }

    return 0;
}
