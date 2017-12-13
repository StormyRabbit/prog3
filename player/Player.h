//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PLAYER_H
#define PROG3_PLAYER_H

#include "../PhysicsSprite.h"
#include "PlayerState.h"
#include "StandingState.h"
#include "RunningState.h"
#include "JumpingState.h"
#include "FallingState.h"
#include "DodgingState.h"
#include "DeadState.h"

namespace rootengine {
    class Player : public PhysicsSprite {
    public:
        static Player *getInstance(int xPos, int yPos, int width, int height, std::string spritePath);
        static Player* getInstance(int xPos, int yPos, int width, int height);
        void handleEvent(const SDL_Event &eve);
        void checkState();
        void updatePlayer();
    protected:
        Player(int xPos, int yPos, int width, int height, std::string spritePath);
        Player(int xPos, int yPos, int width, int height);
    private:
        //PlayerState currentState = PlayerState::standing;
        std::string frontTexture = "assets/sprites/Player/p1_front.png";
        void keyDown(const SDL_Event& eve) override;
        void keyUp(const SDL_Event& eve) override;
        void handleInput(SDL_KeyboardEvent& keyEvent);
        PlayerState* playerState;

    };
}


#endif //PROG3_PLAYER_H
