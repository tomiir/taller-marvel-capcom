//
// Created by magali on 08/04/19.
//

#include "Mapper_fight_1.h"

string Mapper_fight_1::map(SDL_Event event) {

    const Uint8* keyboardStateArray = SDL_GetKeyboardState(nullptr);

    string keys = "h";


    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_l:
                keys = 'd';
                break;
            case SDLK_j:
                keys = 'a';
                break;
            case SDLK_i:
                keys = 'w';
                break;
            case SDLK_k:
                keys = 's';
                break;
            case SDLK_m:
                keys = 'c';
                break;
//Fijense si les parece esto, sino iría la O, pero como está el punch siempre se usa con el indice
            case SDLK_u:
                keys = 'e';
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_L] and keyboardStateArray[SDL_SCANCODE_I] ) {
            keys = 'e';
        }

        if ( keyboardStateArray[SDL_SCANCODE_J] and keyboardStateArray[SDL_SCANCODE_I] ) {
            keys = 'q';
        }
    }

    if( event.type == SDL_KEYUP){

        switch (event.key.keysym.sym) {

            case SDLK_k:
                keys = 'r';
                break;
            case SDLK_j:
                keys = 't';
                break;
            case SDLK_l:
                keys = 'y';
                break;
            default:
                break;
        }

    }

    return keys;
}




