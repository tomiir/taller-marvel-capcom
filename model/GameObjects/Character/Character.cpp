//
// Created by fer on 26/03/19.
//

#include "Character.h"
#include <string.h>


Character::Character(const char* imagePath,string name_,int z_index, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialY, std::string name, double size) :
           GameObject(imagePath, name_, z_index, rend, 0, initialY, 0, 0) {

    spriteManager = spriteManager_;
    this->initialY = initialY;
    logger->Log("Creando personaje: " + name, DEBUG, "");
    this->size = size;

}

Character::~Character() = default;

void Character::move(DirectionVector* direction){
    objRect.x += (int) direction->x;
    objRect.y += (int) direction->y;
}

void Character::render() {

    SDL_Rect sprite = spriteManager->getSprite();
    objRect.w = (int) (sprite.w * size);
    objRect.h = (int) (sprite.h * size);
    SDL_RenderCopyEx(renderer, objTexture, &sprite, &objRect, 0.0, nullptr, flip);
}

vector<int> Character::getInfo() {

    vector<int> info = {objRect.x, objRect.y, objRect.w, objRect.h};
    return info;
}

void Character::setState(string state) {

    spriteManager->setState(state);

}

void Character::flipSprite(SDL_RendererFlip flip_) {

    flip = flip_;
}

void Character::stayInFloor() {

    objRect.y = initialY;
}


void Character::changePosition(int changeX, int changeY) {

    objRect.x = changeX;
    objRect.y = changeY;

}

void Character::setInitialXPositions(int positionLeft, int positionRight){
    posInitialLeft = positionLeft;
    posInitialRight = positionRight;
}

void Character::setInitialPos(bool left){

    objRect.x = left ? posInitialLeft : posInitialRight;
}
