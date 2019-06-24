//
// Created by trocchi on 6/9/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIAUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_CHUNLIAUDIOMANAGER_H


#include "../AudioManager.h"

class ChunLiAudioManager : public AudioManager {
public:
    ~ChunLiAudioManager() = default;
    ChunLiAudioManager();
    void init() override;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIAUDIOMANAGER_H
