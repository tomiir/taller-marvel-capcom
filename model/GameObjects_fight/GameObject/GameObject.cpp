//
// Created by fer on 26/03/19.
//

#include "GameObject.h"


GameObject::GameObject(const char* folderPath, string name_, int z_index, SDL_Renderer *rend, int initialX, int initialY, int width, int height): Renderable() {

    name = name_;
    renderer = rend;
    objRect = SDL_Rect{0, 0, width, height};
    objRect2 = SDL_Rect{initialX, initialY, width, height};
    objTexture = TextureManager::LoadTexture(folderPath, renderer);
    this->z_index = z_index;
}

GameObject::~GameObject() = default;
int GameObject::getZIndex() {
    return z_index;
}

void GameObject::move(DirectionVector* direction){}

vector<int> GameObject::getInfo() {}

void GameObject::render() {
    int error = SDL_RenderCopy(renderer, objTexture, &objRect, &objRect2);
    if( error < 0){
        cout << "error: " << SDL_GetError() << endl;
    }
}

void GameObject::stayInFloor() {}


string GameObject::getName() {
    return name;
}

void GameObject::setOriginRect(vector<int> position) {
    objRect = SDL_Rect{position[0], position[1], position[2], position[3]};
}

void GameObject::setDestinyRect(vector<int> position) {
    objRect2 =SDL_Rect{position[0], position[1], position[2], position[3]};
}
