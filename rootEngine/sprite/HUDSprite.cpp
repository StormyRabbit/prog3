//
// Created by Oskar on 2017-12-04.
//

#include "HUDSprite.h"
#include "../System/System.h"

namespace rootengine{
    HUDSprite::HUDSprite(int xPos, int yPos, std::string &txt) : Sprite(xPos,yPos,0,0), text(txt) {
        if (!sys.getFont()){
            std::cout<<"Misslyckades med att ladda in font fil.";
            exit(-1);
        }
        SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), {255,255,255});
        texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
        int texW = 0;
        int texH = 0;
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

        changeRect().h = texH;
        changeRect().w = texW;
        SDL_FreeSurface(surf);
    }

    HUDSprite* HUDSprite::getInstance(int xPos, int yPos, int width, int height, std::string txt) {
        return new HUDSprite(xPos, yPos, txt);
    }

    void HUDSprite::setText(std::string &newText) {
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
        int texW = 0;
        int texH = 0;
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        SDL_Rect dstrect = {getRect().x, getRect().y, texW, texH};
        SDL_RenderCopy(sys.getRenderer(), texture, nullptr, &dstrect);
    }

    HUDSprite::~HUDSprite() {
        SDL_DestroyTexture(texture);
    }

    void HUDSprite::update() {

    }

}
