//
// Created by fer on 26/03/19.
//

#include "GameObject.h"


GameObject::GameObject(const char* folderPath, int z_index, SDL_Renderer *rend, int initialX, int initialY, int width, int height) {

    renderer = rend;
    objRect = SDL_Rect{initialX, initialY, width, height};
    objTexture = TextureManager::LoadTexture(folderPath, renderer);
    this->z_index = z_index;
}

GameObject::~GameObject() = default;
int GameObject::getZIndex() {
    return z_index;
}

void GameObject::move(DirectionVector* direction){}

vector<int> GameObject::getInfo() {}

void GameObject::render() {}

void GameObject::stayInFloor() {}

void GameObject::crowchDown() {}

bool GameObject::problemWithImage(){

    return !objTexture;
}
