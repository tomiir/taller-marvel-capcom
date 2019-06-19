//
// Created by trocchi on 6/8/19.
//

#include "SpiderManAudioManager.h"

void SpiderManAudioManager::init() {
    Audio* jumpAudio = new Audio("../Audio/Spider-man/Jump.wav");
    Audio* punchAudio =  new Audio("../Audio/Spider-man/punch.wav");
    Audio* dmgAudio =  new Audio("../Audio/Spider-man/dmg.wav");

    audios["jump"] = jumpAudio;

    audios["airKicked"] = dmgAudio;
    audios["standKicked"] = dmgAudio;
    audios["downKicked"] = dmgAudio;

    audios["weakStandPunch"] = punchAudio;
    audios["weakStandKick"] = punchAudio;
    audios["weakAirPunch"] = punchAudio;
    audios["weakAirKick"] = punchAudio;
    audios["weakDownPunch"] = punchAudio;
    audios["weakDownKick"] = punchAudio;
    audios["strongStandPunch"] = punchAudio;
    audios["strongStandKick"] = punchAudio;
    audios["strongAirPunch"] = punchAudio;
    audios["strongAirKick"] = punchAudio;
    audios["strongDownPunch"] = punchAudio;
    audios["strongDownKick"] = punchAudio;
}

SpiderManAudioManager::SpiderManAudioManager() {
    init();
}