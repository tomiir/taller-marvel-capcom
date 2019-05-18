//
// Created by trocchi on 3/31/19.
//

#include "ViewController_fight.h"
#include <algorithm> // for heap operations

#include <SDL2/SDL.h>

#include "../../../utils/Logger/Logger.h"

ViewController_fight::ViewController_fight():ViewController() {

}

ViewController_fight::~ViewController_fight() = default;


void ViewController_fight::addTeams(TeamManager* teamManager1, TeamManager* teamManager2) {

    team1 = teamManager1;
    team2 = teamManager2;
}


bool ViewController_fight::end() {
    //lo hardcodeo pq no tenemos otra view
    return false;
}

string ViewController_fight::getNextView() {
    return "todavia_no_existe";
}

void ViewController_fight::setTeam(vector<ControllerCharacter *> characters, int team) {

    if (team == 1) {
        team1->setCharacters(characters);
        team1->setInitialPos(true);
    }
    else {

        team2->setCharacters(characters);
        team2->setInitialPos(false);
    }

}

void ViewController_fight::addBackground(ControllerBackground *controller) {

    backgrounds.push_back(controller);
}

void ViewController_fight::addFlipManager(FlipManager *flipManager_) {

    flipManager = flipManager_;
}

void ViewController_fight::createFlipManager() {

    flipManager->create();
}


void ViewController_fight::handleEvent(string event) {

    CLogger* logger = CLogger::GetLogger();

// MODIFICAR EL HANDLEEVENT!
    try {
        if ((event[5] == '0' and event[6] == '0') or (event[5] == '1' and event[6] == '0')){
            team1->handleEvent(event.substr(0, 5), backgrounds);
        }
        else if ((event[5] == '0' and event[6] == '1') or (event[5] == '1' and event[6] == '1')){
            team2->handleEvent(event.substr(0, 5), backgrounds);
        }

        flipManager->update();

    } catch(exception e) {
        logger -> Log("Falló al querer manejar un evento", ERROR, e.what());
        logger -> Log("Falló al querer manejar el evento: " + event, DEBUG, e.what());
        throw -1;
    }
}

string intToString(int value, int posNum, int cantNum, string updates){

    string aux = "";
    aux = std::to_string(value);

    int len = aux.size();

    for(int i = 0; i < len ;i++){
        updates[posNum + cantNum - 1 - i] = aux[len - 1 - i];
    }

    return updates;
}



string ViewController_fight::giveNewParameters() {

    string updates = "0100000000000000000000000000000000000000000";

    vector<int> pos_floor = backgrounds[0]->getPosCamera();
    vector<int> pos_moon = backgrounds[1]->getPosCamera();
    vector<int> pos_galaxy = backgrounds[2]->getPosCamera();

    vector<int> posCharT1 = team1->getPosCurrentCharacter();
    vector<int> posCharT2 = team2->getPosCurrentCharacter();

    updates[30] = team1->getStateCurrentCharacter();
    updates[38] = team2->getStateCurrentCharacter();

    updates[39] = team1->getFlipCurrentCharacter();
    updates[40] = team2->getFlipCurrentCharacter();

    updates[41] = team1->getCurrentCharacterNumber();
    updates[42] = team2->getCurrentCharacterNumber();  //No entiendo porque me aparece value is never used


    updates = intToString(pos_floor[0], 2, 4, updates);
    updates = intToString(pos_floor[1], 6, 3, updates);
    updates = intToString(pos_moon[0], 9, 4, updates);
    updates = intToString(pos_moon[1], 13, 3, updates);
    updates = intToString(pos_galaxy[0], 16, 4, updates);
    updates = intToString(pos_galaxy[1], 20, 3, updates);
    updates = intToString(posCharT1[0], 23, 4, updates);
    updates = intToString(posCharT1[1], 27, 3, updates);
    updates = intToString(posCharT2[0], 31, 4, updates);
    updates = intToString(posCharT2[1], 35, 3, updates);

    return updates;
}


