//
// Created by trocchi on 6/7/19.
//

#include "Audio.h"

Audio::~Audio() {
    SDL_CloseAudioDevice(deviceID);
    SDL_FreeWAV(waveBuffer);
}


void Audio::load(const char* fileName) {
    SDL_LoadWAV(fileName, &waveSpec, &waveBuffer, &waveLength);
    deviceID = SDL_OpenAudioDevice(NULL, 0, &waveSpec, NULL, 0);
}

void Audio::play() {
    SDL_QueueAudio(deviceID, waveBuffer, waveLength);
    SDL_PauseAudioDevice(deviceID, 0);
}

Audio::Audio(const char *fileName) {
    this->load(fileName);
}

void Audio::stop() {
    SDL_PauseAudioDevice(deviceID, 1);
}

