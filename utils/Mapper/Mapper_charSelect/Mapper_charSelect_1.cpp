//
// Created by magali on 01/05/19.
//

#include "Mapper_charSelect_1.h"

Mapper_charSelect_1::Mapper_charSelect_1():Mapper_charSelect(){
    //preselected = "CaptainAmerica";
    //map_preselected = cap_america;
}



char *Mapper_charSelect_1:: map( SDL_Event event) {

    char keys[6] = "00000";

    if (event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_l:
                keys[0] = 1;
                break;
            case SDLK_j:
                keys[1] = 1;
                break;
            case SDLK_i:
                keys[2] = 1;
                break;
            case SDLK_k:
                keys[3] = 1;
                break;
            case SDLK_m:
                keys[4] = 1;
            default:
                break;
        }
    }
    return keys;

//    if (event.type == SDL_KEYDOWN) {
//
//        switch (event.key.keysym.sym) {
//
//            case SDLK_l:
//                preselected = map_preselected["right"];
//                break;
//            case SDLK_j:
//                preselected = map_preselected["left"];
//                break;
//            case SDLK_i:
//                preselected = map_preselected["up"];
//                break;
//            case SDLK_k:
//                preselected = map_preselected["down"];
//                break;
//            case SDLK_m:
//                 return preselected;
//            default:
//                break;
//        }
//        map_preselected = map_map[preselected];
//    }
//    return "no_selecciono";

}

