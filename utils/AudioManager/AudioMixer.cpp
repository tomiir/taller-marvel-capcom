//
// Created by trocchi on 6/24/19.
//

#include "AudioMixer.h"
#include <iostream>

using namespace std;

AudioMixer::AudioMixer() {}

AudioMixer::~AudioMixer() {}
void AudioMixer::init() {}

void AudioMixer::setState(string state) {
    cout << "Cambio musica a " << state << endl;
    if(state != this->state) {
        changeMusic(state);
    }
    this->state = state;
}

void AudioMixer::changeMusic(string name) {

    // Pongo a correr para siempre la nueva musica
    if(music.count(name)) {
        Mix_Music *currentAudio = music[name];
        if(Mix_PlayMusic(currentAudio, -1) < 0) {
            cout << "No se pudo playear: "<< Mix_GetError() << endl;
        };
    }
}

void AudioMixer::playSFX(string type) {
    if(audios.count(type)) {
        Mix_Chunk* currentSfx = audios[type];
        Mix_PlayChannel(-1, currentSfx, 1);
    }
}

void AudioMixer::toggleMute() {
    if(muted) {
        Mix_VolumeMusic(128);
        Mix_Volume(-1, 128);
    }
    else {
        Mix_Volume(-1, 0);
        Mix_VolumeMusic(0);
    }
    muted = !muted;
}

