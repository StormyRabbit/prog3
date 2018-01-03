//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_GAMEENGINE_H
#define PROG3_GAMEENGINE_H


#include <SDL_video.h>
#include <SDL_render.h>
#include <vector>
#include "../level/Level.h"
#include "../level/LevelManager.h"
#include "World.h"
#include "../UserInput/UserInput.h"
#include "../UserInput/UserInputCallback.h"
#include "../UserInput/UserInputMgr.h"
#include "../util/Timer.h"
#include "../interfaces/Drawable.h"
namespace rootengine {
    class GameEngine  {
        public:
            void addLvl(Level *);
            void setPlayer(PhysicsSprite *);
            void setHUD(Drawable *);
            void addEvent(UserInputCallback *);
            void run();
            void handleNextLvl();
            int getScore();
            int getLives();
            void setFPS(int);
            static GameEngine* getInstance();
            ~GameEngine();
        protected:
            GameEngine();
        private:
            void createWorld();
            void runStartUpChecks();
            void preLoopProcess();
            UserInputMgr *usrInMgr = nullptr;
            int score{};
            int lives{};
            World *activeWorld = nullptr;
            bool running = true;
            LevelManager* lvlMgr = nullptr;
            Drawable *hud = nullptr;
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
