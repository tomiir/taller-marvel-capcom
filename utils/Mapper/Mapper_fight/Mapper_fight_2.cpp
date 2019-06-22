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
                keys = MAP_RIGHT;
                break;
            case SDLK_a:
                keys = MAP_LEFT;
                break;
            case SDLK_w:
                keys = MAP_JUMP;
                break;
            case SDLK_s:
                keys = MAP_CROUCH;
                break;
            case SDLK_c:
                keys = MAP_CHANGE;
                break;
            case SDLK_u:
                keys = MAP_WEAKPUNCH;
                break;
            case SDLK_i:
                keys = MAP_WEAKKICK;
                break;
            case SDLK_o:
                keys = MAP_STRONGPUNCH;
                break;
            case SDLK_p:
                keys = MAP_STRONGKICK;
                break;
            case SDLK_n:
                keys = MAP_GRAB;
                break;
            case SDLK_b:
                keys = MAP_GUARD;
                break;
            case SDLK_m:
                keys = MAP_THROW;
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_D] and keyboardStateArray[SDL_SCANCODE_W] ) {
            keys = MAP_JUMP_RIGHT;
        }

        if ( keyboardStateArray[SDL_SCANCODE_A] and keyboardStateArray[SDL_SCANCODE_W] ) {
            keys = MAP_JUMP_LEFT;
        }
    }

    if( event.type == SDL_KEYUP){

        switch (event.key.keysym.sym) {

            case SDLK_s:
                keys = MAP_GET_UP;
                break;
            case SDLK_a:
                keys = MAP_STOP_LEFT;
                break;
            case SDLK_d:
                keys = MAP_STOP_RIGHT;
                break;
            case SDLK_b:
                keys = MAP_STOP_GUARD;
                break;
            default:
                break;
        }

    }

    return keys;
}

