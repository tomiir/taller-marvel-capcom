//
// Created by trocchi on 6/9/19.
//

#ifndef TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H


#include "../AudioManager.h"

class ViewAudioManager : public AudioManager {
public:
    ~ViewAudioManager();
    ViewAudioManager();
    void init() override;
    void resetMusic();
};


#endif //TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H
