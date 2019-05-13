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

using namespace std;

class ViewControllerFactory{



public:
    ViewControllerFactory(SDL_Renderer * renderer_, int screenWidth_, int screenHeight_);
    ~ViewControllerFactory();
    ViewController_fight * getViewController_fight();
    View_charSelect * getView_charSelect();
    map<string, ControllerCharacter *> getControllerCharacter();

private:
    SDL_Renderer * renderer;
    map<string, ControllerCharacter*> characters;
    map<string, ControllerCharacter*>::iterator itr_characters= characters.begin();
    int screenWidth, screenHeight;


};


#endif //TALLER_MARVEL_CAPCOM_VIEWFACTORY_H
