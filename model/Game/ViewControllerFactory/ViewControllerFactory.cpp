//
// Created by magali on 31/03/19.
//

#include "ViewControllerFactory.h"


ViewControllerFactory::ViewControllerFactory(SDL_Renderer * renderer_, int screenWidth_, int screenHeight_) {

    renderer = renderer_;
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
}

ViewControllerFactory::~ViewControllerFactory() = default;


ViewController* ViewControllerFactory::getViewController_fight(){


    ViewController* viewControllerFight = new ViewController(renderer);

    GameObjectControllerFactory* factory = new GameObjectControllerFactory(renderer, screenWidth, screenHeight);

    vector<Controller*>  controllers = factory->getGameObjectControllers_fight();

    for (int i = 0; i < 5; i++){ //Este for tiene que agarrar automaticamente la cantidad de controllers que le pasen. no tiene que estar hardcdeado ese 5.

        viewControllerFight->addController(controllers[i]);
    }

    return viewControllerFight;

}

