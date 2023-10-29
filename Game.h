#ifndef BLIND_SHOOTER_GAME_H
#define BLIND_SHOOTER_GAME_H

#include <SDL.h>
#include <string>

class Game {
    SDL_Renderer *renderer;
    SDL_Window *window;
    bool isRunning;
    std::string name;
    int width;
    int height;

public:
    Game();
    ~Game();
    void handleEvents();
    void update();
    void render();
    void clean();
    bool init();
    bool running() const;

};

#endif //BLIND_SHOOTER_GAME_H
