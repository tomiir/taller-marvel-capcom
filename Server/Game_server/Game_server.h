//
// Created by arielpm on 17/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAME_SERVER_H
#define TALLER_MARVEL_CAPCOM_GAME_SERVER_H

#include <string>
#include <string.h>
#include "../../controllers/ViewController/ViewController.h"
#include "../../model/Game/ViewControllerFactory/ViewControllerFactory.h"


using namespace std;

class Game_server {

public:
    Game_server(int screenWidth_, int screenHeight_);
    ~Game_server();
    void init();


    bool haveToChangeViewController();

    void changeViewController();

    void handleEvent(string event);

    string giveNewParameters();

private:
    int screenWidth;
    int screenHeight;

    map<string, ViewController*> viewsController;
    map<string, ViewController*>::iterator itr_viewsController = viewsController.begin();

    map<string, ControllerCharacter*> characters;

    ViewController* currentViewController;

    ViewControllerFactory* factory;

};


#endif //TALLER_MARVEL_CAPCOM_GAME_SERVER_H