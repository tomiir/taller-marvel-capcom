//
// Created by trocchi on 3/31/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_FIGHT_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_FIGHT_H

#include "../../../views/View/View.h"
#include "../../Controller/Controller.h"
#include "../../Controller/Renderable.h"
#include "../ViewController.h"
#include <vector>
#include "../../Controller/ControllerBackground/ControllerBackground.h"
#include "../../../utils/TeamManager/TeamManager.h"
#include "../../../utils/FlipManager/FlipManager.h"
#include <time.h>


class ViewController_fight: public ViewController {

public:

    ViewController_fight();
    ~ViewController_fight();
    void handleEvent(string event) override;
    void addTeams(TeamManager* teamManager1, TeamManager* teamManager2);
    bool end()override;
    string getNextView()override;
    void setTeam(vector<ControllerCharacter*> characters, int team);
    string giveNewParameters() override ;

    void addBackground(ControllerBackground *controller);

    void addFlipManager(FlipManager *flipManager_);

    void createFlipManager();

    int currentCharacterT2();

    int currentCharacterT1();

    vector <char> getWinner();


private:
    TeamManager* team1;
    TeamManager* team2;
    bool countTime;
    FlipManager* flipManager;
    int round;
    bool endOfRounds;
    std::vector<ControllerBackground*> backgrounds;
    void startCounting();
    time_t start;
    static void * restSeconds(void *pVoid);
    char winner_1;
    char winner_2;
    bool endOfGame;
};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_FIGHT_H
