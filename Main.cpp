//
// Created by lasse on 11/16/17.
//
#include "GameEngine.h"
#include "Level.h"
#include "HUD.h"

int main(int, char **){
    auto* ge = new GameEngine();
    ge->initiateSDL();
    auto* win = ge->createWindow(400,400);
    auto* ren = ge->createRenderer(win);
    auto* surf = ge->createSurface("C:\\Users\\lasse\\CLionProjects\\prog3\\sprites\\bgcastle.png", win);
    ge->startLoop();
    return 0;
}

