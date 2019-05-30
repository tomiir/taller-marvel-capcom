//
// Created by magali on 01/05/19.
//

#include "Mapper_charSelect_1.h"

Mapper_charSelect_1::Mapper_charSelect_1():Mapper_charSelect(){

}



string Mapper_charSelect_1:: map( SDL_Event event) {

    string keys = "h";

    if (event.type == SDL_KEYDOWN) {

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
            default:
                break;
        }
    }
    return keys;

}

