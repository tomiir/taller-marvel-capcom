//
// Created by magali on 01/04/19.
//

#include "EventToValueMapper.h"

EventToValueMapper::EventToValueMapper(){}

DirectionVector* EventToValueMapper::map(SDL_Event event){


    const Uint8* keyboardStateArray = SDL_GetKeyboardState(nullptr);

    DirectionVector* direction = new DirectionVector(0,0);

    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_RIGHT:
                direction->add(1, 0);
                break;
            case SDLK_LEFT:
                direction->add(-1, 0);
                break;
            case SDLK_UP:
                direction->add(0, -1);
                break;
            case SDLK_DOWN:
                direction->add(0, 1);
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_RIGHT] and keyboardStateArray[SDL_SCANCODE_UP] ) {
            direction->setDiagonal(1);
            direction->setY(-1);
        }

        if ( keyboardStateArray[SDL_SCANCODE_LEFT] and keyboardStateArray[SDL_SCANCODE_UP] ) {
            direction->setDiagonal(-1);
            direction->setY(-1);
        }
    }

    return direction;
}

EventToValueMapper::~EventToValueMapper() = default;


