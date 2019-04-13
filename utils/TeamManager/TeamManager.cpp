//
// Created by magali on 08/04/19.
//

#include "TeamManager.h"

TeamManager::TeamManager(ControllerCharacter* character_1, ControllerCharacter* character_2, SDL_RendererFlip initialFlip){

    currentCharacter = character_1;
    supportCharacter = character_2;
    flip = initialFlip;
}

void TeamManager::changeCharacter(){

    ControllerCharacter* aux;
    aux = currentCharacter;
    currentCharacter = supportCharacter;
    supportCharacter = aux;
}

void TeamManager::render(){
    currentCharacter->render();
}
void TeamManager:: handleEvent(SDL_Event event, std::vector<ControllerBackground*> backgrounds){

    currentCharacter->handleEvent(event);

    if (currentCharacter->getMapper()->changeCharacter(event)){
        changeCharacter();
        currentCharacter->flip(flip);
    }
    for (std::vector<ControllerBackground*>::iterator controllerBackground=backgrounds.begin(); controllerBackground != backgrounds.end(); ++controllerBackground) {
       //Creo que devuelve un puntero al puntero de controller, por eso lo desreferencio.
        (*controllerBackground)->handleEvent(event,currentCharacter, enemyTeam->getCurrentCharacter() );
    }
}

void TeamManager::addEnemyTeam(TeamManager *enemyTeam_) {

    enemyTeam = enemyTeam_;

}

ControllerCharacter* TeamManager::getCurrentCharacter() {

    return currentCharacter;

}

void TeamManager::flipCurrentCharacter() {

    if (flip == SDL_FLIP_NONE) flip = SDL_FLIP_HORIZONTAL;
    else flip = SDL_FLIP_NONE;

    currentCharacter->flip(flip);

}
