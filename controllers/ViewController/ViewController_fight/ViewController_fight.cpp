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
int second;

ViewController_fight::ViewController_fight(const char* gameMode):ViewController() {
    endOfRounds = false;
    countTime = false;
    time(&start);
    round = 0;
    endOfGame = false;
    shouldFight = false;

    this->gameMode = gameMode;
}

ViewController_fight::~ViewController_fight() = default;


void ViewController_fight::addTeams(TeamManager* teamManager1, TeamManager* teamManager2) {

    team1 = teamManager1;
    team2 = teamManager2;
}


bool ViewController_fight::end() {
    return endOfGame;
}

string ViewController_fight::getNextView() {
    return "endGame";
}

void ViewController_fight::setTeam(vector<ControllerCharacter *> characters, int team) {

    if (team == 1) {
        team1->setCharacters(characters);
        team1->setInitialPos(true);
        team1->setGameMode(gameMode);
    }
    else {

        team2->setCharacters(characters);
        team2->setInitialPos(false);
        team2->setGameMode(gameMode);
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

    if(shouldFight) {

        try {
            if (event[1] == '1' or event[1] == '3') {
                team1->handleEvent(event.substr(0, 1), backgrounds);
            } else if (event[1] == '2' or event[1] == '4') {
                team2->handleEvent(event.substr(0, 1), backgrounds);
            }

            flipManager->update();

        } catch (exception e) {
            logger->Log("Falló al querer manejar un evento", ERROR, e.what());
            logger->Log("Falló al querer manejar el evento: " + event, DEBUG, e.what());
            throw -1;
        }
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
        second --;
    }
    return nullptr;

}

void ViewController_fight::startCounting(int timeToCount){
    countTime = true;
    second = timeToCount;
    pthread_create(&countSeconds, nullptr, restSeconds, nullptr);


}

string ViewController_fight::giveNewParameters() {

    if(strcmp(gameMode, "game") == 0) {
        if (team1->getTeamLife() == 0) {

            pthread_cancel(countSeconds);
            pthread_detach(countSeconds);
            round++;
            countTime = false;
            shouldFight = false;
            second = 0;

            team2->roundWin();
            team1->resetRound();
            team2->resetRound();

            flipManager->setLeftCharacter(team1->getCurrentCharacter());
            flipManager->setRightCharacter(team2->getCurrentCharacter());
        }

        if (team2->getTeamLife() == 0) {

            pthread_cancel(countSeconds);
            pthread_detach(countSeconds);
            round++;
            countTime = false;
            shouldFight = false;
            second = 0;

            team1->roundWin();
            team1->resetRound();
            team2->resetRound();

            flipManager->setLeftCharacter(team1->getCurrentCharacter());
            flipManager->setRightCharacter(team2->getCurrentCharacter());
        }


        if (!countTime && shouldFight) {
            this->startCounting(timeDuration);// esto debería ser 99
        }

        if (second == 0 && !endOfRounds && shouldFight) { //no me deje moverme mientras esta el fight
            pthread_cancel(countSeconds);
            pthread_detach(countSeconds);
            round++;
            countTime = false;
            shouldFight = false;

            int team1Life = team1->getTeamLife();
            int team2Life = team2->getTeamLife();

            if (team1Life > team2Life) team1->roundWin();
            else if (team1Life < team2Life) team2->roundWin();
            else if (team1Life == team2Life) {
                team1->roundWin();
                team2->roundWin();
            }
            team1->resetRound();
            team2->resetRound();

            flipManager->setLeftCharacter(team1->getCurrentCharacter());
            flipManager->setRightCharacter(team2->getCurrentCharacter());
        }

        if (!countTime && !shouldFight) {
            this->startCounting(3);
        } else if (!shouldFight && second == 0) { //una vez que termina el fight me habilita a moverme
            pthread_cancel(countSeconds);
            pthread_detach(countSeconds);
            shouldFight = true;
            countTime = false;
        }

        if (team1->getRoundsWon() == 2) {
            endOfRounds = true;
            endOfGame = true;
            shouldFight = false;

            vector<char> charactersTeam1 = team1->getCharacters();

            winner_1 = charactersTeam1[0];
            winner_2 = charactersTeam1[1];

            round = 3;
        } else if (team2->getRoundsWon() == 2) {
            endOfRounds = true;
            endOfGame = true;
            shouldFight = false;

            vector<char> charactersTeam2 = team2->getCharacters();

            winner_1 = charactersTeam2[0];
            winner_2 = charactersTeam2[1];

            round = 3;
        }

    }else shouldFight = true;


    string updates = "010000000000000000000000000000000000000000000000000000000000000000000000000";

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
    updates[44] = team2->getCurrentCharacterNumber();


    char seconds_string[2];
    sprintf(seconds_string, "%d",second);
    if (second < 10){
        updates[45] = '0';
        updates[46] = seconds_string[0];
    }
    else {
        updates[45] = seconds_string[0]; //ten
        updates[46] = seconds_string[1]; //unity
    }

    char round_string [1];
    sprintf(round_string, "%d", round);
    updates[47] = round_string[0]; //round


    //int lifeTeam1 = second; // uso esto para probar si las barras cambian bien de vida
    int lifeTeam1 = team1->getCurrentCharacterLife();
    int lifeTeam2 = team2->getCurrentCharacterLife();

    if (strcmp(gameMode, "training") == 0){
        lifeTeam1 = 100;
        lifeTeam2 = 100;
    }

    char lifeTeam1_string[3];
    char lifeTeam2_string[3];

    sprintf(lifeTeam1_string, "%d", lifeTeam1);
    sprintf(lifeTeam2_string, "%d", lifeTeam2);

    if (lifeTeam1 == 100){
        updates[48] = lifeTeam1_string[0];
        updates[49] = lifeTeam1_string[1];
        updates[50] = lifeTeam1_string[2];
    }

    if(lifeTeam1 < 100 && lifeTeam1 >= 10) {
        updates[48] = '0';
        updates[49] = lifeTeam1_string[0];
        updates[50] = lifeTeam1_string[1];
    }

    if(lifeTeam1 < 10){
        updates[48] = '0';
        updates[49] = '0';
        updates[50] = lifeTeam1_string[0];
    }


    if (lifeTeam2 == 100){
        updates[51] = lifeTeam2_string[0];
        updates[52] = lifeTeam2_string[1];
        updates[53] = lifeTeam2_string[2];
    }

    if(lifeTeam2 < 100 && lifeTeam2 >= 10) {
        updates[51] = '0';
        updates[52] = lifeTeam2_string[0];
        updates[53] = lifeTeam2_string[1];
    }

    if(lifeTeam2 < 10){
        updates[51] = '0';
        updates[52] = '0';
        updates[53] = lifeTeam2_string[0];
    }

    if(shouldFight) updates[54] = '1';
    else updates[54] = '0';

    updates[55] = team1->getRoundsWon() + '0';
    updates[56] = team2->getRoundsWon() + '0';


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

    vector<int> posProjectileCharT1 = team1->getPosCurrentProjectile();
    vector<int> posProjectileCharT2 = team2->getPosCurrentProjectile();

    updates[57] = team1->getProjectileState();
    updates[58] = team1->getProjectileFlip();

    updates[66] = team2->getProjectileState();
    updates[67] = team2->getProjectileFlip();


    updates = intToString(posProjectileCharT1[0], 59, 4, updates);
    updates = intToString(posProjectileCharT1[1], 63, 3, updates);
    updates = intToString(posProjectileCharT2[0], 68, 4, updates);
    updates = intToString(posProjectileCharT2[1], 72, 3, updates);

    return updates;
}

int ViewController_fight::currentCharacterT1() {
    return team1->currentCharacterPlaying();
}

int ViewController_fight::currentCharacterT2() {
    return team2->currentCharacterPlaying();
}

vector<char > ViewController_fight::getWinner() {
    vector <char> winners = {winner_1, winner_2};
    return winners;
}


