//
// Created by trocchi on 6/8/19.
//

#include "CaptainAmericaAudioManager.h"

void CaptainAmericaAudioManager::init() {
    Audio* jumpAudio = new Audio("../Audio/CaptainAmerica/Jump.wav");
    Audio* punchAudio =  new Audio("../Audio/CaptainAmerica/punch.wav");
    Audio* dmgAudio =  new Audio("../Audio/CaptainAmerica/dmg.wav");

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

CaptainAmericaAudioManager::CaptainAmericaAudioManager() {
    init();
}