//
// Created by fer on 26/03/19.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *imagePath, SDL_Renderer *rend, int initialX, int initialY, int width, int heigh) {
    renderer = rend;
    objRect = SDL_Rect();
    objTexture = TextureManager::LoadTexture(imagePath, renderer);

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

void GameObject::place(int posX, int posY)
{
    objRect.x = posX;
    objRect.y = posY;
}

void GameObject::move(int increase)
{
    objRect.x += increase;
}


void GameObject::render()
{
    SDL_RenderCopy(renderer, objTexture, nullptr, &objRect);
}