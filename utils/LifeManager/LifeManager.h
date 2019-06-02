//
// Created by magali on 02/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_LIFEMANAGER_H
#define TALLER_MARVEL_CAPCOM_LIFEMANAGER_H


#include "SDL2/SDL.h"
#include "../../model/GameObjects_fight/GameObject/GameObject.h"
#include <vector>
#include <map>

class LifeManager {
private:
    //SDL_Renderer* renderer;
    int life;

    // estos se settearan cuando se seleccionen, así podemos hacer
    // barras de vida personalizadas
    std::map<string, GameObject* > lifeFrames;
    map<string, GameObject*>::iterator lifeFrames_iter = lifeFrames.begin();
    GameObject* currentCharacter;

    vector <int> currentColor;
    vector <int> red;
    vector <int> green;
    vector <int> yellow;
    int x;
    int y;
    int w;
    int h;


public:
    LifeManager(int x, int y, int w, int h);
    ~LifeManager() = default;
    void render(SDL_Renderer* renderer);
    void updateLive(int newLife);
    void updateCurrentCharacter(string current);
    void addCharacters(vector <GameObject*> characters);

};


#endif //TALLER_MARVEL_CAPCOM_LIFEMANAGER_H
