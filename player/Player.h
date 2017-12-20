//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PLAYER_H
#define PROG3_PLAYER_H

#include "../PhysicsSprite.h"
#include "PlayerState.h"


namespace rootengine {
    class Player : public PhysicsSprite {
    public:
        static Player *getInstance(int xPos, int yPos, int width, int height, std::string spritePath);
        static Player* getInstance(int xPos, int yPos, int width, int height);
        void handleEvent(const SDL_Event &eve);
        void tick();
        void enterNewState(class PlayerState* newState);
        ~Player();
    protected:
        Player(int xPos, int yPos, int width, int height, std::string spritePath);
        Player(int xPos, int yPos, int width, int height);
    private:
        class PlayerState* playerState;
        void handleInput(SDL_KeyboardEvent& keyEvent);


    };
}


#endif //PROG3_PLAYER_H
