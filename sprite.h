//
// Created by lasse on 11/24/17.
//

#include<string>
#ifndef PROG3_SPRITE_H
#define PROG3_SPRITE_H


class sprite {
public:
    //sprite();
    sprite(int xPos, int yPos, int height,
           int width, std::string spritePath): xPos(xPos) , yPos(yPos), height(height), width(width), spritePath(spritePath) {};
    ~sprite();
    virtual void draw() const = 0;

    int getXPos();
    int getYPos();
    int getHeight();
    int getWidth();
    int getSpritePath();



protected:

private:
    std::string spritePath;
    int xPos;
    int yPos;
    int height;
    int width;
};


#endif //PROG3_SPRITE_H
