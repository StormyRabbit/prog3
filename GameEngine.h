//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_GAMEENGINE_H
#define PROG3_GAMEENGINE_H


#include <SDL_video.h>
#include <SDL_render.h>
#include <vector>
#include "HUD.h"
#include "Level.h"

class GameEngine : public Subject {
public:
    void initiateGameEngine();
    SDL_Window* createWindow(int width, int height);
    SDL_Renderer* createREnderer(SDL_Window* win);
    SDL_Surface* createSurface();
    void startLoop();

protected:

private:
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    bool running;
    HUD *hud;
    std::vector<Level*> levelsVector;

};


#endif //PROG3_GAMEENGINE_H
