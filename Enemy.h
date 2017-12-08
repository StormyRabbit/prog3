//
// Created by oskar on 05-Dec-17.
//

#ifndef PROG3_ENEMY_H
#define PROG3_ENEMY_H

namespace rootengine{
    class Enemy {
    public:
        static Enemy* getInstance(int xPos, int yPos,int width,int height);
    protected:
        Enemy(int xPos, int yPos, int width, int height);
    private:
        bool alive;
    };
}


#endif //PROG3_ENEMY_H
