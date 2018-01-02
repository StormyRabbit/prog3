//
// Created by oskar on 02-Jan-18.
//

#ifndef PROG3_ENVIRONMENTSPRITE_H
#define PROG3_ENVIRONMENTSPRITE_H

#include "../PhysicsSprite.h"

namespace rootengine{
    typedef std::map<std::string, std::string> spritesMap;
    typedef std::map<std::string, std::vector<SDL_Rect>> fMapType;
    class EnvironmentSprite :  public PhysicsSprite {
    public:
        ~EnvironmentSprite();
        static EnvironmentSprite* getInstance(int xPos, int yPos, int height, int width,spritesMap sprites, fMapType frames);
    protected:
        EnvironmentSprite(int xPos, int yPos, int height, int width,spritesMap sprites, fMapType frames);
    private:

    };
}


#endif //PROG3_ENVIRONMENTSPRITE_H
