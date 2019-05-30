//
// Created by magali on 01/05/19.
//

#include "Mapper_charSelect_2.h"


Mapper_charSelect_2::Mapper_charSelect_2():Mapper_charSelect(){

}



string Mapper_charSelect_2:: map( SDL_Event event) {

    string keys = "h";

    if (event.type == SDL_KEYDOWN) {

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
            default:
                break;
        }
    }

    return keys;
}
