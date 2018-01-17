//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PLAYER_H
#define PROG3_PLAYER_H

#include <map>
#include "../../rootEngine/sprite/PhysicsSprite.h"
#include "PlayerState.h"
#include "../../rootEngine/collision/CollEngine.h"
#include "../../rootEngine/interfaces/PlayerInterface.h"
#include "Controller.h"
namespace jumpyboy {
    typedef std::map<std::string, std::string> stringsMap;
    typedef std::map<std::string, std::vector<SDL_Rect>> fMapType;
    typedef std::map<std::string, double> mvMap;
    class Player : public rootengine::PhysicsSprite, rootengine::PlayerInterface {
    public:
        static Player *getInstance(int xPos, int yPos, int width, int height, stringsMap strings, fMapType frames, mvMap movingVariables);
        double getGravity();
        void kill();
        void respawn();
        int getRunningSpeed();
        double& getYVelocity();
        double& getJumpingPower();
        void tick() override;
        void enterNewState(class PlayerState* newState);
        void setController(class Controller* controller);
        ~Player() override;
        void handleInput(std::string action, bool isDown);
        int getLifesLeft();
        void setCanTakeDamage(bool value);
    protected:
        Player(int xPos, int yPos, int width, int height, stringsMap strings, fMapType frames, mvMap movingVariables);
    private:
        class PlayerState* playerState;
        Controller* controller;
        double gravity;
        double jumpingPower;
        double currentYVelocity = 0;
        double runningSpeed;
        int lifes;
    };
}
#endif //PROG3_PLAYER_H
