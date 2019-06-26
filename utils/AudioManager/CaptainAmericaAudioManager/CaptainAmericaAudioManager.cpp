//
// Created by trocchi on 6/8/19.
//

#include "CaptainAmericaAudioManager.h"

void CaptainAmericaAudioManager::init() {
    Audio* punchAudio =  new Audio("../Audio/CaptainAmerica/punch.wav");
    Audio* dmgAudio =  new Audio("../Audio/CaptainAmerica/dmg.wav");
    Audio* fallAudio = new Audio("../Audio/CaptainAmerica/fall.wav"); //--> cuando pasa de jump a still o walk
    Audio* throwAudio = new Audio("../Audio/CaptainAmerica/throw.wav");
//    Audio* grabbedImpactAudio = new Audio("../Audio/Common/grabbedImpact.wav");  //grabbedImpact hacerlo corto

    audios["grabbedImpact"] = fallAudio;
    audios["fall"] = fallAudio;
    audios["throw"] = throwAudio;


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