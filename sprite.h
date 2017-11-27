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
           int width, std::string spritePath);
    ~sprite();
    virtual void draw() const = 0;

    int getXPos();
    int getYPos();
    int getHeight();
    int getWidth();
    SDL_Surface* createSurface();
    void drawTexture(SDL_Renderer* renderer, SDL_Surface* surface);

    std::string static getSpritePath();




protected:

private:
    std::string static spritePath;
    int xPos;
    int yPos;
    int height;
    int width;
};


#endif //PROG3_SPRITE_H
