//
// Created by lasse on 11/16/17.
//

#ifndef PROG3_GAMEENGINE_H
#define PROG3_GAMEENGINE_H
void sdlInit();
SDL_Window* createWindow();
SDL_Renderer* createRender(SDL_Window*);
SDL_Surface *createSurface();

#endif //PROG3_GAMEENGINE_H
