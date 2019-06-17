//
// Created by magali on 08/06/19.
//

#include "TimeManager.h"

TimeManager::TimeManager(int z, vector<GameObject*> unityNumbers, vector<GameObject*> tenNumbers, vector<GameObject*> rounds, GameObject* fight) {
    this->z = z;
    this->unity = 9;
    this->ten = 9;
    // ATENCION! LOS ROUNDS SE CUENTAN 0, 1, 2, PERO SON 1, 2, 3
    this->round = 0;
    this->roundTimer = 0;
    this->unityNumbers = unityNumbers;
    this->tenNumbers = tenNumbers;
    this->rounds = rounds;
    this->shouldFight = false;
    this->fight = fight;

}

void TimeManager::render() {
    if(!shouldFight) {
        tenNumbers[ten]->render();
        unityNumbers[unity]->render();
    }
    if (roundTimer < 2) rounds[round]->render();

    if (roundTimer == 2) fight->render();
}

int TimeManager::getZIndex() {
    return z;
}

void TimeManager::setUnity(int unityNew) {
    if (unity == unityNew) return;
    this->unity = unityNew;
    roundTimer ++;

}

void TimeManager::setTen(int ten) {
    this->ten = ten;
}

void TimeManager::setRound(int roundNew) {
    if(roundNew == round) return;
    round = roundNew;
    roundTimer = 0;

}

void TimeManager::updateShouldFight(int shouldFight) {
    this->shouldFight = shouldFight;
}





