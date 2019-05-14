//
// Created by magali on 01/05/19.
//

#include "Mapper_charSelect_1.h"

Mapper_charSelect_1::Mapper_charSelect_1():Mapper_charSelect(){

}



string Mapper_charSelect_1:: map( SDL_Event event) {

    string keys = "00000";

    if (event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_l:
                keys[0] = '1';
                break;
            case SDLK_j:
                keys[1] = '1';
                break;
            case SDLK_i:
                keys[2] = '1';
                break;
            case SDLK_k:
                keys[3] = '1';
                break;
            case SDLK_m:
                keys[4] = '1';
            default:
                break;
        }
    }
    return keys;

}

