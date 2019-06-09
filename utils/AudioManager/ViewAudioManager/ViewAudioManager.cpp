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
    cout << file << endl;
    audios["fight"] = new Audio(file.c_str());
//    audios["char_select"] = new Audio(CHAR_SELECT_FILE);
    this->state = "char_select";
}

