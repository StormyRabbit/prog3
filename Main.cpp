//
// Created by lasse on 11/16/17.
//

#include <iostream>
#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include <SDL.h>
#include <vector>
#include "GameEngine.h"
#include "Level.h"
#include "HUD.h"

Uint32 rmask;
Uint32 gmask;
Uint32 bmask;
Uint32 amask;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
std::vector<Level*> levelsVector;
HUD *hud;
bool running;
int main(int argc, char *argv[]) {
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;

    return 0;
}

