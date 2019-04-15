//
// Created by fede on 07/04/19.
//

#include "JsonCharacter.h"

JsonCharacter::JsonCharacter(std::string name, std::string filepath, int height, int width, int zindex, int crowchedDownY, std::string spriteManager) {
    this->name = name;
    this->filepath = filepath;
    this-> height = height;
    this->width = width;
    this->zindex = zindex;
    this->crowchedDownY = crowchedDownY;
    this->spriteManager = spriteManager;
}

std::string JsonCharacter::getName() {
    return this->name;
}

std::string JsonCharacter::getFilePath() {
    return this->filepath;
}

int JsonCharacter::getHeight() {
    return this->height;
}

int JsonCharacter::getWidth() {
    return this->width;
}

int JsonCharacter::getzIndex() {
    return this->zindex;
}

int JsonCharacter::getCrowchedDownY(){
    return crowchedDownY;
}

std::string JsonCharacter::getSpriteManager(){
    return spriteManager;
}
