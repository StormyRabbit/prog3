//
// Created by Oskar on 2017-12-04.
//

#include "Player.h"

namespace rootengine{
    Player::Player(int xPos, int yPos, int width, int height, std::string spritePath) : PhysicsSprite(xPos,yPos, width, height, spritePath){}

    Player* Player::getInstance(int xPos, int yPos, int width, int height, std::string spritePath) {
        return new Player(xPos, yPos, width, height, spritePath);
    }

    void Player::checkState(){
        switch(Player::currentState) {
            case(PlayerState::jumping):
                jumping();
                break;
            case (PlayerState ::falling):
                falling();
        }
    }

    void Player::jumping(){
        if (getRect().y > 350)
            changeRect().y = changeRect().y - 3;
        else
            Player::currentState = PlayerState ::falling;
    }

    void Player::falling() {
        if (getRect().y < 450)
            changeRect().y = changeRect().y + 3;
        else
            Player::currentState = PlayerState ::standing;
    }

    void Player::keyDown(const SDL_Event &eve) {
        SDL_KeyboardEvent key = eve.key;
        SDL_Keysym keysym = key.keysym;

        switch (keysym.sym) {
            case SDLK_RIGHT :
                rightButton();
                break;
            case SDLK_LEFT :
                leftButton();
                break;
            case SDLK_UP :
                upButton();
                break;
            case SDLK_DOWN :
                downButton();
                break;
        }
    }

    void Player::keyUp(const SDL_Event &eve) {
        SDL_KeyboardEvent key = eve.key;
        SDL_Keysym keysym = key.keysym;

        switch (keysym.sym) {
            case SDLK_RIGHT :
                changeRect().x = changeRect().x + 10;
                break;
            case SDLK_LEFT :
                leftButton();
                changeRect().x = changeRect().x - 10;
                break;
            case SDLK_UP :
                upButton();
                break;
            case SDLK_DOWN :
                if (getRect().y < 450)
                    changeRect().y = changeRect().y + 10;
                break;
        }
    }

    void Player::runningJump() {

    }

    void Player::standingJump() {

    }

    void Player::leftButton() {
        switch(Player::currentState) {
            case(PlayerState::jumping):
                jumpMove("LEFT");
                break;
            case(PlayerState::running):
                running("LEFT");
                break;
            case(PlayerState::standing):
                running("LEFT");
                break;
            default:
                break;
        }
    }
    void Player::rightButton() {
        switch(Player::currentState) {
            case(PlayerState::jumping):
                jumpMove("RIGHT");
                break;
            case(PlayerState::running):
                running("RIGHT");
                break;
            case(PlayerState::standing):
                running("RIGHT");
                break;
            default:
                break;
        }
    }

    void Player::running(std::string direction) {
        Player::currentState = PlayerState::running;
        if(direction == "LEFT")
            Player::changeRect().x = Player::changeRect().x - 10;

        if(direction == "RIGHT")
            Player::changeRect().x = Player::changeRect().x + 10;

    }

    void Player::jumpMove(std::string direction) {
        Player::currentState = PlayerState::jumping;
        if(direction == "LEFT")
            Player::changeRect().x = Player::changeRect().x - 10;
        if(direction == "RIGHT")
            Player::changeRect().x = Player::changeRect().x + 10;
    }
    void Player::upButton() {
        if (!(Player::currentState == PlayerState::jumping) || !(Player::currentState == PlayerState::falling) || !(Player::currentState == PlayerState::runningJump)){
            if (Player::currentState == PlayerState::running)
                Player::currentState = PlayerState::runningJump;
            else
                Player::currentState = PlayerState::jumping;

        }
    }

    void Player::downButton() {

    }

    void Player::updatePlayer() {

    }

    void Player::handleEvent(const SDL_Event &eve) {
        switch (eve.type){
            case SDL_KEYUP :
                keyUp(eve);
                break;
            case SDL_KEYDOWN:
                keyDown(eve);
                break;
        }

    }
}

