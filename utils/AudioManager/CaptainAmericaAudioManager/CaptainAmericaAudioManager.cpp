//
// Created by trocchi on 6/8/19.
//

#include "CaptainAmericaAudioManager.h"

void CaptainAmericaAudioManager::init() {
    audios["punch"] = new Audio("../Audio/CaptainAmerica/punch.wav");
}

CaptainAmericaAudioManager::CaptainAmericaAudioManager() {
    init();
}