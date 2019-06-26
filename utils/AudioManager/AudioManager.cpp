//
// Created by trocchi on 6/7/19.
//

#include "AudioManager.h"
#include <string>
#include <iostream>

using namespace std;

AudioManager::~AudioManager() {}
AudioManager::AudioManager() {}
void AudioManager::init() {}

bool AudioManager::justFell(string state) {
    return this->state == "jump" && (state == "still" || state == "walk");
}

void AudioManager::setState(std::string state) {
    if(justFell(state)) {
        playAudio("fall");
    }
    else if(state != this->state) {
            playAudio(state);

    }
        this->state = state;

}

void AudioManager::playAudio(string name) {
    if(audios.count(this->state)){
        audios[this->state]->stop();
    }
    if(audios.count(name)){
        Audio* audio = audios[name];
        audio->play();
    }
}

