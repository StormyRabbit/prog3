//
// Created by Oskar on 2017-12-04.
//

#include <vector>
#include "PhysicsSprite.h"
#include "System.h"

namespace rootengine{
    PhysicsSprite::PhysicsSprite(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites) : spriteMap(sprites), Sprite(xPos, yPos, width, height) {
        std::string pathToDraw = sprites.find("standing")->second;
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());
    }
    PhysicsSprite::~PhysicsSprite() {
        SDL_DestroyTexture(texture);
    }

    void PhysicsSprite::changeTexture(std::string keyToMap) {
        std::string pathToDraw = spriteMap.find(keyToMap)->second;
        animatedTexture = false;
        SDL_DestroyTexture(texture);
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());
    }

    void PhysicsSprite::animatedTextureChange(std::string keyToMap, SDL_Rect framesPos[]) {
        std::string pathToDraw = spriteMap.find(keyToMap)->second;
        animatedTexture = true;
        SDL_DestroyTexture(texture);
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());
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

    bool PhysicsSprite::checkIfOnGround(SDL_Rect object, std::vector<SDL_Rect> collEnvironmentRect) {
        int leftObject = object.x;
        int rightObject = object.x + object.w;
        int topObject = object.y;
        int bottomObject = object.y + object.h;

        for (SDL_Rect ground : collEnvironmentRect) {
            int leftGround = ground.x;
            int rightGround = ground.x + ground.w;
            int topGround = ground.y;
            int bottomGround = ground.y + ground.h;

            if (bottomObject >= topGround && leftObject >= leftGround && rightObject <= rightGround && bottomObject <= bottomGround){
                return true;
            }
        }

        return false ;
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
