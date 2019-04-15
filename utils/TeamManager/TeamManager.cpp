//
// Created by magali on 08/04/19.
//

#include "TeamManager.h"

TeamManager::TeamManager(ControllerCharacter* character_1, ControllerCharacter* character_2, SDL_RendererFlip initialFlip) : Renderable(){

    currentCharacter = character_1;
    supportCharacter = character_2;
    flip = initialFlip;
}

int TeamManager::getZIndex() {
    return currentCharacter->getZIndex();
}
void TeamManager::changeCharacter(){

    ControllerCharacter* aux;
    aux = currentCharacter;
    currentCharacter = supportCharacter;
    supportCharacter = aux;

    currentCharacter->changePosition(supportCharacter->getInfo()[0], supportCharacter->getInfo()[1]);
}

void TeamManager::render(){
    currentCharacter->render();
}
void TeamManager:: handleEvent(SDL_Event event, std::vector<ControllerBackground*> backgrounds){

    currentCharacter->handleEvent(event);

    if (currentCharacter->getInfo()[1] < -300){
        changeCharacter();
        supportCharacter->gone();
        currentCharacter->entry();
        currentCharacter->flip(flip);
    }
    for (std::vector<ControllerBackground*>::iterator controllerBackground=backgrounds.begin(); controllerBackground != backgrounds.end(); ++controllerBackground) {

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
