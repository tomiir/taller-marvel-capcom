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

}


