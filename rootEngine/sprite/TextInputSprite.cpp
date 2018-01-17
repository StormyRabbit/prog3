//
// Created by lasse on 1/17/18.
//

#include "TextInputSprite.h"
#include "../System/System.h"

namespace rootengine{
    rootengine::TextInputSprite::TextInputSprite(int xPos, int yPos, int width, int height, std::string txt)
            :HUDSprite(xPos, yPos, txt){
        bool typing = true;
        SDL_Event e;
        SDL_StartTextInput();
        addText(rootengine::HUDSprite::getInstance(300,50, 0,0,"Welcome to Jumpy Boy!"));
        //addText(rootengine::HUDSprite::getInstance(300,200, 0,0,"Please enter name:"));
        addText(rootengine::HUDSprite::getInstance(300,400, 0,0,"Press enter to continue..."));

        for(HUDSprite* s : textToWelcomeScreen){
            s->draw();
        }
        SDL_RenderPresent(sys.getRenderer());
        while(typing) {
            while(SDL_PollEvent( &e )) {
                if(e.type) {
                     switch(e.type) {
                         case SDL_QUIT:
                             typing = false;
                             break;
                         case SDL_TEXTINPUT :
                             SDL_RenderClear(sys.getRenderer());
                             keyPressed(e);
                             drawInfoText();
                             draw();
                             SDL_RenderPresent(sys.getRenderer());
                             break;
                         case SDL_KEYDOWN:
                             if (e.key.keysym.sym == SDLK_RETURN){
                                 typing = false;
                             } else if (e.key.keysym.sym == SDLK_DELETE){
                                 deleteKeyPressed();
                             }
                     }
                }
            }
        }

    }

    void TextInputSprite::addText(HUDSprite *sprite) {
        textToWelcomeScreen.push_back(sprite);
    }

    void TextInputSprite::drawInfoText(){
        for(HUDSprite* s : textToWelcomeScreen){
            s->draw();
        }
    }

    void TextInputSprite::deleteKeyPressed(){
        std::string oldText = getText();
        std::string newText = oldText.substr(0, oldText.size()-1);
        setText(newText);
        SDL_RenderClear(sys.getRenderer());
        drawInfoText();
        draw();
        SDL_RenderPresent(sys.getRenderer());
    }


    void rootengine::TextInputSprite::keyPressed(SDL_Event event) {
        if( event.type == SDL_TEXTINPUT) {
            std::string newText = getText() + "" + event.text.text;
            setText(newText);
        }

    }

    rootengine::TextInputSprite *rootengine::TextInputSprite::getInstance(int x, int y, int w, int h, std::string txt) {
        return new TextInputSprite(x, y, w, h, txt);
    }
}