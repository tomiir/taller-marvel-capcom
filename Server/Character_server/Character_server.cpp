//
// Created by arielpm on 16/05/19.
//

#include "Character_server.h"

Character_server::Character_server(int initialY, std::string name) :
        GameObject_server(name, 0, initialY, 0, 0) {

    this->initialY = initialY;
    logger->Log("Creando personaje: " + name, DEBUG, "");
    this->state = "still";

}

Character_server::~Character_server() = default;

void Character_server::move(DirectionVector* direction){
    objRect.x += (int) direction->x;
    objRect.y += (int) direction->y;
}

vector<int> Character_server::getInfo() {

    vector<int> info = {objRect.x, objRect.y, objRect.w, objRect.h};
    return info;
}

void Character_server::setState(string state) {

    this->state = state;

}

void Character_server::stayInFloor() {

    objRect.y = initialY;
}


void Character_server::changePosition(int changeX, int changeY) {

    objRect.x = changeX;
    objRect.y = changeY;

}

void Character_server::setInitialXPositions(int positionLeft, int positionRight){
    posInitialLeft = positionLeft;
    posInitialRight = positionRight;
}

void Character_server::setInitialPos(bool left){

    objRect.x = left ? posInitialLeft : posInitialRight;
}

void Character_server::flipSprite(SDL_RendererFlip flip_) {

    flip = flip_;
}
