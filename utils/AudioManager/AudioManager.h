//
// Created by trocchi on 6/7/19.
//

#ifndef TALLER_MARVEL_CAPCOM_AUDIOMANAGER_H
#define TALLER_MARVEL_CAPCOM_AUDIOMANAGER_H


#include "Audio.h"
#include <map>
#include <string>

using namespace std;

class AudioManager {
public:
    ~AudioManager();
    AudioManager();

    virtual void init();
    virtual void playAudio(string name);
    void setState(std::string state);
protected:
    map<string,Audio*> audios;
    std::string state;

};

#endif //TALLER_MARVEL_CAPCOM_AUDIOMANAGER_H
