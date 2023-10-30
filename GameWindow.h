#ifndef BLIND_SHOOTER_GAMEWINDOW_H
#define BLIND_SHOOTER_GAMEWINDOW_H

#include <SDL.h>
#include <string>

class GameWindow {
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::string name;
    int screenWidth;
    int screenHeight;

public:
    GameWindow(std::string name, int screenWidth, int screenHeight);
    ~GameWindow();
    bool init();
    SDL_Renderer *getRenderer() const;


};


#endif //BLIND_SHOOTER_GAMEWINDOW_H
