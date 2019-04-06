//
// Created by magali on 01/04/19.
//

#include "EventToValueMapper.h"


std::vector<int> EventToValueMapper::map(SDL_Event event, std::vector<int> dir){

    const Uint8* keyboardStateArray = SDL_GetKeyboardState(nullptr);

    if( event.type == SDL_KEYDOWN) {

        switch (event.key.keysym.sym) {

            case SDLK_RIGHT:
                dir[0]++;
                break;
            case SDLK_LEFT:
                dir[0]--;
                break;
            case SDLK_UP:
                dir[1]--;
                break;
            case SDLK_DOWN:
                dir[1]++;
                break;
            default:
                break;
        }

        if ( keyboardStateArray[SDL_SCANCODE_RIGHT] and keyboardStateArray[SDL_SCANCODE_UP] ) {
            dir[2] = 1;
            dir[1] = -1;
        }

        if ( keyboardStateArray[SDL_SCANCODE_LEFT] and keyboardStateArray[SDL_SCANCODE_UP] ) {
            dir[2] = -1;
            dir[1] = -1;
        }
    }

    return dir;
};
