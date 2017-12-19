//
// Created by Oskar on 2017-12-04.
//

#include <vector>
#include "PhysicsSprite.h"
#include "System.h"

namespace rootengine{
    PhysicsSprite::PhysicsSprite(int xPos, int yPos, int width, int height, std::string pathToDraw) : Sprite(xPos, yPos, width, height) {
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());
    }
    PhysicsSprite::~PhysicsSprite() {
        SDL_DestroyTexture(texture);
    }

    void PhysicsSprite::changeTexture(std::string pathToNewTexture) {
        animatedTexture = false;
        SDL_DestroyTexture(texture);
        texture = IMG_LoadTexture(sys.getRenderer(), pathToNewTexture.c_str());
    }

    void PhysicsSprite::animatedTextureChange(std::string pathToNewTexture, SDL_Rect framesPos[]) {
        animatedTexture = true;
        SDL_DestroyTexture(texture);
        texture = IMG_LoadTexture(sys.getRenderer(), pathToNewTexture.c_str());
        framePositions;
        //TODO MAKE RESPONSIVE TO DIFFERENT SIZES
        for (int i = 0; i <= 10; i++){
            framePositions[i].x = framesPos[i].x;
            framePositions[i].y = framesPos[i].y;
            framePositions[i].w = framesPos[i].w;
            framePositions[i].h = framesPos[i].h;
        }
    }

    void PhysicsSprite::animatedTick() {
        if (animatedTexture)
        {
            frame++;
            //TODO MAKE RESPONSIVE TO DIFFERENT SIZES
            if (frame > 10) {
                frame = 0;
            }
        }
    }

    void PhysicsSprite::draw() const {
        if (!animatedTexture){
            SDL_RenderCopy(sys.getRenderer(), texture, NULL, &getRect());
        } else {
            SDL_Rect tempClip = framePositions[frame]; //Change to frame/2 too make slower.
            SDL_RenderCopy(sys.getRenderer(), texture, &tempClip, &getRect());
        }
    }
}
