#ifndef BLIND_SHOOTER_GAME_H
#define BLIND_SHOOTER_GAME_H

#include <SDL.h>
#include <string>
#include <vector>

#include "GameWindow.h"
#include "Renderer.h"
#include "Map.h"
#include "Entity.h"
#include "Player.h"

class Game {
    Player *player = nullptr;
    std::vector<Entity*> entities;
    GameWindow *gameWindow = nullptr;
    Renderer *renderer = nullptr;
    Map *map = nullptr;
    bool isRunning = false;
    std::string name = "Blind Shooter";
    int virtualWidth = 3200;
    int virtualHeight = 2000;
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
