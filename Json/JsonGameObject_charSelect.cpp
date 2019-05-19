//
// Created by magali on 18/05/19.
//

#include "JsonGameObject_charSelect.h"

JsonGameObject_charSelect::JsonGameObject_charSelect(const char *path, std::vector<int> posc, std::string name) {
    this->path = path;
    this->posc = posc;
    this->name = name;
}

const char *JsonGameObject_charSelect::getFilePath() {
    return path;
}

std::string JsonGameObject_charSelect::getName() {
    return name;
}

std::vector<int> JsonGameObject_charSelect::getPosc() {
    return posc;
}
