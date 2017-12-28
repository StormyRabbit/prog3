//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PHYSICSSPRITE_H
#define PROG3_PHYSICSSPRITE_H

#include "Sprite.h"
#include <SDL_image.h>
#include <vector>
#include <string>
#include <map>

namespace rootengine{
    class PhysicsSprite : public Sprite {
    public:
        void draw() const;
        void animatedTextureChange(std::string keyToMap);
        void setIsDraweble(bool draw);
        bool checkIfOnGround(PhysicsSprite* sprite, std::vector<SDL_Rect> ground);
    protected:
        PhysicsSprite(int xPos,int yPos,int width,int height, std::map<std::string, std::string> sprites, std::map<std::string, std::vector<SDL_Rect>> frames);
        ~PhysicsSprite(); //Osäker på om det ska vara protected???
        int frame = 0;
        void animatedTick();
    private:
        bool isDrawable = true;
        SDL_Texture* texture;
        std::vector<SDL_Rect> framePositions;
        std::map<std::string, std::string> spriteMap;
        std::map<std::string, std::vector<SDL_Rect>> framesMap;
        int originalH;
        int originalW;
        void updateSize();
    };
}


#endif //PROG3_PHYSICSSPRITE_H
