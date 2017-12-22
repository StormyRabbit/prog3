//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PLAYER_H
#define PROG3_PLAYER_H

#include <map>
#include "../PhysicsSprite.h"
#include "PlayerState.h"


namespace rootengine {
    class Player : public PhysicsSprite {
    public:
        static Player *getInstance(int xPos, int yPos, int width, int height, std::map<std::string, std::string> strings);
        static Player* getInstance(int xPos, int yPos, int width, int height);
        void handleEvent(const SDL_Event &eve);
        double getGravity();
        int getRunningSpeed();
        double& getYVelocity();
        double& getJumpingPower();
        void tick();
        void enterNewState(class PlayerState* newState);
        ~Player();
    protected:
        Player(int xPos, int yPos, int width, int height, std::map<std::string, std::string> strings);
        Player(int xPos, int yPos, int width, int height);
    private:
        class PlayerState* playerState;
        void handleInput(SDL_KeyboardEvent& keyEvent);
        double gravity = 0.2;
        double jumpingPower = 7;
        double currentYVelocity = 0;
        double runningSpeed = 5;



    };
}


#endif //PROG3_PLAYER_H
