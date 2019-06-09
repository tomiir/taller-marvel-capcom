//
// Created by trocchi on 6/9/19.
//

#include "ChunLiAudioManager.h"

ChunLiAudioManager::ChunLiAudioManager() {
    init();
}

void ChunLiAudioManager::init() {
    audios["punch"] = new Audio("../Audio/Chun-Li/punch.wav");
}

