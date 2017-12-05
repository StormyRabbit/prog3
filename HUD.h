//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_HUD_H
#define PROG3_HUD_H


#include "HUDSprite.h"
#include "Observer.h"
namespace rootengine {

    class HUD : public Observer {
    public:
        void addHUDElement(HUDSprite *he);

        void setHUDElements(std::vector<HUDSprite *> hudElementList);
        static HUD* getInstance();
        void draw();
        void update();

    protected:
        HUD();

    private:
        std::vector<HUDSprite *> hudElements;

    };

}
#endif //PROG3_HUD_H
