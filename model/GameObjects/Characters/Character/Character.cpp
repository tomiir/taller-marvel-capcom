//
// Created by fer on 26/03/19.
//

#include "Character.h"

using namespace std;

Character::Character(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh) :
           GameObject(imagePath, rend, initialX, initialY, width, heigh) {
    this->jumpHeight=-20;
    this->speed=20;
}

Character::~Character() = default;

void Character::move(std::vector<int>  &increase)
{
    cout << increase[0] << increase[1]<< endl;
    cout << increase[0]*this->speed << increase[1]*this->jumpHeight<< endl;
    int x = increase[0];
    int y = increase[1];

    objRect.x += x*this->speed;
    objRect.y += y*this->jumpHeight;
}
