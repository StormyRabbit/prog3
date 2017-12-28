//
// Created by Oskar on 2017-12-04.
//

#include <vector>
#include <cmath>
#include "PhysicsSprite.h"
#include "System.h"

namespace rootengine{
    PhysicsSprite::PhysicsSprite(int xPos, int yPos, int width, int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames) : originalW(width), originalH(height), framesMap(frames), spriteMap(sprites), Sprite(xPos, yPos, width, height) {
        std::string pathToDraw = sprites.find(sprites.begin()->first)->second;
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
        updateSize();
        frame++;
        if (frame >= framePositions.size()) {
            frame = 0;
            changeRect().h = originalH;
            changeRect().w = originalW;
        }
    }

    bool PhysicsSprite::checkIfOnGround(PhysicsSprite* sprite, std::vector<SDL_Rect> collEnvironmentRect) {
        int leftObject = sprite->getRect().x;
        int rightObject = sprite->getRect().x + sprite->getRect().w;
        int topObject = sprite->getRect().y;
        int bottomObject = sprite->getRect().y + sprite->getRect().h;

        for (SDL_Rect ground : collEnvironmentRect) {
            int leftGround = ground.x;
            int rightGround = ground.x + ground.w;
            int topGround = ground.y;
            int bottomGround = ground.y + ground.h;

            if (bottomObject >= topGround && leftObject >= leftGround && rightObject <= rightGround && bottomGround >= bottomObject){
                sprite->changeRect().y = sprite->getRect().y;
                return true;
            }
        }

        return false;
    }

    void PhysicsSprite::updateSize(){
        int tempFrame = frame;
        if (tempFrame != 0){
            double diffrenceInHeight = (double)framePositions[frame].h / (double)framePositions[frame - 1].h;
            double diffrenceInWitdh = (double)framePositions[frame].w / (double)framePositions[frame - 1].w;

            changeRect().h = round(getRect().h * diffrenceInHeight);
            changeRect().w = round(getRect().w * diffrenceInWitdh);
        }
    }

    void PhysicsSprite::draw() const {
        if (isDrawable) {
            SDL_Rect tempClip = framePositions[frame];
            SDL_RenderCopy(sys.getRenderer(), texture, &tempClip, &getRect());
        }

    }

    void PhysicsSprite::setIsDraweble(bool draw) {
        isDrawable = draw;
    }
}
