//
// Created by trocchi on 6/9/19.
//

#include "VenomAudioManager.h"

VenomAudioManager::VenomAudioManager() {
    init();
}

void VenomAudioManager::init() {
    Audio* punchAudio =  new Audio("../Audio/Venom/punch.wav");
    Audio* dmgAudio =  new Audio("../Audio/Venom/dmg.wav");
    Audio* fallAudio = new Audio("../Audio/Venom/fall.wav"); //--> cuando pasa de jump a still o walk
    Audio* grabbedImpactAudio = new Audio("../Audio/Venom/grabbedImpact.wav");  //grabbedImpact hacerlo corto
    Audio* throwAudio = new Audio("../Audio/Venom/throw.wav");


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