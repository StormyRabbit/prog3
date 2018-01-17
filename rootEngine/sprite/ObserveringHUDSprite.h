//
// Created by lasse on 1/17/18.
//

#ifndef PROG3_OBSERVERINGHUDSPRITE_H
#define PROG3_OBSERVERINGHUDSPRITE_H

#include "HUDSprite.h"
#include "../System/System.h"

namespace rootengine {
    template<typename T>
    class ObservingHUDSprite: public HUDSprite{
    public:
        static ObservingHUDSprite *getInstance(int xPos, int yPos, int width, int height, std::string &txt, T *obj, int(T::*func)() ) {
            return new ObservingHUDSprite(xPos, yPos, width, height, txt, obj, func);
        }

        void draw() const override {
            SDL_RenderCopy(sys.getRenderer(), texture, nullptr, &getRect());
        }
        void update() override {
            int value = (obj->*func)();
            std::string newText = getText() + " " + std::to_string(value);
            SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), newText.c_str(), {255,255,255});
            texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
            SDL_FreeSurface(surf);
        }
    protected:
        ObservingHUDSprite(int xPos, int yPos, int width, int height, std::string &txt, T *obj, int(T::*func)())
                :obj(obj), func(func), HUDSprite(xPos,yPos,width,height, txt) {}
    private:
        T *obj;
        int (T:: *func)();
    };
}
#endif //PROG3_OBSERVERINGHUDSPRITE_H
