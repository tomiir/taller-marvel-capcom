//
// Created by fer on 26/03/19.
//

#include "GameObject.h"



GameObject::GameObject(const char* folderPath, SDL_Renderer *rend, int initialX, int initialY, int width, int heigh) {

    renderer = rend;
    objRect = SDL_Rect{initialX, initialY, width, heigh};
    objTexture = TextureManager::LoadTexture(folderPath, renderer);

}

GameObject::~GameObject() = default;

void GameObject::move(std::vector<int> &increase){}



vector<int> GameObject::getInfo() {}

void GameObject::render() {}
