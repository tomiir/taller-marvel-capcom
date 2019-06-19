//
// Created by trocchi on 6/8/19.
//

#include "SpiderManAudioManager.h"

void SpiderManAudioManager::init() {
    audios["punch"] = new Audio("../Audio/Spider-man/punch.wav");
}

SpiderManAudioManager::SpiderManAudioManager() {
    init();
}