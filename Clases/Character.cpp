//
// Created by fer on 26/03/19.
//

#include "Character.h"
#include "TextureManager.h"

int JUMP = 50;
int DOWN = 50;

Character::Character(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh) :
           GameObject(imagePath, rend, initialX, initialY, width, heigh) {}

Character::~Character() = default;

void Character::jump(){

    objRect.y -= JUMP;
}

void Character::down(){

    objRect.y += DOWN;
}