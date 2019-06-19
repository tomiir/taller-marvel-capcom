//
// Created by trocchi on 6/9/19.
//

#include "VenomAudioManager.h"

VenomAudioManager::VenomAudioManager() {
    init();
}

void VenomAudioManager::init() {
    audios["punch"] = new Audio("../Audio/Venom/punch.wav");
}