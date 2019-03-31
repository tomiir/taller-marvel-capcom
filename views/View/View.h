//
// Created by trocchi on 3/31/19.
//

#include "../../model/GameObjects/GameObject/GameObject.h"
#include <vector>
#ifndef TALLER_MARVEL_CAPCOM_VIEW_H
#define TALLER_MARVEL_CAPCOM_VIEW_H


class View {
public:
    View(char* viewId, SDL_Renderer* renderer); //Esto es para uqe pueda levantar del JSON, despues nosotros definimos constantes con los id
    ~View();
    void render();
    void handleEvent(SDL_Event event);
private:
    std::vector<GameObject*> objects;
    int objectCount;
    SDL_Renderer* renderer;
    std::vector<int> mapEventToValue(SDL_Event event, std::vector<int> &dir);
};


#endif //TALLER_MARVEL_CAPCOM_VIEW_H
