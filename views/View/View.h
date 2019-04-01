//
// Created by trocchi on 3/31/19.
//

#include "../../model/GameObjects/GameObject/GameObject.h"
#include <vector>
#include "../../utils/EventToValueMapper/EventToValueMapper.h"
#ifndef TALLER_MARVEL_CAPCOM_VIEW_H
#define TALLER_MARVEL_CAPCOM_VIEW_H


class View {
public:
    View(SDL_Renderer* renderer); //Saco el id que es para el jason, pq no se si debería estar en ViewController!
    ~View();
    void render();
    void handleEvent(SDL_Event event);
private:
    SDL_Renderer* renderer;

};


#endif //TALLER_MARVEL_CAPCOM_VIEW_H
