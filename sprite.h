//
// Created by lasse on 11/24/17.
//

#include<string>
#include <SDL_render.h>

#ifndef PROG3_SPRITE_H
#define PROG3_SPRITE_H


class sprite {
public:
    //sprite();
    sprite(int xPos, int yPos, int height,
           int width);
    ~sprite();
    //virtual void draw() const = 0; MAKES ABSTRACT REMOVE COMMENT LATER

    int getXPos();
    int getYPos();
    int getHeight();
    int getWidth();
    SDL_Surface* createSurface();
    void drawTexture(SDL_Renderer* renderer);

    std::string static getSpritePath();




protected:

private:
    std::string static spritePath;
    int xPos;
    int yPos;
    int height;
    int width;
};

std::string sprite::spritePath = "../sprites/Tiles/box.png";

#endif //PROG3_SPRITE_H
