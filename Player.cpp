//
// Created by Oskar on 2017-12-04.
//

#include "Player.h"

namespace rootengine{
    Player::Player(int xPos, int yPos, int width, int height) : PhysicsSprite(xPos,yPos, width, height, "assets/sprites/Player/p1_front.png"){}
    Player::~Player() {}

    Player* Player::getInstance(int xPos, int yPos, int width, int height) {
        return new Player(xPos, yPos, width, height);
    }

    void Player::checkState(){
        if (isJumping == true)
            if (getRect().y > 400)
                changeRect().y--;
            else
                isJumping = false;
                isFalling = true;
        if (isFalling == true)
            if (getRect().y < 450)
                changeRect().y++;
            else
                isFalling = false;

    }

    void Player::keyDown(const SDL_Event &eve) {
        SDL_KeyboardEvent key = eve.key;
        SDL_Keysym keysym = key.keysym;

        switch (keysym.sym) {
            case SDLK_RIGHT : changeRect().x = changeRect().x + 10;
                break;
            case SDLK_LEFT : changeRect().x = changeRect().x - 10;
                break;
            case SDLK_UP : isJumping = true; //changeRect().y = changeRect().y - 10;
                break;
            case SDLK_DOWN :
                    if(getRect().y < 450)
                        changeRect().y = changeRect().y + 10;

                break;
        }

    }

    void Player::keyUp(const SDL_Event &eve) {

    }
}
