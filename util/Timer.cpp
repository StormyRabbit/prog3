//
// Created by lasse on 12/7/17.
//

#include <SDL_timer.h>
#include "Timer.h"
namespace {

}

bool rootengine::Timer::isPaused() {
    return started && paused;
}

bool rootengine::Timer::isStarted() {
    return started;
}

int rootengine::Timer::getTicks() {
    int time = 0;

    if(started)
        time = pausedTicks;
    else
        time = SDL_GetTicks() -startTicks;

    return time;
}

void rootengine::Timer::unpause() {
    if(started && paused) {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

void rootengine::Timer::pause() {
    if(started && !paused) {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
        startTicks = 0;
    }

}

void rootengine::Timer::start() {
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
    pausedTicks = 0;
}

void rootengine::Timer::stop() {
    started = false;
    paused = false;
    startTicks = 0;
    pausedTicks = 0;
}

rootengine::Timer *rootengine::Timer::getInstance() {
    return new Timer();
}
