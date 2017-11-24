//
// Created by lasse on 11/24/17.
//

#include<string>
#ifndef PROG3_SPRITE_H
#define PROG3_SPRITE_H


class sprite {
public:
    sprite(int x, int y, int height,
           int width, std::string spritePath);
    virtual void draw() const = 0;

protected:

private:
    std::string spritePath;
    int x;
    int y;
    int height;
    int width;
};


#endif //PROG3_SPRITE_H
