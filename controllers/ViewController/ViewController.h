//
// Created by trocchi on 3/31/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H

#include "../../views/View/View.h"
#include "../Controller/Controller.h"
#include "../BackgroundsController/BackgroundsController.h"
#include <list>

using namespace std;

class ViewController {

public:
    ViewController(SDL_Renderer* renderer_);
    ~ViewController();
    void updateView();
    void handleEvent();
    void addControllerCharacter(ControllerCharacter *controllerCharacter);
    BackgroundsController* addBackgroundsController(BackgroundsController* backgroundsController);

private:
    View* view;
    SDL_Renderer* renderer;
    list<ControllerCharacter*> controllersCharacter;
    list<ControllerCharacter*>::iterator itr = controllersCharacter.begin();

};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
