//
// Created by magali on 02/06/19.
//

#include "LifeManager.h"

LifeManager::LifeManager(SDL_Renderer* renderer, int z,vector <int> first, vector <int> second):Renderable() {
    life = 1; // este es un porcentaje
    green = {0x00, 0xFF, 0x00};
    red = {0xFF, 0x00, 0x00};
    yellow  =  {0xFF, 0xFF, 0x00};
    lifeSecond = 20;

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

    firstCharacter->render(); // renderizo el marco y luego la barra de vida
    secondCharacter->render();
    SDL_RenderFillRect(renderer, &rectangle);




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
//    lifeFrames[characters[0]->getName()] = characters[0];
//    lifeFrames[characters[1]->getName()] = characters[1];
//    lifeFrames[characters[2]->getName()] = characters[2];
//    lifeFrames[characters[3]->getName()] = characters[3];

}

void LifeManager::addCharactersSecond(vector<GameObject*> charactersSecond){

    for(auto characterSecond : charactersSecond) lifeFramesSecond[characterSecond->getName()] = characterSecond;
//    lifeFramesSecond[charactersSecond[0]->getName()] = charactersSecond[0];
//    lifeFramesSecond[charactersSecond[1]->getName()] = charactersSecond[1];
//    lifeFramesSecond[charactersSecond[2]->getName()] = charactersSecond[2];
//    lifeFramesSecond[charactersSecond[3]->getName()] = charactersSecond[3];


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
