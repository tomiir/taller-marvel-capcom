//
// Created by magali on 01/05/19.
//

#include "EventToValueMapper_charSelect_1.h"

EventToValueMapper_charSelect_1::EventToValueMapper_charSelect_1():EventToValueMapper_charSelect(){
    preselected = "cap_america";
    map_preselected = cap_america;
}



string EventToValueMapper_charSelect_1:: map( SDL_Event event) {


    if (event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_l:
                preselected = map_preselected["right"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_j:
                preselected = map_preselected["left"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_i:
                preselected = map_preselected["up"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_k:
                preselected = map_preselected["down"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_m:
                 return preselected;
                break;
            default:
                break;
        }
        map_preselected = map_map[preselected];
    }
    return "no_selecciono";
}

