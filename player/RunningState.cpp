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
        SDL_Rect tempFrameRect[10];

        //TODO GÖR SNYGGARE???
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


        //TODO FLIP TEXTURES
        if (isLeft) {
            player.animatedTextureChange("running", tempFrameRect);
        } else {
            player.animatedTextureChange("running", tempFrameRect);
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

        //TODO ADD GET FUNCTION FOR ENVI OBJECTS
        //JUST TRY CODE
        SDL_Rect ground1;
        ground1.x = 0;
        ground1.y = 500;
        ground1.h = 100;
        ground1.w = 1200;
        SDL_Rect ground2;
        ground2.x = 500;
        ground2.y = 420;
        ground2.h = 20;
        ground2.w = 200;
        std::vector<SDL_Rect> grounds;
        grounds.push_back(ground1);
        grounds.push_back(ground2);
        if (!player.checkIfOnGround(player.changeRect(), grounds)){
            player.enterNewState(new RunningFallState(isLeft));
        }


        if (isLeft){
            player.changeRect().x = player.getRect().x - player.getRunningSpeed();
        } else {
            player.changeRect().x = player.getRect().x + player.getRunningSpeed();
        }
    }

}
