//
// Created by arielpm on 17/05/19.
//

#include "Game_server.h"


Game_server::Game_server(int screenWidth_, int screenHeight_) {

    screenWidth = screenWidth_;
    screenHeight = screenHeight_;
}



Game_server::~Game_server() = default;


void Game_server::init(const char* gameMode) {

    factory = new ViewControllerFactory(screenWidth, screenHeight);

    viewsController["char_select"] = new ViewController_charSelect();
    viewsController["fight"] = factory->getViewController_fight(gameMode);
    viewsController["endGame"] = new ViewController_endGame;
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

    if(strcmp(nextViewControllerName.c_str(),"endGame") == 0){
        vector <char> winners = dynamic_cast<ViewController_fight*>(viewsController["fight"])-> getWinner();
        char winner_1 = winners[0];
        char winner_2 = winners[1];
        dynamic_cast<ViewController_endGame*>(viewsController["endGame"])->setWinners(winner_1, winner_2);
    }

    this->currentViewController = nextViewController;

}

void Game_server::handleEvent(string event) {

    currentViewController->handleEvent(event);
}

string Game_server::giveNewParameters() {

    return currentViewController->giveNewParameters();
}

int Game_server::currentClientT1() {

    int character = dynamic_cast<ViewController_fight*>(this->currentViewController)->currentCharacterT1() ;

    if (character == 0) return 1;
    if (character == 1) return 3;
}

int Game_server::currentClientT2() {

    int character = dynamic_cast<ViewController_fight*>(this->currentViewController)->currentCharacterT2() ;

    if (character == 0) return 2;
    if (character == 1) return 4;
}





