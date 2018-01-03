//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PHYSICSSPRITE_H
#define PROG3_PHYSICSSPRITE_H

#include <SDL_image.h>
#include <vector>
#include <string>
#include <map>
#include "../collision/CollisionStrategy.h"
#include "Sprite.h"

namespace rootengine{
    typedef std::map<std::string, std::string> sMapType;
    typedef std::map<std::string, std::vector<SDL_Rect>> fMapType;
    class PhysicsSprite : public Sprite {
    public:
        void draw() const override;
        void animatedTextureChange(std::string keyToMap);
        virtual void tick();
        virtual void collBehavior();
        //SET FUNCTIONS
        void setResetHeight(int height);
        void setResetWidth(int width);
        void setIsDrawable(bool draw);
        void setCollisionStrategy(class CollisionStrategy* collStrategy);
        void setOnGround(bool isOnGround);
        //GET FUNCTIONS
        CollisionStrategy* getCollisionStrategy();
        std::string getCurrentSprite();
        SDL_Rect getCurrentFrame();
        int getResetHeight();
        int getResetWidth();
        bool checkIfOnGround();
    protected:
        PhysicsSprite(int xPos,int yPos,int width,int height, sMapType sprites, fMapType frames);
        ~PhysicsSprite();
    private:
        int frame = 0;
        bool isDrawable = true;
        SDL_Surface *surf; // behövs för pixel detection ?
        SDL_Texture* texture = nullptr;
        std::vector<SDL_Rect> framePositions;
        std::map<std::string, std::string> spriteMap;
        std::map<std::string, std::vector<SDL_Rect>> framesMap;
        CollisionStrategy* collStrategy = nullptr;
        std::string currentStateKey;
        int resetHeight;
        int resetWidth;
        bool onGround = false;
        bool onGrundBorder = true;
        void updateSize();
    };
}


#endif //PROG3_PHYSICSSPRITE_H
