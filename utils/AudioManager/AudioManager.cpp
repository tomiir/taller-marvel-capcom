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

void AudioManager::setState(std::string state) {
    if(state != this->state) {
        cout << "Prev State: " << this->state << " - New state: " << state << endl;
        playAudio(state);
    }
    this->state = state;

}

void AudioManager::playAudio(string name) {
    if(audios.count(name)){
        Audio* audio = audios[name];
        audio->play();
    }
}

