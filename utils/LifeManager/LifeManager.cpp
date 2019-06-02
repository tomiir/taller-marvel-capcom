//
// Created by magali on 02/06/19.
//

#include "LifeManager.h"

LifeManager::LifeManager(int x, int y, int w, int h) {
    life = 1; // este es un porcentaje
    green = {0x00, 0xFF, 0x00};
    red = {0xFF, 0x00, 0x00};
    yellow  =  {0xFF, 0xFF, 0x00};
    this->x = x;
    this->y = y;
    this->h = h;
    this->w = w;
}

void LifeManager::render(SDL_Renderer *renderer) {

    SDL_SetRenderDrawColor(renderer, currentColor[0], currentColor[1], currentColor[2], 255);

    SDL_Rect rectangle;

    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w * life;
    rectangle.h = h;

    currentCharacter->render(); // renderizo el marco y luego la barra de vida
    SDL_RenderFillRect(renderer, &rectangle);


}

void LifeManager::updateLive(int newLife) {
    if (newLife > 0.60) currentColor = green;
    else if(newLife > 0.40) currentColor = yellow;
    else currentColor = red;
    life = newLife;

}

void LifeManager::updateCurrentCharacter(string current) {
    lifeFrames_iter = lifeFrames.find(current);
    currentCharacter = lifeFrames_iter->second;
}

void LifeManager::addCharacters(vector<GameObject *> characters) {

    lifeFrames[characters[0]->getName()] = characters[0];
    lifeFrames[characters[1]->getName()] = characters[1];
    lifeFrames[characters[2]->getName()] = characters[2];
    lifeFrames[characters[3]->getName()] = characters[3];

}
