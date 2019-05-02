//
// Created by magali on 01/05/19.
//

#include "EventToValueMapper_charSelect_2.h"


EventToValueMapper_charSelect_2::EventToValueMapper_charSelect_2():EventToValueMapper_charSelect(){
    preselected = "spider_man";
    map_preselected = spider_man;
}



string EventToValueMapper_charSelect_2:: map( SDL_Event event) {


    if (event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_d:
                preselected = map_preselected["up"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_a:
                preselected = map_preselected["left"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_w:
                preselected = map_preselected["up"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_s:
                preselected = map_preselected["up"];
                map_preselected = map_map[preselected];
                break;
            case SDLK_c:
               return preselected;
            default:
                break;
        }
        map_preselected = map_map[preselected];
    }
        return NULL;

}
