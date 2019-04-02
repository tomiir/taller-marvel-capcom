//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLERFACTORY_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLERFACTORY_H

#include "../GameObjectControllerFactory/GameObjectControllerFactory.h"
#include "../../../controllers/ViewController/ViewController.h"
#include "../../../views/View/View.h"

class ViewControllerFactory{

    SDL_Renderer * renderer;

public:
    ViewControllerFactory(SDL_Renderer * renderer_);
    ~ViewControllerFactory();
    ViewController * getViewController_fight();

};


#endif //TALLER_MARVEL_CAPCOM_VIEWFACTORY_H
