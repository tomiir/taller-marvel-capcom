//
// Created by fer on 26/03/19.
//

#include "GameObject.h"


using namespace std;

GameObject::GameObject(const char* folderPath, SDL_Renderer *rend, int initialX, int initialY, int width, int heigh) {
    renderer = rend;
    objRect = SDL_Rect();
    objTexture = TextureManager::LoadTexture(folderPath, renderer);

    objRect.x = initialX;
    objRect.y = initialY;
    objRect.w = width;
    objRect.h = heigh;

    posX = objRect.x;
    posY = objRect.y;
    this->width = objRect.w;
    this->heigh = objRect.h;
}

GameObject::~GameObject() = default;

void GameObject::move(std::vector<int> &increase){};


void GameObject::render(){

    SDL_RenderCopy(renderer, objTexture, nullptr, &objRect);

}