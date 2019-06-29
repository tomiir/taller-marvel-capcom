//
// Created by trocchi on 6/9/19.
//

#include "ViewAudioManager.h"
#include <random>
#include <iostream>

ViewAudioManager::ViewAudioManager() {
    init();
}

void ViewAudioManager::init() {
    string file_id = to_string(rand() % 3 + 1);
    string file = "../Audio/Music/music" + file_id + ".wav";
    audios["fight"] = new Audio(file.c_str());
    audios["char_select"] = new Audio("../Audio/Music/char_select.wav");
    audios["endgame"] = new Audio("../Audio/Music/endgame.wav");
    this->state = "present";
    this->oldValue = -1;
}

void ViewAudioManager::resetMusic(int soundFlag) {
    if (soundFlag != oldValue && soundFlag == 0){
        this->playAudio(this->state);
        oldValue = soundFlag;
    }
    if (soundFlag == 1)
        oldValue = soundFlag;

}

ViewAudioManager::~ViewAudioManager() {
    map<string,Audio*>::iterator iter = audios.begin();
    while(iter != audios.end()) {
        Audio* curAudio = iter->second;
        delete curAudio;
    }
}

