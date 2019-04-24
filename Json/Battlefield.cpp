//
// Created by fede on 07/04/19.
//

#include "Battlefield.h"

Battlefield::Battlefield(std::list<std::string> errors){
    this->error = true;
    this->errorsList = errors;
}

Battlefield::Battlefield(std::string name, std::string path, int zindex,  int width, int height) {

    this->name = name;
    this->path = path;
    this->zindex = zindex;
    this->width = width;
    this->height = height;
    this->error = false;
}

std::string Battlefield::getFilePath() {
    return this->path;
}

int Battlefield::getzIndex() {
    return this->zindex;
}

int Battlefield::getHeight() {
    return this->height;
}

int Battlefield::getWidth() {
    return this->width;
}

bool Battlefield::getError() {
    return this->error;
}

std::list<std::string> Battlefield::getErrorList(){
    return this->errorsList;
}

std::string Battlefield::getName() {
    return this->name;
}
