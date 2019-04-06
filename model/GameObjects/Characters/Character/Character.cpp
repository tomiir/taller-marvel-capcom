//
// Created by fer on 26/03/19.
//

#include "Character.h"


Character::Character(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int height) :
           GameObject(imagePath, rend, initialX, initialY, width, height) {}

Character::~Character() = default;

void Character::move(DirectionVector* direction){

    objRect.x += (int) direction->x;
    objRect.y += (int) direction->y;
}

void Character::render() {

    SDL_RenderCopy(renderer, objTexture, nullptr, &objRect);
}

vector<int> Character::getInfo() {

    std::vector<int> info = {objRect.x, objRect.y, objRect.w, objRect.h};
    return info;
}