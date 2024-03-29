//
// Created by fede on 07/04/19.
//

#include "JsonCharacter.h"

JsonCharacter::JsonCharacter(std::list<std::string> errors){
    this->error = true;
    this->errorsList = errors;

}

JsonCharacter::JsonCharacter(std::string name, std::string filepath, std::string lifebarPath, int zindexlifebar, int height, int width, int zindex, std::string spriteManager, double size, int wSprite, int hSprite) {

    this->name = name;
    this->filepath = filepath;
    this-> height = height;
    this->width = width;
    this->zindex = zindex;
    this->zindexlifebar = zindexlifebar;
    this->spriteManager = spriteManager;
    this->size = size;
    this->error = false;
    this->wSprite = wSprite;
    this->hSprite = hSprite;
    this->lifebarpath = lifebarPath;
}

std::string JsonCharacter::getName() {
    return this->name;
}

std::list<std::string> JsonCharacter::getErrorList(){
    return this->errorsList;
}

std::string JsonCharacter::getFilePath() {
    return this->filepath;
}

std::string JsonCharacter::getLifebarpath(){
    return this->lifebarpath;
}

int JsonCharacter::getzIndexLifebar() {
    return this->zindexlifebar;
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

std::string JsonCharacter::getSpriteManager(){
    return spriteManager;
}

double JsonCharacter::getSize() {
    return  size;
}

bool JsonCharacter::getError(){
    return error;
}

int JsonCharacter::getWSprite(){
    return wSprite;
}

int JsonCharacter::getHSprite(){
    return hSprite;
}

