//
// Created by magali on 02/06/19.
//

#include "LifeManager.h"

LifeManager::LifeManager(SDL_Renderer* renderer, int z,vector <int> first, vector <int> second):Renderable() {

    green = {0x00, 0xFF, 0x00};
    red = {0xFF, 0x00, 0x00};
    yellow  =  {0xFF, 0xFF, 0x00};

    life = 1; // este es un porcentaje
    // les pongo estos valores al segundo personaje para probar, en realidad empieza con verde y 1.
    lifeSecond = 20;

    secondColor = red;

    this->renderer = renderer;
    this->z = z;
    this->x = first[0];
    this->y = first[1];
    this->h = first[2];
    this->w = first[3];

    this->z_second = z;
    this->x_second = second[0];
    this->y_second = second[1];
    this->h_second = second[2];
    this->w_second = second[3];
}

void LifeManager::render() {

    SDL_SetRenderDrawColor(renderer, currentColor[0], currentColor[1], currentColor[2], 255);

    SDL_Rect rectangle;

    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w * life;
    rectangle.h = h;

    SDL_RenderFillRect(renderer, &rectangle);
    firstCharacter->render(); // renderizo el marco y luego la barra de vida


    SDL_SetRenderDrawColor(renderer, secondColor[0], secondColor[1], secondColor[2], 255);

    SDL_Rect rectangle_second;

    rectangle_second.x = x_second;
    rectangle_second.y = y_second;
    rectangle_second.w = w_second * lifeSecond;
    rectangle_second.h = h_second;

    SDL_RenderFillRect(renderer, &rectangle_second);
    secondCharacter->render();

}

void LifeManager::updateLife(int newLife) {
    if (newLife > 0.60) currentColor = green;
    else if(newLife > 0.40) currentColor = yellow;
    else currentColor = red;
    life = newLife;

}

// siempre se debe cambiar el personajes primero, antes que la vida.
void LifeManager::updateCurrentCharacter(string current) {
    if (strcmp(current.c_str(), (firstCharacter->getName()).c_str()) != 0){
        lifeFramesSecond_iter = lifeFramesSecond.find(firstCharacter->getName());
        secondCharacter = lifeFramesSecond_iter->second;
        lifeSecond = life;
    }
    lifeFrames_iter = lifeFrames.find(current);
    firstCharacter = lifeFrames_iter->second;
}

void LifeManager::addCharacters(vector<GameObject *> characters) {

    for(auto character : characters) lifeFrames[character->getName()] = character;

}

void LifeManager::addCharactersSecond(vector<GameObject*> charactersSecond){

    for(auto characterSecond : charactersSecond) lifeFramesSecond[characterSecond->getName()] = characterSecond;

}

int LifeManager::getZIndex() {
    return z;
}

void LifeManager::setFirstCharacter(string name) {
    lifeFrames_iter = lifeFrames.find(name);
    firstCharacter = lifeFrames_iter->second;
}

void LifeManager::setSecondCharacter(string name) {
    lifeFramesSecond_iter = lifeFramesSecond.find(name);
    secondCharacter = lifeFramesSecond_iter->second;
}
