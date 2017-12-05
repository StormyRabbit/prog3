//
// Created by oskar on 05-Dec-17.
//

#ifndef PROG3_ENVIRONMENTSPRITE_H
#define PROG3_ENVIRONMENTSPRITE_H


#include "Sprite.h"
#include <string>

namespace rootengine{
    class EnvironmentSprite : public Sprite{
    public:
        static EnvironmentSprite* getInstance(int xPos, int yPos,int width,int height, std::string pathToSprite);
        ~EnvironmentSprite();
    protected:
        EnvironmentSprite(int xPos, int yPos, int width, int height, std::string pathToSprite);
    private:
        SDL_Texture* texture;
    };
}


#endif //PROG3_ENVIRONMENTSPRITE_H
