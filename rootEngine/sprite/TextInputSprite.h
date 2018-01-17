//
// Created by lasse on 1/17/18.
//

#ifndef PROG3_TEXTINPUTSPRITE_H
#define PROG3_TEXTINPUTSPRITE_H


#include "HUDSprite.h"

namespace rootengine {
    class TextInputSprite : public HUDSprite {
    public:
        static TextInputSprite* getInstance(int x, int y, int w, int h, std::string txt);
    protected:
        TextInputSprite(int xPos, int yPos,int width,int height, std::string txt);
    private:
        void keyPressed(SDL_Event event);
    };
}


#endif //PROG3_TEXTINPUTSPRITE_H
