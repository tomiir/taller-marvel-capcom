//
// Created by trocchi on 6/7/19.
//

#ifndef TALLER_MARVEL_CAPCOM_AUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_AUDIOMANAGER_H


#include "Audio.h"
#include <vector>
#include <string>

class AudioManager_Fight {
public:
    ~AudioManager_Fight();
    AudioManager_Fight(const char* punch_, const char* jump_, const char* dmg_);

    void setState(std::string state);
private:
    Audio punch;
    Audio jump;
    Audio dmg;
    std::string state;

};


#endif //TALLER_MARVEL_CAPCOM_AUDIOMANAGER_H
