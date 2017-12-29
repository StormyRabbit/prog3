//
// Created by Oskar on 2017-12-04.
//

#include <vector>
#include <cmath>
#include "PhysicsSprite.h"
#include "System.h"

namespace rootengine {
    typedef std::map<std::string, std::string> spritesMap;
    typedef std::map<std::string, std::vector<SDL_Rect>> framesMap;
    PhysicsSprite::PhysicsSprite(int xPos, int yPos, int width, int height, spritesMap sprites, framesMap frames)
            : resetWidth(width), resetHeight(height), framesMap(frames), spriteMap(sprites),
              Sprite(xPos, yPos, width, height) {
        std::string pathToDraw = sprites.find(sprites.begin()->first)->second;
        surf = IMG_Load(pathToDraw.c_str());
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());

    }
    PhysicsSprite::~PhysicsSprite() {
        SDL_DestroyTexture(texture);
    }

    void PhysicsSprite::animatedTextureChange(std::string keyToMap) {
        frame = 0;
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
            changeRect().h = resetHeight;
            changeRect().w = resetWidth;
        }
    }

    bool PhysicsSprite::checkIfOnGround() {
        return onGround;
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

    void PhysicsSprite::setIsDrawable(bool draw) {
        isDrawable = draw;
    }

    void PhysicsSprite::setOnGround(bool isOnGround) {
        onGround = isOnGround;
    }

    int PhysicsSprite::getResetWidth() {
        return resetWidth;
    }

    int PhysicsSprite::getResetHeight() {
        return resetWidth;
    }

    void PhysicsSprite::setResetWidth(int width) {
        resetWidth = width;
    }

    void PhysicsSprite::setResetHeight(int height) {
        resetHeight = height;
    }

    SDL_Surface *PhysicsSprite::getSurface() {
        return surf;
    }
}
