//
// Created by fer on 26/03/19.
//

#include "Character.h"


Character::Character(const char* imagePath, SDL_Renderer* rend, SpriteManager* spriteManager_ , int initialX, int initialY, int width, int height) :
           GameObject(imagePath, rend, initialX, initialY, width, height) {

    spriteManager = spriteManager_;
}

Character::~Character() = default;

void Character::move(DirectionVector* direction){

    objRect.x += (int) direction->x;
    objRect.y += (int) direction->y;
}

void Character::render() {

    SDL_Rect sprite = spriteManager->getSprite();
    objRect.w = (int) (sprite.w * 2.5);
    objRect.h = (int) (sprite.h * 2.5);
    SDL_RenderCopyEx(renderer, objTexture, &sprite, &objRect, 0.0, nullptr, flip);
}

vector<int> Character::getInfo() {

    vector<int> info = {objRect.x, objRect.y, objRect.w, objRect.h};
    return info;
}

void Character::setState(string state) {

    spriteManager->setState(state);

}

void Character::flipSprite() {

    if (flip == SDL_FLIP_NONE) flip = SDL_FLIP_HORIZONTAL;
    else flip = SDL_FLIP_NONE;
}

