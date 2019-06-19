//
// Created by trocchi on 6/9/19.
//

#include "ChunLiAudioManager.h"

ChunLiAudioManager::ChunLiAudioManager() {
    init();
}

void ChunLiAudioManager::init() {
    Audio* jumpAudio = new Audio("../Audio/Chun-Li/Jump.wav");
    Audio* punchAudio =  new Audio("../Audio/Chun-Li/punch.wav");
    Audio* dmgAudio =  new Audio("../Audio/Chun-Li/dmg.wav");

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

