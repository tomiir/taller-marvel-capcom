//
// Created by magali on 08/04/19.
//

#include "EventToValueMapper_player1.h"

DirectionVector *EventToValueMapper_player1::map(SDL_Event event) {

    changeCharacter_ = false;

    const Uint8* keyboardStateArray = SDL_GetKeyboardState(nullptr);

    DirectionVector* direction = new DirectionVector(0,0);

    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_l:
                direction->add(1, 0);
                break;
            case SDLK_j:
                direction->add(-1, 0);
                break;
            case SDLK_i:
                direction->add(0, -1);
                break;
            case SDLK_k:
                direction->add(0, 1);
                break;
            case SDLK_m:
                changeCharacter_= true;
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_L] and keyboardStateArray[SDL_SCANCODE_I] ) {
            direction->setDiagonal(1);
            direction->setY(-1);
        }

        if ( keyboardStateArray[SDL_SCANCODE_J] and keyboardStateArray[SDL_SCANCODE_I] ) {
            direction->setDiagonal(-1);
            direction->setY(-1);
        }
    }

    return direction;
}




