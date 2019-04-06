//
// Created by trocchi on 3/31/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H

#include "../../views/View/View.h"
#include "../Controller/Controller.h"
#include <list>



class ViewController {

public:
    ViewController(SDL_Renderer* renderer_);
    ~ViewController();
    void updateView();
    void handleEvent();
    void addController(Controller* controller);

private:
    View* view;
    SDL_Renderer* renderer;
    std::list<Controller*> controllers;
};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
