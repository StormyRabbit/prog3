//
// Created by lasse on 1/17/18.
//

#include "TextInputSprite.h"

rootengine::TextInputSprite::TextInputSprite(int xPos, int yPos, int width, int height, std::string txt)
        :HUDSprite(xPos, yPos, width, height, txt){
    bool typing = true;
    SDL_Event e;
    SDL_StartTextInput();
    while(typing) {
        while(SDL_PollEvent( &e )) {
            if(e.type) {
             switch(e.type) {
                 case SDL_QUIT:
                     break;
                 case SDL_KEYDOWN:
                     keyPressed(e);
             }
            }
        }
    }

}

void rootengine::TextInputSprite::keyPressed(SDL_Event event) {
    if(event.key.keysym.sym == SDLK_BACKSPACE && getText().length() > 0) {
        // TODO: fixa erase
    }
    if( event.type == SDL_TEXTINPUT) {
        std::string newText = getText() + " " + event.text.text;
        setText(newText);
    }

}
