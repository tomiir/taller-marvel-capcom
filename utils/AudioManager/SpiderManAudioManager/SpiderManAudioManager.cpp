//
// Created by trocchi on 6/8/19.
//

#include "SpiderManAudioManager.h"

void SpiderManAudioManager::init() {

    Audio* punchAudio =  new Audio("../Audio/Spider-man/punch.wav");
    Audio* dmgAudio =  new Audio("../Audio/Spider-man/dmg.wav");
    Audio* fallAudio = new Audio("../Audio/Spider-man/fall.wav"); //--> cuando pasa de jump a still o walk
    Audio* grabbedImpactAudio = new Audio("../Audio/Spider-man/grabbedImpact.wav");  //grabbedImpact hacerlo corto
    Audio* throwAudio = new Audio("../Audio/Spider-man/throw.wav");

    audios["grabbedImpact"] = grabbedImpactAudio;
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

SpiderManAudioManager::SpiderManAudioManager() {
    init();
}