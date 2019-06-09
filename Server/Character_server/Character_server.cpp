//
// Created by arielpm on 16/05/19.
//

#include "Character_server.h"

Character_server::Character_server(int initialY, std::string name, int width, int height, HitboxManager* hitbox_) :
        GameObject_server(name, 0, initialY, width, height) {

    this->initialY = initialY;
    logger->Log("Creando personaje: " + name, DEBUG, "");
    this->state = "still";
    hitbox = hitbox_;
    this->name = name;

}

Character_server::~Character_server() = default;

void Character_server::move(DirectionVector* direction){
    objRect.x += (int) direction->x;
    objRect.y += (int) direction->y;

    hitbox->move(direction);
}

vector<int> Character_server::getInfo() {

    vector<int> info = {objRect.x, objRect.y, objRect.w, objRect.h};
    return info;
}

void Character_server::setState(string state) {

    this->state = state;

    hitbox->setHitboxes(state, horizontalFlip);  // pongo con estos dos poque por ahora estan estos dos solos
}

void Character_server::stayInFloor() {

    objRect.y = initialY;

    hitbox->stayInFloor(initialY);
}


void Character_server::changePosition(int changeX, int changeY) {

    objRect.x = changeX;
    objRect.y = changeY;

    hitbox->setInitialPos(changeX, changeY);

}

void Character_server::setInitialXPositions(int positionLeft, int positionRight){
    posInitialLeft = positionLeft;
    posInitialRight = positionRight;
}

void Character_server::setInitialPos(bool left){

    objRect.x = left ? posInitialLeft : posInitialRight;

    hitbox->setInitialPos(objRect.x, objRect.y);
}

void Character_server::flipSprite(SDL_RendererFlip flip_) {

    flip = flip_;
    horizontalFlip = flip == SDL_FLIP_HORIZONTAL;
}

vector<int> Character_server::getPosInfo(char side) {

    //side te dice con '0' que esta ala izquierda y '1' que esta a la derecha y depende eso cambia le off set

    int x = objRect.x;
    int y = objRect.y;

    if (name == "CaptainAmerica"){
        y -= 205;
        if (side == '0'){
            x -= 237;
        }else x -= 411;
    }
    if (name == "SpiderMan"){
        y -= 307;
        if (side == '0'){
            x -= 424;
        }else x -= 527;
    }
    if (name == "ChunLi"){
        y -= 240;
        if (side == '0'){
            x -= 423;
        }else x -= 376;
    }
    if (name == "Venom"){
        y -= 180;
        if (side == '0'){
            x -= 575;
        }else x -= 527;
    }


    vector<int> positions = {x, y};

    return positions;
}

string Character_server::getState() {
    return state;
}

SDL_RendererFlip Character_server::getFlip() {
    return flip;
}

vector<SDL_Rect> Character_server::getHitboxInfo() {
    return hitbox->getCurrentHitboxes();
}

bool Character_server::getHorizontalFlip() {
    return horizontalFlip;
}

//void Character_server::correctPunch(bool punching) {
//
//    if (punching){
//
//        if(name == "CaptainAmerica"){
//            objRect.x -= 120;
//        }else if(name == "SpiderMan"){
//            objRect.x -= 100;
//        }else if(name == "ChunLi"){
//            objRect.x -= 110;
//        }else if(name == "Venom"){
//            objRect.x -= 140;
//        }
//    }else{
//        if(name == "CaptainAmerica"){
//            objRect.x += 120;
//        }else if(name == "SpiderMan"){
//            objRect.x += 100;
//        }else if(name == "ChunLi"){
//            objRect.x += 110;
//        }else if(name == "Venom"){
//            objRect.x += 140;
//        }
//    }
//}
