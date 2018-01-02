//
// Created by oskar on 12-Dec-17.
//
#include "PlayerState.h"

namespace jumpyboy{
    PlayerState::PlayerState() {}
    PlayerState::~PlayerState() {}

    void PlayerState::enterState(class Player &player) {}
    void PlayerState::updateState(class Player &player) {}
    PlayerState* PlayerState::handleInput(class Player &player, SDL_KeyboardEvent &keyEvent) {}
}
