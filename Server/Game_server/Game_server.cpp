//
// Created by arielpm on 17/05/19.
//

#include "Game_server.h"
#include "../../controllers/ViewController/ViewController_charSelect/ViewController_charSelect.h"


Game_server::Game_server(int screenWidth_, int screenHeight_) {

    screenWidth = screenWidth_;
    screenHeight = screenHeight_;
}



Game_server::~Game_server() = default;


void Game_server::init() {

    factory = new ViewControllerFactory(screenWidth, screenHeight);

    viewsController["char_select"] = new ViewController_charSelect();
    viewsController["fight"] = factory->getViewController_fight();
    characters = factory->getControllerCharacter();

    currentViewController = (viewsController.find("char_select"))->second;

}

bool Game_server::haveToChangeViewController() {

    return currentViewController->end();
}

void Game_server::changeViewController() {

    string nextViewControllerName = currentViewController->getNextView();
    ViewController* nextViewController = viewsController.find(nextViewControllerName)->second;

    if (strcmp(nextViewControllerName.c_str(), "fight") == 0){
        // esto significa que la anterior fue la de selección de personajes;
        vector<string> team1 = dynamic_cast<ViewController_charSelect*>(viewsController["char_select"])-> getTeam1();
        vector<string> team2 = dynamic_cast<ViewController_charSelect*>(viewsController["char_select"]) -> getTeam2();

        vector<ControllerCharacter*> aux = {(characters.find(team1[0])->second), (characters.find(team1[1])->second)};
        dynamic_cast<ViewController_fight*>(viewsController["fight"])->setTeam(aux,1);

        aux =  {(characters.find(team2[0])->second), (characters.find(team2[1])->second)};
        dynamic_cast<ViewController_fight*>(viewsController["fight"])->setTeam(aux,2);

        dynamic_cast<ViewController_fight*>(viewsController["fight"])->createFlipManager();
    }

    this->currentViewController = nextViewController;

}

void Game_server::handleEvent(string event) {

    currentViewController->handleEvent(event);
}

string Game_server::giveNewParameters() {

    return currentViewController->giveNewParameters();
}





