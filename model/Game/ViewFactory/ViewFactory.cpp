//
// Created by magali on 31/03/19.
//

#include "ViewFactory.h"
#include "../../../utils/FlipManager/FlipManager.h"
#include "../../../Json/JsonConfigs.h"



ViewFactory::ViewFactory(SDL_Renderer * renderer_, int screenWidth_, int screenHeight_) {

    renderer = renderer_;
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
}

ViewFactory::~ViewFactory() = default;


View_fight* ViewFactory::getView_fight() {


    View_fight *viewFight = new View_fight(renderer);

    GameObjectFactory* factory = new GameObjectFactory(renderer, screenWidth, screenHeight);

    vector<GameObject *> backgrounds = factory->getGameObjectsBackgrounds_fight();

    GameObject* disconnected = factory->getGameObjectDisconnected();

    viewFight->addDisconnected(disconnected);

    for (auto & background : backgrounds){
        viewFight->addBackground(dynamic_cast<Background*>(background));
    }

    vector<GameObject*> characters = factory->getGameObjectsCharacters_fight();

    for (auto & character : characters){
        viewFight->addCharacter(dynamic_cast<Character*>(character));
    }

    auto itr_character_ = characters.begin();
    for (; itr_character_ != characters.end(); ++itr_character_) {
        characters_map[(*itr_character_)->getName()] = (dynamic_cast<Character*>(*itr_character_));
    }

    delete factory;

    return viewFight;
}

map<string, Character*> ViewFactory::getCharacter(){
    return characters_map;
}

View_charSelect * ViewFactory:: getView_charSelect(){

    GameObjectFactory* factory = new GameObjectFactory(renderer, screenWidth, screenHeight);
    vector <GameObject_charSelect*> gameObjects = factory->getgameobjectChar_select_fight();

    GameObject* disconnected = factory->getGameObjectDisconnected();

    View_charSelect* viewCharSelect = new View_charSelect(renderer, screenWidth, screenHeight);

    GameObject_charSelect* go = gameObjects[0];
    viewCharSelect->addGameObject_background(go);
    viewCharSelect->addGameObject_disconnected(disconnected);


    // LOS SIDES DE CADA TEAM
    viewCharSelect->addGameObject_character(gameObjects[1],1);
    viewCharSelect->addGameObject_character(gameObjects[2],2);

    viewCharSelect->addGameObject_character(gameObjects[3],1);
    viewCharSelect->addGameObject_character(gameObjects[4],2);

    viewCharSelect->addGameObject_character(gameObjects[5],1);
    viewCharSelect->addGameObject_character(gameObjects[6],2);

    viewCharSelect->addGameObject_character(gameObjects[7],1);
    viewCharSelect->addGameObject_character(gameObjects[8],2);

    // LOS SIDES DE CADA TEAM selected
    viewCharSelect->addGameObject_character_selected(gameObjects[9],1);
    viewCharSelect->addGameObject_character_selected(gameObjects[10],2);

    viewCharSelect->addGameObject_character_selected(gameObjects[11],1);
    viewCharSelect->addGameObject_character_selected(gameObjects[12],2);

    viewCharSelect->addGameObject_character_selected(gameObjects[13],1);
    viewCharSelect->addGameObject_character_selected(gameObjects[14],2);

    viewCharSelect->addGameObject_character_selected(gameObjects[15],1);
    viewCharSelect->addGameObject_character_selected(gameObjects[16],2);



    // LOS CUADRADITOS DE CADA TEAM
    viewCharSelect->addGameObject_square(gameObjects[17],1);
    viewCharSelect->addGameObject_square(gameObjects[18],2);

    // LOS CUADRADITOS GRISES
    viewCharSelect->addGameObject_square_gray(gameObjects[19]);
    viewCharSelect->addGameObject_square_gray(gameObjects[20]);
    viewCharSelect->addGameObject_square_gray(gameObjects[21]);
    viewCharSelect->addGameObject_square_gray(gameObjects[22]);

    return viewCharSelect;

}


