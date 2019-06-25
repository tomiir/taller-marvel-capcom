//
// Created by trocchi on 6/9/19.
//

#include "ViewAudioManager.h"
#include <random>
#include <iostream>

ViewAudioManager::ViewAudioManager() {
    init();
}

void ViewAudioManager::init() {
    string file_id = to_string(rand() % 3 + 1);
    string file = "../Audio/Music/music" + file_id + ".wav";
    Mix_Init(0);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 2048) < 0){
        cout << Mix_GetError() << endl;
    };
    Mix_AllocateChannels(5);
//    sfx["move_cursor"] = Mix_LoadWAV(MOVE_CURSOR_FILE);
//    sfx["select"] = Mix_LoadWAV(SELECT_SFX);

    Mix_Music* fight_music = Mix_LoadMUS(file.c_str());
    if(fight_music == NULL) cout << Mix_GetError() << endl;
    music["fight"] = fight_music;
    Mix_Music* char_select_music = Mix_LoadMUS("../Audio/Music/char_select.mp3");
    if(char_select_music == NULL) cout << Mix_GetError() << endl;
    music["char_select"] = char_select_music;

    this->state = "present";
}

