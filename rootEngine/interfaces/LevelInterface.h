//
// Created by lasse on 1/8/18.
//

#ifndef PROG3_LEVELINTERFACE_H
#define PROG3_LEVELINTERFACE_H
namespace rootengine {
    class LevelInterface {
    public:
        virtual bool isLevelComplete() = 0;
        virtual void drawLevel() = 0;
        virtual void tickLevel() = 0;
        virtual void getCollidableObjects() = 0;
    };
}

#endif //PROG3_LEVELINTERFACE_H
