//
// Created by trocchi on 3/31/19.
//
#ifndef TALLER_MARVEL_CAPCOM_VIEW_H
#define TALLER_MARVEL_CAPCOM_VIEW_H
#include <iostream>
#include "../../model/GameObjects_fight/GameObject/GameObject.h"
#include <vector>
#include "../../utils/Mapper/Mapper_charSelect/Mapper_charSelect.h"
#include "../../controllers/Controller/ControllerBackground/ControllerBackground.h"


class View {
public:
    View(SDL_Renderer* renderer); //Saco el id que es para el jason, pq no se si debería estar en ViewController_fight!
    virtual ~View();
    void clearWindow();
    virtual void updateView();
    virtual bool end();
    virtual string getNextView();

protected:
    SDL_Renderer* renderer;
    std::vector<Background*> backgrounds;
    std::vector<Character*> characters;
    Background* errorLayer;
};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
