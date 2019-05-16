//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLERFACTORY_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLERFACTORY_H

#include "../GameObjectControllerFactory/GameObjectControllerFactory.h"
#include "../../../controllers/ViewController/ViewController_fight/ViewController_fight.h"
#include "../../../views/View/View.h"
#include "../../../utils/TeamManager/TeamManager.h"
#include "../../../views/View/View_charSelect.h"
#include "../../../views/View/View_fight.h"

using namespace std;

class ViewFactory{



public:
    ViewFactory(SDL_Renderer * renderer_, int screenWidth_, int screenHeight_);
    ~ViewFactory();
    View_fight * getView_fight();
    View_charSelect * getView_charSelect();
    map<string, Character *> getCharacter();

private:
    SDL_Renderer * renderer;
    map<string, Character*> characters_map;
    map<string, Character*>::iterator itr_characters= characters_map.begin();
    int screenWidth, screenHeight;


};


#endif //TALLER_MARVEL_CAPCOM_VIEWFACTORY_H
