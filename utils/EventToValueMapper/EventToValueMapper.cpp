//
// Created by magali on 01/04/19.
//

#include "EventToValueMapper.h"


std::vector<int> EventToValueMapper::map(SDL_Event event, std::vector<int> dir){

    if( event.type == SDL_KEYDOWN){
        switch  (event.key.keysym.sym){
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
    }
    return dir;
};
