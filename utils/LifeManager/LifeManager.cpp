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
    lifeSecond = 1;
    currentColor = green;
    secondColor = yellow;
    isRight = false;
    this->renderer = renderer;
    this->z = z;
    this->x = first[0];
    this->y = first[1];
    this->w = first[2];
    this->h = first[3];

    this->z_second = z;
    this->x_second = second[0];
    this->y_second = second[1];
    this->w_second = second[2];
    this->h_second = second[3];
}

void LifeManager::render() {

    SDL_SetRenderDrawColor(renderer, currentColor[0], currentColor[1], currentColor[2], 255);

    SDL_Rect rectangle;

    double delta;
    if (isRight){
        delta = w*(1-life);
        rectangle.x = x + delta;
    }
    else{
        rectangle.x = x;
    }

    rectangle.w = w * life;
    rectangle.y = y;
    rectangle.h = h;

    SDL_RenderFillRect(renderer, &rectangle);
    firstCharacter->render();


    SDL_SetRenderDrawColor(renderer, secondColor[0], secondColor[1], secondColor[2], 255);

    SDL_Rect rectangle_second;
    if (isRight){
        delta = w_second * ( 1 - lifeSecond);
        rectangle_second.x = x_second + delta;
    }
    else{
        rectangle_second.x = x_second;
    }

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
    if (strcmp(current.c_str(), (firstCharacter->getName()).c_str()) == 0) return;
    //el actual (first) va a ser el secundario
    lifeFramesSecond_iter = lifeFramesSecond.find(firstCharacter->getName());
    secondCharacter = lifeFramesSecond_iter->second;
    //el que reciba sera el actual
    lifeFrames_iter = lifeFrames.find(current);
    firstCharacter = lifeFrames_iter->second;
    double aux  = life;
    life = lifeSecond;
    lifeSecond = aux;
    vector<int> aux_color = currentColor;
    currentColor = secondColor;
    secondColor = aux_color;

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

void LifeManager::setAsRight() {
    isRight = true;

    //double delta = w * (1 - life);
    //x = x + delta;
    //double deltaSecond = w_second * (1 - lifeSecond);
    //x_second = x_second + deltaSecond;
}
