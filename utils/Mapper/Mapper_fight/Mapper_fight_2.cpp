//
// Created by magali on 08/04/19.
//

#include "Mapper_fight_2.h"
#include <stdio.h>


char *Mapper_fight_2::map(SDL_Event event){

    //changeCharacter_ = false;

    const Uint8* keyboardStateArray = SDL_GetKeyboardState(nullptr);

    char keys[6] = "00000";

    //DirectionVector* direction = new DirectionVector(0,0);

    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_d:
                //direction->add(1, 0);
                keys[0] = 1;
                break;
            case SDLK_a:
                //direction->add(-1, 0);
                keys[1] = 1;
                break;
            case SDLK_w:
                //direction->add(0, -1);
                keys[2] = 1;
                break;
            case SDLK_s:
                //direction->add(0, 1);
                keys[3] = 1;
                break;
            case SDLK_c:
                //changeCharacter_ = true;
                keys[4] = 1;
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_D] and keyboardStateArray[SDL_SCANCODE_W] ) {
            //direction->setDiagonal(1);
            //direction->setY(-1);
            keys[0] = 1;
            keys[2] = 1;
        }

        if ( keyboardStateArray[SDL_SCANCODE_A] and keyboardStateArray[SDL_SCANCODE_W] ) {
            //direction->setDiagonal(-1);
            //direction->setY(-1);
            keys[1] = 1;
            keys[2] = 1;
        }
    }

//    if( event.type == SDL_KEYUP){
//
//        switch (event.key.keysym.sym) {
//
//            case SDLK_d:
//                //direction->add(2, 0);
//                keys[0] = 0;
//                break;
//            case SDLK_a:
//                //direction->add(-2, 0);
//                break;
//            case SDLK_w:
//                keys[2] = 0;
//                break;
//            case SDLK_s:
//                //direction->add(0, 2);
//                keys[3] = 0;
//                break;
//            case SDLK_c:
//                keys[4] = 0;
//                break;
//            default:
//                break;
//        }
//
//    }

    return keys;
}

