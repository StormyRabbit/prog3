//
// Created by Oskar on 2017-12-10.
//

#include "RunningState.h"
#include "StandingState.h"
#include "JumpingState.h"
#include "RunningJumpState.h"
#include "DodgingState.h"
#include "FallingState.h"
#include "RunningFallState.h"

namespace rootengine{
    RunningState::RunningState(bool isLeftBool) {
        isLeft = isLeftBool;
    }
    RunningState::~RunningState() {}
    void RunningState::enterState(Player &player) {
        std::vector<SDL_Rect> tempFrameRect;

        SDL_Rect rect1{0,0,67,92};
        SDL_Rect rect2{67,0,66,93};
        SDL_Rect rect3{133,0,67,92};
        SDL_Rect rect4{0,93,67,93};
        SDL_Rect rect5{67,93,66,93};
        SDL_Rect rect6{133,93,71,92};
        SDL_Rect rect7{0,186,71,93};
        SDL_Rect rect8{71,186,71,93};
        SDL_Rect rect9{142,186,70,93};
        SDL_Rect rect10{0,279,71,93};
        SDL_Rect rect11{71,279,67,92};

        tempFrameRect.push_back(rect1);
        tempFrameRect.push_back(rect2);
        tempFrameRect.push_back(rect3);
        tempFrameRect.push_back(rect4);
        tempFrameRect.push_back(rect5);
        tempFrameRect.push_back(rect6);
        tempFrameRect.push_back(rect7);
        tempFrameRect.push_back(rect8);
        tempFrameRect.push_back(rect9);
        tempFrameRect.push_back(rect10);
        tempFrameRect.push_back(rect11);

        //TODO FLIP TEXTURES
        if (isLeft) {
            player.animatedTextureChange("running");
        } else {
            player.animatedTextureChange("running");
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

        return nullptr;
    }

    void RunningState::updateState(Player& player){
        if (isLeft){
            player.changeRect().x = player.getRect().x - player.getRunningSpeed();
        } else {
            player.changeRect().x = player.getRect().x + player.getRunningSpeed();
        }

        if (!player.checkIfOnGround()){
            player.enterNewState(new RunningFallState(isLeft));
        }
    }

}
