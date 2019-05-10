//
// Created by magali on 01/05/19.
//

#include "Mapper_charSelect_2.h"


Mapper_charSelect_2::Mapper_charSelect_2():Mapper_charSelect(){
    //preselected = "SpiderMan";
    //map_preselected = spider_man;
}



char *Mapper_charSelect_2:: map( SDL_Event event) {

    char keys[6] = "00000";

    if (event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_d:
                keys[0] = 1;
                break;
            case SDLK_a:
                keys[1] = 1;
                break;
            case SDLK_w:
                keys[2] = 1;
                break;
            case SDLK_s:
                keys[3] = 1;
                break;
            case SDLK_c:
                keys[4] = 1;
            default:
                break;
        }
    }
        return "no_selecciono";

//    if (event.type == SDL_KEYDOWN) {
//
//        switch (event.key.keysym.sym) {
//
//            case SDLK_d:
//                preselected = map_preselected["right"];
//                break;
//            case SDLK_a:
//                preselected = map_preselected["left"];
//                break;
//            case SDLK_w:
//                preselected = map_preselected["up"];
//                break;
//            case SDLK_s:
//                preselected = map_preselected["down"];
//                break;
//            case SDLK_c:
//                return preselected;
//            default:
//                break;
//        }
//        map_preselected = map_map[preselected];
//    }
//    return "no_selecciono";

}
