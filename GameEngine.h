//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_GAMEENGINE_H
#define PROG3_GAMEENGINE_H


#include <SDL_video.h>
#include <SDL_render.h>
#include <vector>
#include "HUD.h"
#include "Level.h"
#include "Subject.h"
#include "sprite.h"

class GameEngine : public Subject {
public:
    void initiateSDL();
    SDL_Window* createWindow(int width, int height);
    SDL_Renderer* createRenderer(SDL_Window* win);
    SDL_Surface* createSurface(std::string path, SDL_Window*);
    void startLoop(SDL_Window*, SDL_Surface*);
    ~GameEngine();
    //static GameEngine* getInstance();
    //Test med sprite ej final
    sprite* getSprite();
    void addSprite();
    void drawTextures();
    //Slut med sprite test
protected:
private:
    SDL_Renderer* ren;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
    bool running = true;
    HUD *hud;
    std::vector<Level*> levelsVector;
    //Test med sprite ej final
    sprite* sprites[0];
    //slut med sprite test

};
/*
GameEngine* GameEngine::getInstance() {
    return new GameEngine();
}
 */
#endif //PROG3_GAMEENGINE_H
