//
// Created by magali on 01/05/19.
//

#include "Mapper_charSelect_2.h"


Mapper_charSelect_2::Mapper_charSelect_2():Mapper_charSelect(){

}



string Mapper_charSelect_2:: map( SDL_Event event) {

    string keys = "00000";

    if (event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_d:
                keys[0] = '1';
                break;
            case SDLK_a:
                keys[1] = '1';
                break;
            case SDLK_w:
                keys[2] = '1';
                break;
            case SDLK_s:
                keys[3] = '1';
                break;
            case SDLK_c:
                keys[4] = '1';
            default:
                break;
        }
    }

    return keys;
}
