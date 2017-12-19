//
// Created by Oskar on 2017-12-10.
//

#include "RunningState.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "RunningJumpState.h"
#include "DodgingState.h"

namespace rootengine{
    RunningState::RunningState(bool isLeftBool) {
        isLeft = isLeftBool;
    }
    RunningState::~RunningState() {}
    void RunningState::enterState(Player &player) {
        SDL_Rect tempFrameRect[10];

        tempFrameRect[0].x = 0;
        tempFrameRect[0].y = 0;
        tempFrameRect[0].w = 67;
        tempFrameRect[0].h = 92;

        tempFrameRect[1].x = 67;
        tempFrameRect[1].y = 0;
        tempFrameRect[1].w = 66;
        tempFrameRect[1].h = 93;

        tempFrameRect[2].x = 133;
        tempFrameRect[2].y = 0;
        tempFrameRect[2].w = 67;
        tempFrameRect[2].h = 92;

        tempFrameRect[3].x = 0;
        tempFrameRect[3].y = 93;
        tempFrameRect[3].w = 67;
        tempFrameRect[3].h = 93;

        tempFrameRect[4].x = 67;
        tempFrameRect[4].y = 93;
        tempFrameRect[4].w = 66;
        tempFrameRect[4].h = 93;

        tempFrameRect[5].x = 133;
        tempFrameRect[5].y = 93;
        tempFrameRect[5].w = 71;
        tempFrameRect[5].h = 92;

        tempFrameRect[6].x = 0;
        tempFrameRect[6].y = 186;
        tempFrameRect[6].w = 71;
        tempFrameRect[6].h = 93;

        tempFrameRect[7].x = 71;
        tempFrameRect[7].y = 186;
        tempFrameRect[7].w = 71;
        tempFrameRect[7].h = 93;

        tempFrameRect[8].x = 142;
        tempFrameRect[8].y = 186;
        tempFrameRect[8].w = 70;
        tempFrameRect[8].h = 93;

        tempFrameRect[9].x = 0;
        tempFrameRect[9].y = 279;
        tempFrameRect[9].w = 71;
        tempFrameRect[9].h = 93;

        tempFrameRect[10].x = 71;
        tempFrameRect[10].y = 279;
        tempFrameRect[10].w = 67;
        tempFrameRect[10].h = 92;

        if (isLeft) {
            player.animatedTextureChange("assets/sprites/Player/p1_walk/p1_walk.png", tempFrameRect);
        } else {
            player.animatedTextureChange("assets/sprites/Player/p1_walk/p1_walk.png", tempFrameRect);
        }

        //delete(tempFrameRect);
    }

    PlayerState* RunningState::handleInput(Player& player, SDL_KeyboardEvent& keyEvent) {
        SDL_Keysym keysym = keyEvent.keysym;


        if (keyEvent.type == SDL_KEYDOWN){
            switch (keysym.sym) {
                case SDLK_UP :
                    return new RunningJumpState(isLeft);
                case SDLK_DOWN :
                    return new DodgingState();
            }
        }



        if (keyEvent.type == SDL_KEYUP){
            switch (keysym.sym) {
                case SDLK_LEFT :
                    return new StandingState();
                case SDLK_RIGHT :
                    return new StandingState();
            }
        }

        return NULL;
    }

    void RunningState::updateState(Player& player){
        if (isLeft){
            player.changeRect().x = player.getRect().x - 5;
        } else {
            player.changeRect().x = player.getRect().x + 5;
        }
    }

}
