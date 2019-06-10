//
// Created by trocchi on 3/31/19.
//

#include "ViewController_fight.h"
#include <algorithm> // for heap operations

#include <SDL2/SDL.h>
#include <pthread.h>
#include <unistd.h>
#include "../../../utils/Logger/Logger.h"

pthread_t countSeconds;
pthread_mutex_t  mutex_second;
int second;

ViewController_fight::ViewController_fight():ViewController() {
    countTime = false;
    time(&start);
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

    if (event == "") return;

    try {
        if (event[1] == '1' or event[1] == '3'){
            team1->handleEvent(event.substr(0, 1), backgrounds);
        }
        else if (event[1] == '2' or event[1] == '4'){
            team2->handleEvent(event.substr(0, 1), backgrounds);
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

void* ViewController_fight::restSeconds(void *pVoid){

    while (second >= 0){
        sleep(1);
        pthread_mutex_lock(&mutex_second);
        second --;
        pthread_mutex_unlock(&mutex_second);
    }
    return nullptr;

}

void ViewController_fight::startCounting(){
    countTime = true;
    second = 99;
    pthread_mutex_init(&mutex_second,NULL);
    pthread_create(&countSeconds, nullptr, restSeconds, nullptr);
    pthread_detach(countSeconds);
    pthread_mutex_destroy(&mutex_second);
}

string ViewController_fight::giveNewParameters() {

    if (!countTime ) {
        this->startCounting();
    }

    string updates = "010000000000000000000000000000000000000000000000";

    vector<int> pos_floor = backgrounds[0]->getPosCamera();
    vector<int> pos_moon = backgrounds[1]->getPosCamera();
    vector<int> pos_galaxy = backgrounds[2]->getPosCamera();

    vector<int> posCharT1 = team1->getPosCurrentCharacter();
    vector<int> posCharT2 = team2->getPosCurrentCharacter();

    updates[31] = team1->getStateCurrentCharacter();
    updates[40] = team2->getStateCurrentCharacter();

    updates[41] = team1->getFlipCurrentCharacter();
    updates[42] = team2->getFlipCurrentCharacter();

    updates[43] = team1->getCurrentCharacterNumber();
    updates[44] = team2->getCurrentCharacterNumber();//No entiendo porque me aparece value is never used

    //int ten = second / 10;
    //int unity = second - second/10;

    char seconds_string[2];

    pthread_mutex_lock(&mutex_second);
    sprintf(seconds_string, "%d",second);
    pthread_mutex_unlock(&mutex_second);

    updates[45] = seconds_string[0]; //ten
    updates[46] = seconds_string[1]; //unity
    //updates = intToString(ten,45,1,updates);
    //updates = intToString(unity, 46, 1, updates);
    updates[47] = '0'; //round


    updates = intToString(pos_floor[0], 2, 4, updates);
    updates = intToString(pos_floor[1], 6, 3, updates);
    updates = intToString(pos_moon[0], 9, 4, updates);
    updates = intToString(pos_moon[1], 13, 3, updates);
    updates = intToString(pos_galaxy[0], 16, 4, updates);
    updates = intToString(pos_galaxy[1], 20, 3, updates);
    updates = intToString(posCharT1[0], 23, 4, updates);
    updates = intToString(posCharT1[1], 27, 4, updates);
    updates = intToString(posCharT2[0], 32, 4, updates);
    updates = intToString(posCharT2[1], 36, 4, updates);

    return updates;
}

int ViewController_fight::currentCharacterT1() {
    return team1->currentCharacterPlaying();
}

int ViewController_fight::currentCharacterT2() {
    return team2->currentCharacterPlaying();
}


