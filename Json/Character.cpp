//
// Created by fede on 07/04/19.
//

#include "Character.h"

Character::Character(std::string name, std::string filepath, int height, int width, int zindex) {
    this->name = name;
    this->filepath = filepath;
    this-> height = height;
    this->width = width;
    this->zindex = zindex;
}

std::string Character::getName() {
    return this->name;
}

std::string Character::getFilePath() {
    return this->filepath;
}

int Character::getHeight() {
    return this->height;
}

int Character::getWidth() {
    return this->width;
}

int Character::getzIndex() {
    return this->zindex;
}
