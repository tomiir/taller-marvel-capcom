//
// Created by trocchi on 6/7/19.
//

#include "AudioManager_Fight.h"
#include <string>

using namespace std;

AudioManager_Fight::AudioManager_Fight(const char* punch_, const char* jump_, const char* dmg_) {
    punch.load(punch_);
    jump.load(jump_);
    dmg.load(dmg_);
}

void AudioManager_Fight::setState(std::string state) {
    this->state = state;

}
