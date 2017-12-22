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
        void changeTexture(std::string pathToNewTexture);
        void animatedTextureChange(std::string pathToNewTexture, SDL_Rect framesPos[]);
        bool checkIfOnGround(SDL_Rect player, std::vector<SDL_Rect> ground);
    protected:
        PhysicsSprite(int xPos,int yPos,int width,int height, std::map<std::string, std::string> sprites);
        ~PhysicsSprite(); //Osäker på om det ska vara protected???
        bool animatedTexture;
        int frame = 0;
        void animatedTick();
    private:
        SDL_Texture* texture;
        SDL_Rect framePositions[11];
        SDL_Rect* currentClip;
        std::map<std::string, std::string> spriteMap;


    };
}


#endif //PROG3_PHYSICSSPRITE_H
