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


class ViewController_fight: public ViewController {

public:

    ViewController_fight();
    ~ViewController_fight();
    void handleEvent(string event) override;
    void addTeams(TeamManager* teamManager1, TeamManager* teamManager2);
    bool end()override;
    string getNextView()override;
    void setTeam(vector<ControllerCharacter*> characters, int team);

private:
    TeamManager* team1;
    TeamManager* team2;


};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_FIGHT_H
