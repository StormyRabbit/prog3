//
// Created by lasse on 11/24/17.
//

#include <SDL_image.h>
#include "sprite.h"
/*void sprite::draw() const {

}*/


sprite::sprite(int x, int y, int height,
               int width) : xPos(xPos), yPos(yPos), height(height) {}

int sprite::getXPos() { return xPos; }
int sprite::getYPos() { return yPos; }
int sprite::getHeight() { return height;}
int sprite::getWidth() { return width;}
std::string static sprite::getSpritePath() { return spritePath; };

SDL_Surface* createSurface(){
    SDL_Surface* thisSurface;
    std::string str = sprite::getSpritePath();
    thisSurface = IMG_Load(str.c_str());

    return thisSurface;
}

void drawTexture(SDL_Renderer* renderer){
    SDL_Surface* surface = createSurface();
    SDL_Texture* newTexture;
    newTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, newTexture, NULL, NULL);
}


