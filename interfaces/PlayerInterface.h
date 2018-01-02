//
// Created by lasse on 1/2/18.
//

#ifndef PROG3_PLAYERINTERFACE_H
#define PROG3_PLAYERINTERFACE_H

namespace rootengine {
    class PlayerInterface {
        virtual void kill() = 0;
        virtual void respawn() = 0;
    };
}

#endif //PROG3_PLAYERINTERFACE_H
