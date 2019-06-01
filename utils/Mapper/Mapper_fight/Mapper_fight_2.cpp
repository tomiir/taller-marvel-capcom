//
// Created by magali on 08/04/19.
//

#include "Mapper_fight_2.h"
#include <stdio.h>


string Mapper_fight_2::map(SDL_Event event){

    const Uint8* keyboardStateArray = SDL_GetKeyboardState(nullptr);

   string keys = "h";


    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_d:
                keys = 'd';
                break;
            case SDLK_a:
                keys = 'a';
                break;
            case SDLK_w:
                keys = 'w';
                break;
            case SDLK_s:
                keys = 's';
                break;
            case SDLK_c:
                keys = 'c';
                break;
            case SDLK_e:
                keys = 'e';
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_D] and keyboardStateArray[SDL_SCANCODE_W] ) {
            keys = 'e';
        }

        if ( keyboardStateArray[SDL_SCANCODE_A] and keyboardStateArray[SDL_SCANCODE_W] ) {
            keys = 'q';
        }
    }

    if( event.type == SDL_KEYUP){

        switch (event.key.keysym.sym) {

            case SDLK_s:
                keys = 'r';
                break;
            case SDLK_a:
                keys = 't';
                break;
            case SDLK_d:
                keys = 'y';
                break;
            default:
                break;
        }

    }

    return keys;
}

