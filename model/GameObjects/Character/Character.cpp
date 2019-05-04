//
// Created by fer on 26/03/19.
//

#include "Character.h"
#include <string.h>


Character::Character(const char* imagePath,string name_,int z_index, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialX, int initialY, int crowchedDownY_, std::string name, double size) :
           GameObject(imagePath, name_, z_index, rend, initialX, initialY, 0, 0) {

    spriteManager = spriteManager_;
    this->initialY = initialY;
    crowchedDownY = crowchedDownY_;
    logger->Log("Creando personaje: " + name, DEBUG, "");
    this->size = size;

}

Character::~Character() = default;

void Character::move(DirectionVector* direction){
    logger -> Log("Moviendo a " + name + "X: "+ to_string(direction->x) +"Y: "+ to_string(direction->y), DEBUG, "");
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

void Character::crowchDown() {

    objRect.y = crowchedDownY;
}

void Character::changePosition(int changeX, int changeY) {

    objRect.x = changeX;
    objRect.y = changeY;

}

