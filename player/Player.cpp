//
// Created by Oskar on 2017-12-04.
//

#include "Player.h"
#include "StandingState.h"
#include "FallingState.h"
#include "../GameEngine.h"

namespace rootengine{
    Player::Player(int xPos, int yPos, int width, int height, std::map<std::string, std::string> strings, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> movingVariables) : PhysicsSprite(xPos,yPos, width, height, strings, frames){

        gravity = movingVariables.find("gravity")->second;

        runningSpeed = movingVariables.find("runningSpeed")->second;

        jumpingPower = movingVariables.find("jumpPower")->second;

        playerState = new StandingState();
        playerState->enterState(*this);
    }

    Player* Player::getInstance(int xPos, int yPos, int width, int height, std::map<std::string, std::string> strings, std::map<std::string, std::vector<SDL_Rect>> frames, std::map<std::string, double> movingVariables) {
        return new Player(xPos, yPos, width, height, strings, frames, movingVariables);
    }

    double Player::getGravity() {
        return gravity;
    }

    int Player::getRunningSpeed() {
        return runningSpeed;
    }

    double& Player::getYVelocity(){
        return currentYVelocity;
    }

    double& Player::getJumpingPower(){
        return jumpingPower;
    }

    void Player::enterNewState(PlayerState* newState) {
        if (newState != nullptr) {
            delete playerState;
            playerState = newState;
            playerState->enterState(*this);
        }
    }

    void Player::tick() {
        PhysicsSprite::tick();
        playerState->updateState(*this);
    }

    void Player::handleInput(SDL_KeyboardEvent &keyEvent) {
        PlayerState* tempState = playerState->handleInput(*this, keyEvent);
        //Returns NULL if PlayerState is not changed.
        if (tempState != nullptr){
            delete playerState;
            playerState = tempState;

            //Enter new state.
            playerState->enterState(*this);
        }
    }

    void Player::handleEvent(const SDL_Event &eve) {
        if (eve.type == SDL_KEYUP || eve.type == SDL_KEYDOWN){
            SDL_KeyboardEvent keyEvent = eve.key;
            handleInput(keyEvent);
        }
    }

    Player::~Player() {}
}

