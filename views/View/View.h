//
// Created by trocchi on 3/31/19.
//
#ifndef TALLER_MARVEL_CAPCOM_VIEW_H
#define TALLER_MARVEL_CAPCOM_VIEW_H
#include <iostream>
#include "../../model/GameObjects/GameObject/GameObject.h"
#include <vector>
#include "../../utils/EventToValueMapper/EventToValueMapper_player/EventToValueMapper.h"


class View {
public:
    View(SDL_Renderer* renderer); //Saco el id que es para el jason, pq no se si debería estar en ViewController_fight!
    ~View();
    void render();
    void handleEvent(SDL_Event event);
private:
    SDL_Renderer* renderer;

};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
