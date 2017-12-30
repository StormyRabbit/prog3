//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PLAYER_H
#define PROG3_PLAYER_H

#include <map>
#include "../PhysicsSprite.h"
#include "PlayerState.h"
#include "../util/CollEngine.h"


namespace rootengine {
    typedef std::map<std::string, std::string> stringsMap;
    typedef std::map<std::string, std::vector<SDL_Rect>> fMapType;
    typedef std::map<std::string, double> mvMap;
    class Player : public PhysicsSprite {
    public:
        static Player *getInstance(int xPos, int yPos, int width, int height, stringsMap strings, fMapType frames, mvMap movingVariables);
        void handleEvent(const SDL_Event &eve);
        double getGravity();
        int getRunningSpeed();
        double& getYVelocity();
        double& getJumpingPower();
        void tick() override;
        void enterNewState(class PlayerState* newState);
        ~Player() override;
    protected:
        Player(int xPos, int yPos, int width, int height, stringsMap strings, fMapType frames, mvMap movingVariables);
    private:
        class PlayerState* playerState;
        void handleInput(SDL_KeyboardEvent& keyEvent);
        double gravity;
        double jumpingPower;
        double currentYVelocity = 0;
        double runningSpeed;
    };
}
#endif //PROG3_PLAYER_H
