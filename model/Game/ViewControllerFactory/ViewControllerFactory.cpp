//
// Created by magali on 31/03/19.
//

#include "ViewControllerFactory.h"
#include "../../../controllers/BackgroundsController/BackgroundsController.h"
#include "../../../utils/TeamManager/TeamManager.h"


ViewControllerFactory::ViewControllerFactory(SDL_Renderer * renderer_, int screenWidth_, int screenHeight_) {

    renderer = renderer_;
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
}

ViewControllerFactory::~ViewControllerFactory() = default;


ViewController* ViewControllerFactory::getViewController_fight(){

    ViewController* viewControllerFight = new ViewController(renderer);

    GameObjectControllerFactory* factory = new GameObjectControllerFactory(renderer, screenWidth, screenHeight);

    vector<ControllerCharacter*>  controllersCharacters = factory->getCharacterControllers_fight();

    BackgroundsController* backgroundsController = factory->getBackgroundsController_fight();

    viewControllerFight->addBackgroundsController(backgroundsController);

    TeamManager* team1 = new TeamManager(controllersCharacters[0], controllersCharacters[1]);
    TeamManager* team2 = new TeamManager(controllersCharacters[2], controllersCharacters[3]);

    backgroundsController->addTeamsManager(team1, team2);

    for (int i = 0; i < controllersCharacters.size(); i++){

        viewControllerFight->addControllerCharacter(controllersCharacters[i]);
    }

    return viewControllerFight;

}

