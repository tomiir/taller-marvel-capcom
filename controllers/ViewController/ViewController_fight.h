//
// Created by trocchi on 3/31/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_FIGHT_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_FIGHT_H

#include "../../views/View/View.h"
#include "../Controller/Controller.h"
#include "../Controller/Renderable.h"
#include "ViewController.h"
#include <vector>
#include "../Controller/ControllerBackground/ControllerBackground.h"
#include "../../utils/TeamManager/TeamManager.h"
#include "../Controller/BackgroundsCotroller/BackgroundsController.h"
#include "../../utils/FlipManager/FlipManager.h"


class ViewController_fight: public ViewController {

public:

    ViewController_fight(SDL_Renderer* renderer_);
    ~ViewController_fight();
    void updateView() override;
    void handleEvent() override;
    void addFlipManager(FlipManager* flipManager_);
    void addBackground(ControllerBackground* controller) override;
    void addTeams(TeamManager* teamManager1, TeamManager* teamManager2);

private:

    View* view;
    SDL_Renderer* renderer;
    std::vector<ControllerBackground*> backgrounds;
    TeamManager* team1;
    TeamManager* team2;
    BackgroundsController* backgroundsController;
    FlipManager* flipManager;
};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_FIGHT_H
