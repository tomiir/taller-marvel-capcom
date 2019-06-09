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
};


#endif //TALLER_MARVEL_CAPCOM_FIGHTAUDIOMANAGER_H
