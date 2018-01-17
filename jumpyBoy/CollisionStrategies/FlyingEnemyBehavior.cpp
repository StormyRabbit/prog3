//
// Created by lasse on 1/3/18.
//

#include "FlyingEnemyBehavior.h"
#include "../../jumpyBoy/enemy/Enemy.h"
#include "../enemy/FlyingEnemy.h"
#include "../player/Player.h"
#include "../player/JumpingState.h"
#include "../player/RunningJumpState.h"

void jumpyboy::FlyingEnemyBehavior::handleCollision(rootengine::PhysicsSprite *thisObj, rootengine::PhysicsSprite *otherObj, SDL_Rect &rect) {
    if(otherObj->getCollisionStrategy() != nullptr) {
        auto *e = (jumpyboy::FlyingEnemy*)thisObj;
        auto *p = (jumpyboy::Player*)otherObj;
        SDL_Point normRect = e->getNormalizedValue(rect.x, rect.y);

        if (normRect.y < (static_cast<double>(e->getRect().h * 0.10)) && e->getIsAlive()){
            bool hitDirectionLeft;
            if (normRect.x < (static_cast<double>(e->getRect().w * 0.5))){
                hitDirectionLeft = false;
                e->setFlyingDirection(hitDirectionLeft);
            } else {
                hitDirectionLeft = true;
                e->setFlyingDirection(hitDirectionLeft);
            }
            e->killEnemy();
            p->getYVelocity() = e->getBouncyPower();
            p->enterNewState(new JumpingState());
        } else {
            p->kill();
        }
    }
}
