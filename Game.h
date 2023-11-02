#ifndef BLIND_SHOOTER_GAME_H
#define BLIND_SHOOTER_GAME_H

#include <SDL.h>
#include <string>

#include "GameWindow.h"
#include "Renderer.h"
#include "Map.h"


class Game {
    GameWindow *gameWindow;
    Renderer *renderer;
    Map *map;
    bool isRunning;
    std::string name;
    int virtualWidth;
    int virtualHeight;
    int screenWidth;
    int screenHeight;

public:
    Game();
    ~Game();
    void handleEvents();
    void update();
    void render() const;
    bool init();
    bool running() const;
};

#endif //BLIND_SHOOTER_GAME_H
