//
// Created by fede on 07/04/19.
//

#include "Battlefield.h"

Battlefield::Battlefield(){
    this->ruta = "";
    this->height = -1;
    this ->width = -1;
    this ->zindex = -999;
    this -> error = true;
}

Battlefield::Battlefield(std::string ruta, int zindex,  int width, int height) {

    this->ruta = ruta;
    this->zindex = zindex;
    this->width = width;
    this->height = height;
    this->error = false;
}

std::string Battlefield::getFilePath() {
    return this->ruta;
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