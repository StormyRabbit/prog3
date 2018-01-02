//
// Created by Oskar on 2017-12-04.
//

#include "Player.h"
#include "StandingState.h"
#include "FallingState.h"
#include "../../rootEngine/System/GameEngine.h"
namespace jumpyboy {

 Player::Player(int xPos, int yPos, int width, int height, stringsMap strings, fMapType frames, mvMap movingVariables)
            : PhysicsSprite(xPos,yPos, width, height, strings, frames){

        gravity = movingVariables.find("gravity")->second;
        runningSpeed = movingVariables.find("runningSpeed")->second;
        jumpingPower = movingVariables.find("jumpPower")->second;
        playerState = new StandingState();
        playerState->enterState(*this);
    }

    Player* Player::getInstance(int xPos, int yPos, int width, int height, stringsMap strings,
                                fMapType frames, mvMap movingVariables) {
        return new Player(xPos, yPos, width, height, strings, frames, movingVariables);
    }

    double Player::getGravity() {
        return gravity;
    }

    int Player::getRunningSpeed() {
        return (int)runningSpeed;
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

    void Player::handleInput(std::string action, bool isDown) {
        PlayerState* tempState = playerState->handleInput(*this, action, isDown);
        //Returns NULL if PlayerState is not changed.
        if (tempState != nullptr){
            delete playerState;
            playerState = tempState;
            //Enter new state.
            playerState->enterState(*this);
        }
    }

    Player::~Player() {}

    void Player::respawn() {

    }

    void Player::kill() {

    }

    void Player::setController(Controller *controll) {
        controller = controll;
    }
}
