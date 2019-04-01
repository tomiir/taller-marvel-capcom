//
// Created by magali on 31/03/19.
//

#include "ViewControllerFactory.h"


ViewControllerFactory::ViewControllerFactory(SDL_Renderer * renderer_) {
    renderer = renderer_;
}

ViewController* ViewControllerFactory::getViewController_fight(){


    ViewController* viewControllerFight = new ViewController(renderer);

    GameObjectControllerFactory* factory = new GameObjectControllerFactory(renderer);
    std::vector<Controller*>  controllers = factory->getGameObjectControllers_fight();
    for (int i = 0; i<4; i++){
        viewControllerFight->addController(controllers[i]);
    }
    return viewControllerFight;

}