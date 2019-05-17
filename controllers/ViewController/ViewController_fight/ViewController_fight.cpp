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
            team1->handleEvent(event.substr(0, 4), backgrounds);
        }
        else if ((event[5] == '0' and event[6] == '1') or (event[5] == '1' and event[6] == '1')){
            team2->handleEvent(event.substr(0, 4), backgrounds);
        }

        flipManager->update();

    } catch(exception e) {
        logger -> Log("Falló al querer manejar un evento", ERROR, e.what());
        logger -> Log("Falló al querer manejar el evento: " + event, DEBUG, e.what());
        throw -1;
    }
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
    updates[42] = team2->getCurrentCharacterNumber();

    string pos_floor_x = "";
    pos_floor_x = std::to_string(pos_floor[0]);

    string pos_floor_y = "";
    pos_floor_y = std::to_string(pos_floor[1]);

    string pos_moon_x = "";
    pos_moon_x = std::to_string(pos_moon[0]);

    string pos_moon_y = "";
    pos_moon_y = std::to_string(pos_moon[1]);

    string pos_galaxy_x = "";
    pos_galaxy_x = std::to_string(pos_galaxy[0]);

    string pos_galaxy_y = "";
    pos_floor_y = std::to_string(pos_galaxy[1]);

    string pos_charT1_x = "";
    pos_charT1_x = std::to_string(posCharT1[0]);

    string pos_charT1_y = "";
    pos_charT1_y = std::to_string(posCharT1[1]);

    string pos_charT2_x = "";
    pos_charT2_x = std::to_string(posCharT2[0]);

    string pos_charT2_y = "";
    pos_charT2_y = std::to_string(posCharT2[1]);


}


