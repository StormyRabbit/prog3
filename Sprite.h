//
// Created by Oskar on 2017-12-04.
//

#ifndef PROG3_SPRITE_H
#define PROG3_SPRITE_H

#include <SDL.h>

namespace rootengine{
    class Sprite {
    public:
        virtual ~Sprite();
        virtual void mouseDown(const SDL_Event&){};
        virtual void mouseUp(const SDL_Event&){};
        virtual void keyDown(const SDL_Event&){};
        virtual void keyUp(const SDL_Event&){};
        virtual void draw() const = 0;
        const SDL_Rect& getRect() const { return rect; }
    protected:
        Sprite(int xPos, int yPos, int width, int height);
    private:
        SDL_Rect rect;
        Sprite(const Sprite&) = delete;
        const Sprite& operator=(const Sprite&) = delete;
    };
}


#endif //PROG3_SPRITE_H
