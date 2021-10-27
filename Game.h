#ifndef _Game_H_
#define _Game_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
//#include <map>

#include "Entity.h"
#include "Player.h"

class Game {
public:
    Game();
    ~Game();
    bool init(const char *title, const int width, const int height);
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

};

#endif // _Game_H_
