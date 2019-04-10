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

    vector<ControllerBackground*>  backgrounds = factory->getControllersBackground_fight();


    for (int i = 0; i < backgrounds.size(); i++){
        viewControllerFight->addBackground(backgrounds[i]);
    }

    vector<ControllerCharacter*> characters = factory->getControllersCharacter_fight();

    TeamManager* team1 = new TeamManager(characters[0], characters[1]);
    TeamManager* team2 = new TeamManager(characters[2], characters[3]);

    team1->addEnemyTeam(team2);
    team2->addEnemyTeam(team1);

    viewControllerFight->addTeamManager(team1);
    viewControllerFight->addTeamManager(team2);


    return viewControllerFight;

}

