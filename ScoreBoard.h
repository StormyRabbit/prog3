//
// Created by lasse on 12/26/17.
//

#ifndef PROG3_SCOREBOARD_H
#define PROG3_SCOREBOARD_H

#include <string>
namespace rootengine {
    class ScoreBoard {
    public:
        void readNewEntry();
        ScoreBoard *getInstance();
    protected:
        ScoreBoard() = default;
    private:
    };
}


#endif //PROG3_SCOREBOARD_H
