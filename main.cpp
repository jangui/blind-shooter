#include "Game.h"

int main() {
    Game game = Game();
    game.init();

    while (game.running()) {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();
    return 0;
}
