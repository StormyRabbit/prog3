//
// Created by lasse on 11/28/17.
//

#ifndef PROG3_SYSTEM_H
#define PROG3_SYSTEM_H


#include <SDL_render.h>
namespace rootengine {
    class System {
    public:
        System();

        ~System();

        SDL_Renderer *getRenderer();

    private:
        void createWindow(int width, int height, std::string name);

        void createRenderer();

        void init();

        SDL_Window *win;
        SDL_Renderer *ren;
    };

    extern System sys;
}
#endif //PROG3_SYSTEM_H
