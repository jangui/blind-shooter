#ifndef Game_H
#define Game_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
//#include <map>

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
    SDL_Renderer *renderer; // TODO figure out how to not constantly pass this around?
    //SDL_Surface *screenSurface;
    SDL_Event e;
    //std::map<const char*, Entity> entities;
    Entity *entity;
    Texture *spriteSheet;
    Settings *s;
    SDL_Rect playerClip;
    Texture *red;

};

#endif // Game_H
