//
// Created by lasse on 12/7/17.
//

#include <SDL_timer.h>
#include "Timer.h"
namespace rootengine {
    Uint32 Timer::getTicks() {
        Uint32 time = 0;
        if(started)
            time = pausedTicks;
        else
            time = SDL_GetTicks() -startTicks;
        return time;
    }

    void Timer::start() {
        started = true;
        startTicks = SDL_GetTicks();
        pausedTicks = 0;
    }

    Timer *rootengine::Timer::getInstance() {
        return new Timer();
    }
}
