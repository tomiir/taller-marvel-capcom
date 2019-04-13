//
// Created by fede on 07/04/19.
//

#include "Battlefield.h"

Battlefield::Battlefield(std::string ruta, int zindex) {
    this->ruta = ruta;
    this->zindex = zindex;
}

std::string Battlefield::getRuta() {
    return this->ruta;
}

int Battlefield::getzIndex() {
    return this->zindex;
}
