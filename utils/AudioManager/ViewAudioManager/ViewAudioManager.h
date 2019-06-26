//
// Created by trocchi on 6/9/19.
//

#ifndef TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H


#include "../AudioManager.h"

class ViewAudioManager : public AudioManager {
public:
    ~ViewAudioManager() = default;
    ViewAudioManager();
    void init() override;

private:
    void setVolume(int volume);
    void mute();
};


#endif //TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H
