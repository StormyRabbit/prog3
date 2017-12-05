//
// Created by lasse on 11/28/17.
//

#ifndef PROG3_SYSTEM_H
#define PROG3_SYSTEM_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_render.h>
#include <SDL_ttf.h>
namespace rootengine {
    class System {
    public:
        System();

        ~System();

        SDL_Renderer *getRenderer() const;
        TTF_Font* getFont() const;

    private:
        void createWindow(int width, int height, std::string name);
        void createFont(std::string path, int size);
        void createRenderer();

        void init();

        SDL_Window *win;
        SDL_Renderer *ren;
        TTF_Font* mainFont;
    };

    extern System sys;
}
#endif //PROG3_SYSTEM_H
