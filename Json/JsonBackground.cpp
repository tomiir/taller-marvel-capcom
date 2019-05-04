//
// Created by fede on 07/04/19.
//

#include "JsonBackground.h"

JsonBackground::JsonBackground(std::list<std::string> errors){
    this->error = true;
    this->errorsList = errors;
}

JsonBackground::JsonBackground(std::string name, std::string path, int zindex,  int width, int height) {

    this->name = name;
    this->path = path;
    this->zindex = zindex;
    this->width = width;
    this->height = height;
    this->error = false;
}

std::string JsonBackground::getFilePath() {
    return this->path;
}

int JsonBackground::getzIndex() {
    return this->zindex;
}

int JsonBackground::getHeight() {
    return this->height;
}

int JsonBackground::getWidth() {
    return this->width;
}

bool JsonBackground::getError() {
    return this->error;
}

std::list<std::string> JsonBackground::getErrorList(){
    return this->errorsList;
}

std::string JsonBackground::getName() {
    return this->name;
}
