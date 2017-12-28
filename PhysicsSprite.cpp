//
// Created by Oskar on 2017-12-04.
//

#include <vector>
#include "PhysicsSprite.h"
#include "System.h"

namespace rootengine{
    PhysicsSprite::PhysicsSprite(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames) : framesMap(frames), spriteMap(sprites), Sprite(xPos, yPos, width, height) {
        std::string pathToDraw = sprites.find("standing")->second;
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());
    }
    PhysicsSprite::~PhysicsSprite() {
        SDL_DestroyTexture(texture);
    }

    void PhysicsSprite::animatedTextureChange(std::string keyToMap) {
        framePositions = framesMap.find(keyToMap)->second;
        std::string pathToDraw = spriteMap.find(keyToMap)->second;
        SDL_DestroyTexture(texture);
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());
    }

    void PhysicsSprite::animatedTick() {
        frame++;
        if (frame >= framePositions.size()) {
            frame = 0;
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
        SDL_Rect tempClip = framePositions[frame]; //Change to frame/2 too make slower.
        SDL_Rect playerSize = getRect();

        //playerSize.h = tempClip.h * 1;
        //playerSize.w = tempClip.w * 1;

        /*if (framePositions.size() > 1 && frame != 0){
            SDL_Rect previousRect = framePositions[frame - 1];

            playerSize.h = tempClip.h - (tempClip.h - previousRect.h);
            playerSize.w = tempClip.w - (tempClip.w - previousRect.w);
        }*/

        SDL_RenderCopy(sys.getRenderer(), texture, &tempClip, &playerSize);
    }
}
