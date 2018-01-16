 //
// Created by Oskar on 2017-12-04.
//

#include <vector>
#include <cmath>
#include "PhysicsSprite.h"
#include "../System/System.h"

namespace rootengine {
    PhysicsSprite::PhysicsSprite(int xPos, int yPos, int width, int height, sMapType sprites, fMapType frames)
            : resetWidth(width), resetHeight(height), framesMap(frames), spriteMap(sprites),
              Sprite(xPos, yPos, width, height) {
    }
    PhysicsSprite::~PhysicsSprite() {
        SDL_DestroyTexture(texture);
    }

    void PhysicsSprite::animatedTextureChange(std::string keyToMap) {
        frame = 0;
        currentStateKey = keyToMap;

        framePositions = framesMap.find(currentStateKey)->second;
        std::string pathToDraw = spriteMap.find(currentStateKey)->second;

        if (surface != nullptr){
            SDL_FreeSurface(surface);
        }
        if (texture != nullptr){
            SDL_DestroyTexture(texture);
        }
        surface = IMG_Load(pathToDraw.c_str());
        texture = IMG_LoadTexture(sys.getRenderer(), pathToDraw.c_str());
    }

    void PhysicsSprite::tick(){
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
        if (tempFrame > 0){
            double differenceInHeight = (double)framePositions[frame].h / (double)framePositions[frame - 1].h;
            double differenceInWidth = (double)framePositions[frame].w / (double)framePositions[frame - 1].w;

            changeRect().h = (int)round(getRect().h * differenceInHeight);
            changeRect().w = (int)round(getRect().w * differenceInWidth);
        }
    }

    void PhysicsSprite::draw() const {
        if (isDrawable && texture != nullptr) {
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

    void PhysicsSprite::collBehavior() {

    }

    void PhysicsSprite::setCollisionStrategy(CollisionStrategy *collStrategy) {
        PhysicsSprite::collStrategy = collStrategy;
    }

    CollisionStrategy *PhysicsSprite::getCollisionStrategy() {
        return collStrategy;
    }

    SDL_Rect PhysicsSprite::getCurrentFrame() {
        return framesMap.find(currentStateKey)->second[frame];
    }


    std::string PhysicsSprite::getCurrentSprite() {
        return spriteMap.find(currentStateKey)->second;
    }

    bool PhysicsSprite::getAlphaValue(int x, int y) {

        SDL_Point delta = getNormalizedValue(x,y);

        //Hämtat från http://www.sdltutorials.com/sdl-per-pixel-collision
        SDL_Rect currentFrame = getCurrentFrame();
        SDL_SetClipRect(surface, &currentFrame);

        int bpp = surface->format->BytesPerPixel;
        Uint8* p = (Uint8*)surface->pixels + delta.y * surface->pitch + delta.x * bpp;
        Uint32  pixelColor;

        switch (bpp){
            case (1):
                pixelColor = *p;
                break;
            case (2):
                pixelColor = *(Uint16 *)p;
                break;
            case (3):
                pixelColor = p[0] | p[1] << 8 | p[2] << 16;
                break;
            case (4):
                pixelColor = *(Uint32*)p;
                break;
        }

        Uint8 red, green, blue, alpha;
        SDL_GetRGBA(pixelColor, surface->format, &red, &green, &blue, &alpha);
        return alpha > 200;
    }

    double PhysicsSprite::getHitAngle(int x, int y) {
        SDL_Point delta = getNormalizedValue(x,y);

        double circleWZero = getRect().w / 2;
        double circleHZero = getRect().h / 2;

        return atan2(delta.x - circleWZero, delta.y - circleHZero) * 180 / 3.1415926535897;
        ;
    }

    SDL_Point PhysicsSprite::getNormalizedValue(int x, int y) {
        SDL_Point delta;
        delta.x = x - getRect().x;
        delta.y = y - getRect().y;
        double yDiff = static_cast<double>(getCurrentFrame().w) / getRect().w;
        double xDiff = static_cast<double>(getCurrentFrame().w) / getRect().w;

        delta.x = floor(delta.x * xDiff);
        delta.y = floor(delta.y * yDiff);

        return delta;
    }
}
