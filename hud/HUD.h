//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_HUD_H
#define PROG3_HUD_H
#include <vector>
#include "HUDSprite.h"
#include "../interfaces/Drawable.h"

namespace rootengine {
    class HUD : public Drawable {
    public:
        void addHUDElement(class HUDSprite *he);
        static HUD* getInstance();
        void draw() override;
        ~HUD();
    protected:
        HUD() = default;
    private:
        std::vector<HUDSprite *> hudElements;
    };
}
#endif //PROG3_HUD_H
