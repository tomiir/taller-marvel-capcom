//
// Created by trocchi on 6/9/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMAUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_VENOMAUDIOMANAGER_H

#include "../AudioManager.h"

class VenomAudioManager : public AudioManager {
public:
    ~VenomAudioManager() = default;
    VenomAudioManager();

    void init() override;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMAUDIOMANAGER_H
