//
// Created by magali on 08/04/19.
//

#include "Mapper_fight_1.h"

char *Mapper_fight_1::map(SDL_Event event) {

    //changeCharacter_ = false;

    const Uint8* keyboardStateArray = SDL_GetKeyboardState(nullptr);

    //DirectionVector* direction = new DirectionVector(0,0);
    char keys[6] = "00000";


    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_l:
                //direction->add(1, 0);
                keys[0] = 1;
                break;
            case SDLK_j:
                //direction->add(-1, 0);
                keys[1] = 1;
                break;
            case SDLK_i:
                //direction->add(0, -1);
                keys[2] = 1;
                break;
            case SDLK_k:
                //direction->add(0, 1);
                keys[3] = 1;
                break;
            case SDLK_m:
                //changeCharacter_= true;
                keys[4] = 1;
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_L] and keyboardStateArray[SDL_SCANCODE_I] ) {
            //direction->setDiagonal(1);
            //direction->setY(-1);
            keys[0] = 1;
            keys[2] = 1;

        }

        if ( keyboardStateArray[SDL_SCANCODE_J] and keyboardStateArray[SDL_SCANCODE_I] ) {
        //    direction->setDiagonal(-1);
        //    direction->setY(-1);
            keys[1] = 1;
            keys[2] = 1;
        }
    }

//    if( event.type == SDL_KEYUP){
//
//        switch (event.key.keysym.sym) {
//
//            case SDLK_l:
//                //direction->add(2, 0);
//                keys[0] = 0;
//                break;
//            case SDLK_j:
//                //direction->add(-2, 0);
//                keys[1] = 0;
//                break;
//            case SDLK_i:
//                keys[2] = 0;
//                break;
//            case SDLK_k:
//                //direction->add(0, 2);
//                keys[3] = 0;
//                break;
//            case SDLK_m:
//                keys[4] = 0;
//                break;
//            default:
//                break;
//        }
//
//    }

    return keys;
}




