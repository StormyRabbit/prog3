//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PLAYER_H
#define PROG3_PLAYER_H

#include "PhysicsSprite.h"
#include "PlayerState.h"

namespace rootengine {
    class Player : public PhysicsSprite {
    public:
        static Player* getInstance(int xPos, int yPos,int width,int height);
        void keyDown(const SDL_Event& eve) override;
        void keyUp(const SDL_Event& eve) override;
        void checkState();
        void updatePlayer();
    protected:
        Player(int xPos, int yPos, int width, int height);
    private:
        PlayerState currentState = PlayerState::standing;
        std::string frontTexture = "assets/sprites/Player/p1_front.png";
        void running(std::string direction);
        void jumpMove(std::string direction);

        void upButton();
        void runningJump();
        void standingJump();
        void leftButton();

        void downButton();

        void rightButton();
    };
}


#endif //PROG3_PLAYER_H
