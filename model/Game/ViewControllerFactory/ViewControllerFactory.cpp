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


ViewController_fight* ViewControllerFactory::getViewController_fight() {


    ViewController_fight *viewControllerFight = new ViewController_fight(renderer);

    JsonConfigs* config = JsonConfigs::getJson();
    int speedCharacter = config->getCharactersSpeed();
    int jumpSpeed = config->getJumpSpeed();

    GameObjectControllerFactory* factory = new GameObjectControllerFactory(renderer, screenWidth, screenHeight, speedCharacter, jumpSpeed);

    vector<ControllerBackground *> backgrounds = factory->getControllersBackground_fight();

    for (int i = 0; i < backgrounds.size(); i++){
        viewControllerFight->addBackground(backgrounds[i]);
    }

    vector<ControllerCharacter*> characters_ = factory->getControllersCharacter_fight();

    vector<ControllerCharacter*> :: iterator  itr_character_ = characters_.begin();
    for (itr_character_; itr_character_ != characters_.end(); ++itr_character_) {
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

ViewController_charSelect * ViewControllerFactory:: getViewController_charSelect(){

    GameObjectFactory* factory = new GameObjectFactory(renderer, screenWidth, screenHeight);
    vector <GameObject_charSelect*> gameObjects = factory->getgameobjectChar_select_fight();

    ViewController_charSelect* viewController = new ViewController_charSelect(renderer);
    viewController->addGameObject_background(gameObjects[0]);


    // LOS SIDES DE CADA TEAM
    viewController->addGameObject_character(gameObjects[1],1);
    viewController->addGameObject_character(gameObjects[2],2);

    viewController->addGameObject_character(gameObjects[3],1);
    viewController->addGameObject_character(gameObjects[4],2);

    viewController->addGameObject_character(gameObjects[5],1);
    viewController->addGameObject_character(gameObjects[6],2);

    viewController->addGameObject_character(gameObjects[7],1);
    viewController->addGameObject_character(gameObjects[8],2);

    // LOS SIDES DE CADA TEAM selected
    viewController->addGameObject_character_selected(gameObjects[9],1);
    viewController->addGameObject_character_selected(gameObjects[10],2);

    viewController->addGameObject_character_selected(gameObjects[11],1);
    viewController->addGameObject_character_selected(gameObjects[12],2);

    viewController->addGameObject_character_selected(gameObjects[13],1);
    viewController->addGameObject_character_selected(gameObjects[14],2);

    viewController->addGameObject_character_selected(gameObjects[15],1);
    viewController->addGameObject_character_selected(gameObjects[16],2);



    // LOS CUADRADITOS DE CADA TEAM
    viewController->addGameObject_square(gameObjects[17],1);
    viewController->addGameObject_square(gameObjects[18],2);

    // LOS CUADRADITOS GRISES
    viewController->addGameObject_square_gray(gameObjects[19]);
    viewController->addGameObject_square_gray(gameObjects[20]);
    viewController->addGameObject_square_gray(gameObjects[21]);
    viewController->addGameObject_square_gray(gameObjects[22]);

    return viewController;




}


