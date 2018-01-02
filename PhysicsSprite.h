//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PHYSICSSPRITE_H
#define PROG3_PHYSICSSPRITE_H

#include "Sprite.h"
#include "collision/CollisionStrategy.h"
#include <SDL_image.h>
#include <vector>
#include <string>
#include <map>

namespace rootengine{
    typedef std::map<std::string, std::string> spritesMap;
    typedef std::map<std::string, std::vector<SDL_Rect>> fMapType;
    class PhysicsSprite : public Sprite {
    public:
        void draw() const;
        void animatedTextureChange(std::string keyToMap);
        void setIsDrawable(bool draw);
        bool checkIfOnGround();
        void setResetHeight(int height);
        void setResetWidth(int width);
        void setCollisionStrategy(class CollisionStrategy* collStrategy);
        CollisionStrategy* getCollisionStrategy();
        virtual void tick();
        int getResetHeight();
        virtual void collBehavior();
        SDL_Surface *getSurface();
        int getResetWidth();
        void setOnGround(bool isOnGround);
        void setOnGroundBorder(bool isBorder);
        bool checkIfOnGroundBorder();
    protected:

        PhysicsSprite(int xPos,int yPos,int width,int height, spritesMap sprites, fMapType frames);
        ~PhysicsSprite();
        int frame = 0;
    private:
        bool isDrawable = true;
        SDL_Surface *surf; // behövs för pixel detection ?
        SDL_Texture* texture;
        std::vector<SDL_Rect> framePositions;
        std::map<std::string, std::string> spriteMap;
        std::map<std::string, std::vector<SDL_Rect>> framesMap;
        CollisionStrategy* collStrategy = nullptr;
        int resetHeight;
        int resetWidth;
        bool onGround = false;
        bool onGrundBorder = true;
        void updateSize();
    };
}


#endif //PROG3_PHYSICSSPRITE_H
