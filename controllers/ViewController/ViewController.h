//
// Created by trocchi on 3/31/19.
//
#include "../../views/View/View.h"
#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H


class ViewController {
public:
    ViewController(char* viewId, SDL_Renderer* renderer);
    ~ViewController();
    void updateView();
    void handleEvent();
private:
    View* view;
};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
