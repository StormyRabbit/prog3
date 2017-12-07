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
#include "World.h"

namespace rootengine {
    class GameEngine : public Subject {
        public:
            void setLvlMgr(LevelManager* lvlMgr);
            void setPlayer(Player *player);
            void setHUD(HUD *hud);
            void run();
            void createWorld();
            static GameEngine* getInstance();
            ~GameEngine();
        protected:
            GameEngine() = default;
        private:
            Player *player{};
            World* activeWorld{};
            bool running = true;
            LevelManager* lvlMgr{};
            HUD *hud{};
    };
}
#endif //PROG3_GAMEENGINE_H
