//
// Created by trocchi on 6/8/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANAUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANAUDIOMANAGER_H

#include "../AudioManager.h"

class SpiderManAudioManager : public AudioManager {
public:
    SpiderManAudioManager();
    ~SpiderManAudioManager() = default;

    void init() override ;
};

#endif //TALLER_MARVEL_CAPCOM_SPIDERMANAUDIOMANAGER_H
