//
// Created by trocchi on 6/7/19.
//

#ifndef TALLER_MARVEL_CAPCOM_AUDIO_H
#define TALLER_MARVEL_CAPCOM_AUDIO_H


#include <SDL_audio.h>

class Audio {
public:
    ~Audio();
    explicit Audio(const char* fileName);
    void load(const char* fileName);
    void play();

private:
    SDL_AudioSpec waveSpec;
    uint32_t  waveLength;
    uint8_t* waveBuffer;
    SDL_AudioDeviceID deviceID;
};


#endif //TALLER_MARVEL_CAPCOM_AUDIO_H
