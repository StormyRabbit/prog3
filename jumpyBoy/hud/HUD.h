//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_HUD_H
#define PROG3_HUD_H
#include <vector>
#include "../../rootEngine/sprite/HUDSprite.h"
#include "../../rootEngine/interfaces/Drawable.h"

namespace jumpyboy {
    class HUD : public rootengine::Drawable {
    public:
        void addHUDElement(rootengine::HUDSprite *he);
        static HUD* getInstance(rootengine::GameEngine *);
        void draw() override;
        ~HUD();
    protected:
        HUD(rootengine::GameEngine *);
    private:
        std::vector<rootengine::HUDSprite *> hudElements;
    };
}
#endif //PROG3_HUD_H
