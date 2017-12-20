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

namespace rootengine {
    class GameEngine : public Subject {
        public:
            void setLvlMgr(LevelManager *);
            void setPlayer(Player *);
            void setHUD(class HUD *);
            void run();
            void handleNextLvl();
            int getScore();
            void createWorld();
            void setFPS(int, int);
            static GameEngine* getInstance();
            World* getWorld();
            ~GameEngine();
        protected:
            GameEngine() = default;
        private:
            int score;
            int screenFPS{};
            int tickRate{};
            Player *player{};
            World *activeWorld{};
            bool running = true;
            LevelManager* lvlMgr{};
            HUD *hud{};

        void endGame();
    };
}
#endif //PROG3_GAMEENGINE_H
