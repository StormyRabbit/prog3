//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_GAMEENGINE_H
#define PROG3_GAMEENGINE_H


#include <SDL_video.h>
#include <SDL_render.h>
#include <vector>
#include "hud/HUD.h"
#include "level/Level.h"
#include "util/Subject.h"
#include "level/LevelManager.h"
#include "World.h"
#include "UserInput.h"
#include "UserInputCallback.h"
#include "UserInputMgr.h"

namespace rootengine {
    class GameEngine : public Subject {
        public:
            void setLvlMgr(LevelManager *);
            void setPlayer(Player *);
            void setHUD(class HUD *);
            void setUsrInMgr(UserInputMgr *);
            void run();
            void handleNextLvl();
            int getScore();
            void createWorld();
            void setFPS(int);
            static GameEngine* getInstance();
            ~GameEngine();
        protected:
            GameEngine() = default;
        private:
            UserInputMgr *usrInMgr{};
            int score{};
            int tickRate{};
            World *activeWorld{};
            bool running = true;
            LevelManager* lvlMgr{};
            HUD *hud{};

        void endGame();
    };
}
#endif //PROG3_GAMEENGINE_H
