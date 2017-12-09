//
// Created by lasse on 12/7/17.
//

#ifndef PROG3_TIMER_H
#define PROG3_TIMER_H

#include <SDL_quit.h>

namespace rootengine {
    class Timer {
    public:
        void start();
        void stop();
        void pause();
        void unpause();

        int getTicks();

        bool isStarted();
        bool isPaused();

        static Timer* getInstance();
    protected:
        Timer() = default;
    private:
        int startTicks;
        int pausedTicks;
        bool paused;
        bool started;

    };
}



#endif //PROG3_TIMER_H
