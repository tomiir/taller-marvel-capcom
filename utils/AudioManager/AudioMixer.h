//
// Created by trocchi on 6/24/19.
//

#ifndef TALLER_MARVEL_CAPCOM_AUDIOMIXER_H
#define TALLER_MARVEL_CAPCOM_AUDIOMIXER_H

#include <vector>
#include <string>
#include <map>
#include "SDL/SDL_mixer.h"

using namespace std;

class AudioMixer {
public:
    ~AudioMixer();
    AudioMixer();
    void setState(string state);
    void playSFX(string type);
    void toggleMute();
    virtual void init();

protected:
    void changeMusic(string name);
    map<string, Mix_Music*> music;
    map<string, Mix_Chunk*> audios;
    string state;
    bool muted = false;
};

#endif //TALLER_MARVEL_CAPCOM_AUDIOMIXER_H
