//
// Created by magali on 01/04/19.
//

#include "EventToValueMapper.h"

EventToValueMapper::EventToValueMapper(){
    changeCharacter_ = false;
}
DirectionVector* EventToValueMapper :: map(SDL_Event event){}

bool EventToValueMapper::changeCharacter(SDL_Event event){
    return changeCharacter_;
}