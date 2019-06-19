//
// Created by magali on 08/04/19.
//

#include "TeamManager.h"

TeamManager::TeamManager(SDL_RendererFlip initialFlip){

    flip = initialFlip;
    cantChangeChar = 0;

}

void TeamManager:: setCharacters(std::vector<ControllerCharacter*> characters){
    currentCharacter = characters[0];
    supportCharacter = characters[1];

    firstCharacter = characters[0];
    secondCharacter = characters[1];
}

void TeamManager::changeCharacter(){

    ControllerCharacter* aux;
    aux = currentCharacter;
    currentCharacter = supportCharacter;
    supportCharacter = aux;

    currentCharacter->changePosition(supportCharacter->getInfo()[0], supportCharacter->getInfo()[1]);
}

void TeamManager:: handleEvent(string event, std::vector<ControllerBackground*> backgrounds){

    currentCharacter->handleEvent(event, enemyTeam->getCurrentCharacter()->getGameObject(), enemyTeam->getCurrentCharacter(), supportCharacter->getLife());

    if (currentCharacter->getInfo()[1] < -300){
        changeCharacter();
        supportCharacter->gone();
        cantChangeChar++;
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

void TeamManager::setInitialPos(bool left) {

    currentCharacter->setInitialPos(left);

    initialFlip = left;
}

vector<int> TeamManager::getPosCurrentCharacter() {
    return currentCharacter->getPosInfo();
}

char TeamManager::getStateCurrentCharacter() {

    string state = currentCharacter->getState();
    if (state == "still") return '0';
    else if (state == "walk") return '1';
    else if (state == "jump") return '2';
    else if (state == "crowchedDown") return '3';
    else if (state == "entering") return '4';
    else if (state == "weakStandPunch") return '5';
    else if (state == "weakDownPunch") return '6';
    else if (state == "weakAirPunch") return '7';
    else if (state == "weakStandKick") return '8';
    else if (state == "weakDownKick") return '9';
    else if (state == "weakAirKick") return 'a';
    else if (state == "strongStandPunch") return 'b';
    else if (state == "strongDownPunch") return 'c';
    else if (state == "strongAirPunch") return 'd';
    else if (state == "strongStandKick") return 'e';
    else if (state == "strongDownKick") return 'f';
    else if (state == "strongAirKick") return 'g';
    else if (state == "standGuard") return 'h';
    else if (state == "downGuard") return 'i';
    else if (state == "airGuard") return 'j';
    else if (state == "standKicked") return 'k';
    else if (state == "downKicked") return 'l';
    else if (state == "airKicked") return 'm';



}

char TeamManager::getFlipCurrentCharacter() {

    SDL_RendererFlip flip = currentCharacter->getFlip();

    if(flip == SDL_FLIP_NONE) return '0';
    if(flip == SDL_FLIP_HORIZONTAL) return '1';
}

char TeamManager::getCurrentCharacterNumber() {

    if ((cantChangeChar % 2) == 0) return '0';
    else return '1';
}

int TeamManager::currentCharacterPlaying() {

    if ((cantChangeChar % 2) == 0) return 0;
    else return 1;
}

int TeamManager::getCurrentCharacterLife() {

    return currentCharacter->getLife();
}

bool TeamManager::getTeamLife() {

    int life1 = currentCharacter->getLife();
    int life2 = supportCharacter->getLife();

    return life1 + life2;
}

void TeamManager::roundWin() {
    rounds_wins++;
}

void TeamManager::resetRound() {

    currentCharacter->resetLife();
    supportCharacter->resetLife();

    currentCharacter = firstCharacter;
    supportCharacter = secondCharacter;
    currentCharacter->resetPosition(initialFlip);

    if ((cantChangeChar % 2) != 0) cantChangeChar++;
}

int TeamManager::getRoundWon() {
    return rounds_wins;
}
