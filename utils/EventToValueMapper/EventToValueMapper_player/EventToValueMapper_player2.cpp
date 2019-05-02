//
// Created by magali on 08/04/19.
//

#include "EventToValueMapper_player2.h"
#include <stdio.h>


DirectionVector *EventToValueMapper_player2::map(SDL_Event event){

    changeCharacter_ = false;

    const Uint8* keyboardStateArray = SDL_GetKeyboardState(nullptr);

    DirectionVector* direction = new DirectionVector(0,0);

    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_d:
                direction->add(1, 0);
                break;
            case SDLK_a:
                direction->add(-1, 0);
                break;
            case SDLK_w:
                direction->add(0, -1);
                break;
            case SDLK_s:
                direction->add(0, 1);
                break;
            case SDLK_c:
                changeCharacter_ = true;
                break;
            default:
                break;
        }

    if ( keyboardStateArray[SDL_SCANCODE_D] and keyboardStateArray[SDL_SCANCODE_W] ) {
            direction->setDiagonal(1);
            direction->setY(-1);
        }

        if ( keyboardStateArray[SDL_SCANCODE_A] and keyboardStateArray[SDL_SCANCODE_W] ) {
            direction->setDiagonal(-1);
            direction->setY(-1);
        }
    }

    if( event.type == SDL_KEYUP){

        switch (event.key.keysym.sym) {

            case SDLK_s:
                direction->add(0, 2);
                break;
            default:
                break;
        }

    }

    return direction;
}

