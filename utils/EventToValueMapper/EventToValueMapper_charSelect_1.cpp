//
// Created by magali on 01/05/19.
//

#include "EventToValueMapper_charSelect_1.h"

EventToValueMapper_charSelect_1::EventToValueMapper_charSelect_1():EventToValueMapper_charSelect(){
    preselected = "captain_america";
    map_preselected = cap_america;
}



void EventToValueMapper_charSelect_1:: map(ViewController_charSelect* viewController, SDL_Event event){


    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_l:
                preselected = map_preselected["up"];
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
                preselected = map_preselected["up"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_m:
                viewController->setTeam1(preselected);
                break;
            default:
                break;
        }
        map_preselected = map_map[preselected];
}


