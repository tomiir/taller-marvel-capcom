//
// Created by trocchi on 6/9/19.
//

#include "ViewAudioManager.h"
#include <random>
#include <iostream>
#include <alsa/asoundlib.h>

ViewAudioManager::ViewAudioManager() {
    init();
}

void ViewAudioManager::init() {
    string file_id = to_string(rand() % 3 + 1);
    string file = "../Audio/Music/music" + file_id + ".wav";

    audios["fight"] = new Audio(file.c_str());
    audios["char_select"] = new Audio("../Audio/Music/char_select.wav");
    // audios["endgame"] = new Audio("../Audio/Music/endgame.wav");

    this->state = "present";
}

void ViewAudioManager::mute(){
    setVolume(0);
}

void ViewAudioManager::setVolume(int volume) {
        {
            long min, max;
            snd_mixer_t *handle;
            snd_mixer_selem_id_t *sid;
            const char *card = "default";
            const char *selem_name = "Master";

            snd_mixer_open(&handle, 0);
            snd_mixer_attach(handle, card);
            snd_mixer_selem_register(handle, NULL, NULL);
            snd_mixer_load(handle);

            snd_mixer_selem_id_alloca(&sid);
            snd_mixer_selem_id_set_index(sid, 0);
            snd_mixer_selem_id_set_name(sid, selem_name);
            snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

            snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
            snd_mixer_selem_set_playback_volume_all(elem, volume * max / 100);

            snd_mixer_close(handle);
        }
};