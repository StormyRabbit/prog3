//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_HUDSPRITE_H
#define PROG3_HUDSPRITE_H

#include "Sprite.h"
#include "../System/GameEngine.h"
#include <string>
#include "../System/GameEngine.h"

namespace rootengine {
    class HUDSprite : public Sprite {
    public:
        static HUDSprite* getInstance(int xPos, int yPos,int width,int height, std::string txt);
        std::string getText() const;
        void setText(std::string &newText);
        void setValueToObserver(class GameEngine*, int (GameEngine:: *fpoint)());
        void draw() const override;
        ~HUDSprite() override;

    protected:
        HUDSprite(int xPos, int yPos,int width,int height, std::string &txt);
    private:
        GameEngine* ge;
        int (GameEngine:: *fpointer)();
        std::string text;
        SDL_Texture* texture;
    };
}


#endif //PROG3_HUDSPRITE_H