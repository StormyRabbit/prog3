//
// Created by lasse on 1/3/18.
//

#ifndef PROG3_COLLISIONVARIABLES_H
#define PROG3_COLLISIONVARIABLES_H
namespace rootengine {
    struct CollisionVariables {
        bool standable{};
        static CollisionVariables *getInstance() {
            return new CollisionVariables();
        }

    private:
        CollisionVariables() = default;
    };
}

#endif //PROG3_COLLISIONVARIABLES_H
