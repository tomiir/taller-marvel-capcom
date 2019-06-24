//
// Created by arielpm on 16/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLERFACTORY_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLERFACTORY_H

#include <string>
#include "../../../controllers/ViewController/ViewController_fight/ViewController_fight.h"

using namespace std;

class ViewControllerFactory{

public:
    ViewControllerFactory(int screenWidth_, int screenHeight_);
    ~ViewControllerFactory();
    ViewController_fight * getViewController_fight(const char* gameMode);
    map<string, ControllerCharacter *> getControllerCharacter();

private:
    map<string, ControllerCharacter*> characters;
    map<string, ControllerCharacter*>::iterator itr_characters= characters.begin();
    int screenWidth, screenHeight;

};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLERFACTORY_H
