//
// Created by Oskar on 2017-12-04.
//

#include "HUDSprite.h"
#include "System.h"
#include <iostream>

namespace rootengine{
    HUDSprite::HUDSprite(int xPos, int yPos, int width, int height, std::string txt) : Sprite(xPos,yPos,width,height), text(txt) {
        if (!sys.getFont()){
            exit(-1);
        }

        SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), {0,0,0});
        texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
        SDL_FreeSurface(surf);
    }

    HUDSprite* HUDSprite::getInstance(int xPos, int yPos, int width, int height, std::string txt) {
        return new HUDSprite(xPos, yPos, width, height, txt);
    }

    void HUDSprite::setText(std::string newText) {
        text = newText;
        SDL_DestroyTexture(texture);
        SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), {255,255,255});
        texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
        SDL_FreeSurface(surf);
    }

    std::string HUDSprite::getText() const {
        return text;
    }

    void HUDSprite::draw() const {
        SDL_RenderCopy(sys.getRenderer(), texture, NULL, &getRect());
    }

    HUDSprite::~HUDSprite() {
        SDL_DestroyTexture(texture);
    }

}
