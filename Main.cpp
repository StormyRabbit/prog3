//
// Created by lasse on 11/16/17.
//
#include "GameEngine.h"
#include "System.h"

int main(int, char **) {
    System sys;
    GameEngine* ge = new GameEngine();
    ge->run();
    return 0;
}

