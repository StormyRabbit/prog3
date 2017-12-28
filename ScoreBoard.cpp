//
// Created by lasse on 12/26/17.
//

#include <SDL_events.h>
#include "ScoreBoard.h"
#include "hud/HUDSprite.h"
namespace rootengine {
    ScoreBoard *ScoreBoard::getInstance() {
        return new ScoreBoard();
    }

    void ScoreBoard::readNewEntry() {
        bool running = true;
        SDL_Color textColor = {0,0,0,0xFF};
        bool renderText = false;
        SDL_StartTextInput();
        std::string inputText;
        SDL_Event event;

        while(running) {
            while (SDL_PollEvent(&event)) {
                if(event.type == SDL_KEYDOWN) {
                    if(event.key.keysym.sym == SDLK_RETURN) {
                        running = false;
                        break;
                    }
                    if(event.key.keysym.sym == SDLK_BACKSLASH && inputText.length() > 0) {
                        inputText.pop_back();
                        renderText = true;
                    } else {
                        inputText += event.text.text;
                        renderText = true;
                    }
                }
                if(renderText) {
                }
            } // while Poll
        }
    }
}
