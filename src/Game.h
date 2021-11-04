#ifndef Game_H
#define Game_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>

#include "Entity.h"
#include "Player.h"
#include "Settings.h"

class Game {
public:
    Game(Settings *s);
    ~Game();
    bool init();
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Entity *entity;
    Texture *spriteSheet;
    std::vector<SDL_Rect*> spriteClips;
    Settings *s;
    SDL_Rect playerClip;

};

#endif // Game_H
