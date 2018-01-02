//
// Created by oskar on 05-Dec-17.
//

#ifndef PROG3_NONCOLLENVIRONMENTSPRITE_H
#define PROG3_NONCOLLENVIRONMENTSPRITE_H


#include "Sprite.h"
#include <string>

namespace rootengine{
    class NonCollEnvironment : public Sprite{
    public:
        static NonCollEnvironment* getInstance(int xPos, int yPos,int width,int height, std::string pathToSprite);
        void draw() const;
        ~NonCollEnvironment();
    protected:
        NonCollEnvironment(int xPos, int yPos, int width, int height, std::string pathToSprite);
    private:
        SDL_Texture* texture;
    };
}


#endif //PROG3_NONCOLLENVIRONMENTSPRITE_H
