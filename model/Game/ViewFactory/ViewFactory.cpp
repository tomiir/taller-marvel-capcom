//
// Created by magali on 31/03/19.
//

#include "ViewFactory.h"


View* ViewFactory::getViewFight(){

    View* viewFigth = new View();
    SDL_Renderer *renderer = NULL; //  CREAR RENDER ACA DE LA IMAGEN, esto viene de mas arriba.
    GameObjectControllerFactory* factory = new GameObjectControllerFactory_fight(renderer);
    Controller ** contorllers = factory->getGameObjectControllers();
    for (int i = 0; i<4; i++){
        viewFigth->addController(contorllers[i]);
    }


}