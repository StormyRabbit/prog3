//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_PHYSICSSPRITE_H
#define PROG3_PHYSICSSPRITE_H

#include "Sprite.h"
#include <SDL_image.h>
#include <string>

namespace rootengine{
    class PhysicsSprite : public Sprite {
    public:
        void draw() const;
    protected:
        PhysicsSprite(int xPos,int yPos,int width,int height, std::string pathToDraw);
        ~PhysicsSprite(); //Osäker på om det ska vara protected???
        void changeTexture(std::string pathToNewTexture); //Kan vara public, tror dock högre säkerhet och inget större behov av att öppna. ??
    private:
        SDL_Texture* texture;
    };
}


#endif //PROG3_PHYSICSSPRITE_H
