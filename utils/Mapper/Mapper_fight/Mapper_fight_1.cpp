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
                keys = MAP_RIGHT;
                break;
            case SDLK_j:
                keys = MAP_LEFT;
                break;
            case SDLK_i:
                keys = MAP_JUMP;
                break;
            case SDLK_k:
                keys = MAP_CROUCH;
                break;
            case SDLK_m:
                keys = MAP_CHANGE;
                break;
//Fijense si les parece esto, sino iría la O, pero como está el punch siempre se usa con el indice
            case SDLK_a:
                keys = MAP_PUNCH;
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_L] and keyboardStateArray[SDL_SCANCODE_I] ) {
            keys = MAP_JUMP_RIGHT;
        }

        if ( keyboardStateArray[SDL_SCANCODE_J] and keyboardStateArray[SDL_SCANCODE_I] ) {
            keys = MAP_JUMP_LEFT;
        }
    }

    if( event.type == SDL_KEYUP){

        switch (event.key.keysym.sym) {

            case SDLK_k:
                keys = MAP_GET_UP;
                break;
            case SDLK_j:
                keys = MAP_STOP_LEFT;
                break;
            case SDLK_l:
                keys = MAP_STOP_RIGHT;
                break;
            case SDLK_u:
                keys = MAP_STOP_PUNCH;
            default:
                break;
        }

    }

    return keys;
}




