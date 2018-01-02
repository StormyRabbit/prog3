//
// Created by lasse on 12/7/17.
// based on http://lazyfoo.net/tutorials/SDL/23_advanced_timers/index.php
//

#ifndef PROG3_TIMER_H
#define PROG3_TIMER_H

#include <SDL_quit.h>

namespace rootengine {
    class Timer {
    public:
        void start();
        Uint32 getTicks();
        static Timer* getInstance();
    protected:
        Timer() = default;
    private:
        Uint32 startTicks;
        Uint32 pausedTicks;
        bool started;

    };
}



#endif //PROG3_TIMER_H
