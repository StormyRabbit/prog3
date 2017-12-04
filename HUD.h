//
// Created by lasse on 11/24/17.
//

#ifndef PROG3_HUD_H
#define PROG3_HUD_H


#include "HUDElement.h"
#include "Observer.h"
namespace rootengine {

    class HUD : public Observer {
    public:
        void addHUDElement(HUDElement *he);

        void setHUDElements(std::vector<HUDElement *> hudElementList);

        void update();

    protected:

    private:

    };

}
#endif //PROG3_HUD_H
