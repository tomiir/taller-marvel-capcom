//
// Created by arielpm on 16/05/19.
//

#include "ViewControllerFactory.h"
#include "../../../Json/JsonConfigs.h"
#include "../GameObjectControllerFactory/GameObjectControllerFactory.h"

ViewControllerFactory::ViewControllerFactory(int screenWidth_, int screenHeight_) {

    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
}

ViewControllerFactory::~ViewControllerFactory() = default;


ViewController_fight* ViewControllerFactory::getViewController_fight() {


    ViewController_fight *viewControllerFight = new ViewController_fight();

    JsonConfigs* config = JsonConfigs::getJson();
    int speedCharacter = config->getCharactersSpeed();
    int jumpSpeed = config->getJumpSpeed();
    GameObjectControllerFactory* factory = new GameObjectControllerFactory(screenWidth, screenHeight, speedCharacter, jumpSpeed);

    vector<ControllerBackground *> backgrounds = factory->getControllersBackground_fight();

    for (auto & background : backgrounds){
        viewControllerFight->addBackground(background);
    }

    vector<ControllerCharacter*> characters_ = factory->getControllersCharacter_fight();

    auto itr_character_ = characters_.begin();
    for (; itr_character_ != characters_.end(); ++itr_character_) {
        characters[(*itr_character_)->getName()] = (*itr_character_);
    }

    TeamManager *team1 = new TeamManager(SDL_FLIP_HORIZONTAL);
    TeamManager *team2 = new TeamManager(SDL_FLIP_NONE);

    team1->addEnemyTeam(team2);
    team2->addEnemyTeam(team1);

    FlipManager* flipManager = new FlipManager(team1, team2, backgrounds);

    viewControllerFight->addFlipManager(flipManager);
    viewControllerFight->addTeams(team1, team2);


    return viewControllerFight;
}

map<string, ControllerCharacter*> ViewControllerFactory::getControllerCharacter(){
    return characters;
}