//
// Created by magali on 18/05/19.
//

#include "JsonGameObject_charSelect.h"

JsonGameObject_charSelect::JsonGameObject_charSelect(std::string path, std::vector<int> posc, std::string name) {
    this->path = path;
    this->posc = posc;
    this->name = name;
    this->error = false;
}

std::string JsonGameObject_charSelect::getFilePath() {
    return path;
}

std::string JsonGameObject_charSelect::getName() {
    return name;
}

std::vector<int> JsonGameObject_charSelect::getPosc() {
    return posc;
}

JsonGameObject_charSelect::JsonGameObject_charSelect(std::list<std::string> errors) {
    this->error = true;
    this->errorsList = errors;

}
std::list<std::string> JsonGameObject_charSelect:: getErrorList(){
    return this->errorsList;
}

bool JsonGameObject_charSelect::getError(){
    return error;
}