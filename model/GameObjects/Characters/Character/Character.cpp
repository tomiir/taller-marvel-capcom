//
// Created by fer on 26/03/19.
//

#include "Character.h"


Character::Character(const char* imagePath, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialX, int initialY, int width, int height) :
           GameObject(imagePath, rend, initialX, initialY, width, height) {
    flip_status = SDL_FLIP_NONE;
    flip_angle = 0;
    spriteManager = spriteManager_;
    sprite = spriteManager->getSprite();
}

Character::~Character() = default;

void Character::move(DirectionVector* direction){

    objRect.x += (int) direction->x;
    objRect.y += (int) direction->y;
}

void Character::render() {

    sprite = spriteManager->getSprite();
    objRect.w = (int) (sprite.w * 2.5);
    objRect.h = (int) (sprite.h * 2.5);
    SDL_RenderCopy(renderer, objTexture, &sprite, &objRect);
    //flip_status = SDL_FLIP_NONE;
    //flip_angle = 0;
}

vector<int> Character::getInfo() {

    vector<int> info = {objRect.x, objRect.y, objRect.w, objRect.h};
    return info;
}

void Character::setState(string state) {

    spriteManager->setState(state);

}

void Character:: flipRight(){
    flip_status = SDL_FLIP_VERTICAL;
    flip_angle = 180;
    SDL_RenderCopyEx(renderer, objTexture, &sprite, &objRect, flip_angle, nullptr, flip_status);
}

void Character:: flipLeft(){
    flip_status = SDL_FLIP_VERTICAL;
    flip_angle = 180;
    SDL_RenderCopyEx(renderer, objTexture, &sprite, &objRect, flip_angle, nullptr, flip_status);
}