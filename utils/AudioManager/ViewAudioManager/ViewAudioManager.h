//
// Created by trocchi on 6/9/19.
//

#ifndef TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H

#include "SDL/SDL_mixer.h"
#include "../AudioMixer.h"
#include "SDL/SDL_mixer.h"

class ViewAudioManager : public AudioMixer {
public:
    ~ViewAudioManager() = default;
    ViewAudioManager();
    void init() override;
};


#endif //TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H
