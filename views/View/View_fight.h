//
// Created by arielpm on 16/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEW_FIGHT_H
#define TALLER_MARVEL_CAPCOM_VIEW_FIGHT_H


#include <vector>
#include "../../controllers/ViewController/ViewController.h"



class View_fight: public View {

public:

    View_fight(SDL_Renderer* renderer_);
    ~View_fight();
    void updateView() override;
    void addFlipManager(FlipManager* flipManager_);
    void addBackground(ControllerBackground* controller) override;
    void addTeams(TeamManager* teamManager1, TeamManager* teamManager2);
    bool end()override;
    string getNextView()override;
    void setTeam(vector<ControllerCharacter*> characters, int team);
    void createFlipManager();

private:
    TeamManager* team1;
    TeamManager* team2;
    FlipManager* flipManager;


};


#endif //TALLER_MARVEL_CAPCOM_VIEW_FIGHT_H
