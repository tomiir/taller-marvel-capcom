//
// Created by trocchi on 6/8/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAAUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAAUDIOMANAGER_H

#include "../AudioManager.h"


class CaptainAmericaAudioManager : public AudioManager {
public:
    CaptainAmericaAudioManager();
    ~CaptainAmericaAudioManager() = default;

    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAAUDIOMANAGER_H
