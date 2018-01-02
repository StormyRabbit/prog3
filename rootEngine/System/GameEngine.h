//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_GAMEENGINE_H
#define PROG3_GAMEENGINE_H


#include <SDL_video.h>
#include <SDL_render.h>
#include <vector>
#include "../../hud/HUD.h"
#include "../level/Level.h"
#include "../level/LevelManager.h"
#include "World.h"
#include "../UserInput/UserInput.h"
#include "../UserInput/UserInputCallback.h"
#include "../UserInput/UserInputMgr.h"
#include "../util/Timer.h"

namespace rootengine {
    class GameEngine  {
        public:
            void setLvlMgr(LevelManager *);
            void setPlayer(PhysicsSprite *);
            void setHUD(class HUD *);
            void setUsrInMgr(UserInputMgr *);
            void run();
            void handleNextLvl();
            int getScore();
            int getLives();
            void createWorld();
            void setFPS(int);
            static GameEngine* getInstance();
            ~GameEngine();
        protected:
            GameEngine() = default;
        private:
            void runStartUpChecks();
            void preLoopProcess();
            UserInputMgr *usrInMgr = nullptr;
            int score{};
            int lives{};
            World *activeWorld = nullptr;
            bool running = true;
            LevelManager* lvlMgr = nullptr;
            HUD *hud = nullptr;
            // FPS cap stuff
            int tickRate{};
            void startFPSTimers();
            void pauseTickDur();
            Timer *fpsTimer = nullptr;
            Timer *capTimer = nullptr;
        void endGame();
    };
}
#endif //PROG3_GAMEENGINE_H
