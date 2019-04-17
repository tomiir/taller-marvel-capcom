//
// Created by magali on 31/03/19.
//

#include "ViewControllerFactory.h"
#include "../../../utils/FlipManager/FlipManager.h"
#include "../../../Json/JsonConfigs.h"



ViewControllerFactory::ViewControllerFactory(SDL_Renderer * renderer_, int screenWidth_, int screenHeight_) {

    renderer = renderer_;
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
}

ViewControllerFactory::~ViewControllerFactory() = default;


ViewController* ViewControllerFactory::getViewController_fight(){


    ViewController* viewControllerFight = new ViewController(renderer);

    JsonConfigs* config = new JsonConfigs();
    int speedCharacter = config->getCharactersSpeed();
    int jumpSpeed = config->getJumpSpeed();

    GameObjectControllerFactory* factory = new GameObjectControllerFactory(renderer, screenWidth, screenHeight, speedCharacter, jumpSpeed);

    vector<ControllerBackground*>  backgrounds = factory->getControllersBackground_fight();

    for (int i = 0; i < backgrounds.size(); i++){
        viewControllerFight->addBackground(backgrounds[i]);
    }

    vector<ControllerCharacter*> characters = factory->getControllersCharacter_fight();

    TeamManager* team1 = new TeamManager(characters[0], characters[1], SDL_FLIP_HORIZONTAL);
    TeamManager* team2 = new TeamManager(characters[2], characters[3], SDL_FLIP_NONE);

    team1->addEnemyTeam(team2);
    team2->addEnemyTeam(team1);

    FlipManager* flipManager = new FlipManager(team1, team2, backgrounds);


    viewControllerFight->addFlipManager(flipManager);
    viewControllerFight->addTeams(team1, team2);


    return viewControllerFight;

}

