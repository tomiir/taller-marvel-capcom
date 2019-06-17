//
// Created by magali on 02/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_LIFEMANAGER_H
#define TALLER_MARVEL_CAPCOM_LIFEMANAGER_H


#include "SDL2/SDL.h"
#include "../../model/GameObjects_fight/GameObject/GameObject.h"
#include <vector>
#include <map>
#include "../../controllers/Controller/Renderable.h"

class LifeManager: public Renderable {
private:

    bool isRight;
    double life;
    double lifeSecond;


    // estos se settearan cuando se seleccionen, así podemos hacer
    // barras de vida personalizadas
    std::map<string, GameObject* > lifeFrames;
    map<string, GameObject*>::iterator lifeFrames_iter = lifeFrames.begin();

    // barras de vida secundarias
    std::map<string, GameObject*> lifeFramesSecond;
    map<string, GameObject*>::iterator lifeFramesSecond_iter;

    GameObject* firstCharacter;
    GameObject* secondCharacter;

    vector <int> currentColor;
    vector <int> secondColor;
    vector <int> red;
    vector <int> green;
    vector <int> yellow;

    SDL_Renderer* renderer;
    int z;
    int x;
    int y;
    int w;
    int h;
    int z_second;
    int x_second;
    int y_second;
    int h_second;
    int w_second;

public:
    LifeManager(SDL_Renderer* renderer,int z,vector <int> first, vector <int> second);
    ~LifeManager() = default;
    void render() override ;
    void updateLife(double newLife);
    void updateCurrentCharacter(string current);
    void addCharacters(vector <GameObject*> characters);
    int getZIndex() override;
    void addCharactersSecond(vector<GameObject *> charactersSecond);
    void setFirstCharacter(string name);
    void setSecondCharacter(string name);
    void setAsRight();

};


#endif //TALLER_MARVEL_CAPCOM_LIFEMANAGER_H
