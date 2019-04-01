//
// Created by magali on 01/04/19.
//

#include "EventToValueMapper.h"



EventToValueMapper::EventToValueMapper() {
    dir =  {0,0};
}

std::vector<int> EventToValueMapper::map(SDL_Event event){
    switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
            dir[0]++;
            break;
        case SDLK_LEFT:
            dir[0]--;
            break;
        case SDLK_UP:
            dir[1]++;
            break;
        case SDLK_DOWN:
            dir[1]--;
            break;
        default:
            break;
    }
    if(event.type == SDL_KEYUP){
        dir[1]*= -1;
    };
    return dir;
};
