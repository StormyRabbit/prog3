//
// Created by lasse on 1/17/18.
//

#include "TextInputSprite.h"
#include "../System/System.h"

rootengine::TextInputSprite::TextInputSprite(int xPos, int yPos, int width, int height, std::string txt)
        :HUDSprite(xPos, yPos, width, height, txt){
    bool typing = true;
    SDL_Event e;
    SDL_StartTextInput();
    SDL_RenderClear(sys.getRenderer());
    while(typing) {
        draw();
        while(SDL_PollEvent( &e )) {
            if(e.type) {
                 switch(e.type) {
                     case SDL_QUIT:
                         break;
                     case SDL_KEYDOWN:
                         keyPressed(e);
                         if (e.key.keysym.sym == SDLK_RETURN){
                             typing = false;
                         }

                         SDL_RenderPresent(sys.getRenderer());
                 }
            }
        }
    }

   // SDL_RenderPresent(sys.getRenderer());

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

rootengine::TextInputSprite *rootengine::TextInputSprite::getInstance(int x, int y, int w, int h, std::string txt) {
    return new TextInputSprite(x, y, w, h, txt);
}
