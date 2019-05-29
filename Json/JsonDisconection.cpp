//
// Created by magali on 22/05/19.
//

#include "JsonDisconection.h"

JsonDisconection::JsonDisconection(std::list<std::string> errors) {
    this->errorsList = errors;
}

JsonDisconection::JsonDisconection(std::string name, std::string path, int x, int y, int width, int height, int z_index) {
    this->name = name;
    this->path = path;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->z_index = z_index;
    this->error = false;
}

std::string JsonDisconection::getName() {
    return name;
}

std::string JsonDisconection::getPath() {
    return path;
}

int JsonDisconection::getX() {
    return x;
}

int JsonDisconection::getY() {
    return y;
}

int JsonDisconection::getHeight() {
    return height;
}

int JsonDisconection::getWidth() {
    return width ;
}

int JsonDisconection::getZ_index(){
    return z_index;
}

bool JsonDisconection::getError() {
    return error;
}

std::list<std::string> JsonDisconection::getErrorList() {
    return errorsList;
}
