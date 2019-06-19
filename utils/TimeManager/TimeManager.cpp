//
// Created by magali on 08/06/19.
//

#include "TimeManager.h"

TimeManager::TimeManager(int z, GameObject* unityNumbers, GameObject* tenNumbers, GameObject* roundFight,
            map<int, vector<int>> sourcePosition){
    this->z = z;
    this->unity = 9;
    this->ten = 9;
    // ATENCION! LOS ROUNDS SE CUENTAN 0, 1, 2, PERO SON 1, 2, 3
    this->round = 0;
    this->roundTimer = 0;
    this->unityNumbers = unityNumbers;
    this->tenNumbers = tenNumbers;
    this->roundFight = roundFight;
    this->shouldFight = false;
    this->sourcePosition = sourcePosition;

}

void TimeManager::render() {
    if(shouldFight) {
        sourcePosition_itr = sourcePosition.find(ten);
        tenNumbers->setOriginRect(sourcePosition_itr->second);
        tenNumbers->render();
        sourcePosition_itr = sourcePosition.find(unity);
        unityNumbers->setOriginRect(sourcePosition_itr->second);
        unityNumbers->render();
    }
    if (roundTimer < 2){
        switch(round) {
            case 0:
                sourcePosition_itr = sourcePosition.find(10);
                roundFight->setOriginRect(sourcePosition_itr->second);
            case 1:
                sourcePosition_itr = sourcePosition.find(11);
                roundFight->setOriginRect(sourcePosition_itr->second);
            case 2:
                sourcePosition_itr = sourcePosition.find(12);
                roundFight->setOriginRect(sourcePosition_itr->second);
        }
        roundFight->render();
    }

    if (roundTimer == 2){
        sourcePosition_itr = sourcePosition.find(13);
        roundFight->setOriginRect(sourcePosition_itr->second);
        roundFight->render();
    }
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





