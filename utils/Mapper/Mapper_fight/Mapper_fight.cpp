//
// Created by magali on 01/04/19.
//

#include "Mapper_fight.h"

Mapper_fight::Mapper_fight(){
    changeCharacter_ = false;
}
string Mapper_fight :: map(SDL_Event event){}

bool Mapper_fight::changeCharacter(SDL_Event event){
    return changeCharacter_;
}