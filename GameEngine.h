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
#include "LevelManager.h"

namespace rootengine {
    class GameEngine : public Subject {
    public:
        void setLvlMgr(LevelManager* lvlMgr);

        void setHUD(HUD *hud);

        void run();

        ~GameEngine();

        //Test med sprite ej final
        void addSprite();

        void drawTextures();
        //Slut med sprite test
    protected:
    private:
        bool running = true;
        LevelManager* lvlMgr;
        HUD *hud;
        std::vector<Level *> levelsVector;
        //Test med sprite ej final
        //slut med sprite test

    };
    extern SDL_Renderer *ren;
}
#endif //PROG3_GAMEENGINE_H
