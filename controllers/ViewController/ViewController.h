//
// Created by trocchi on 3/31/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H

#include "../../views/View/View.h"
#include "../Controller/Controller.h"
#include "../Controller/Renderable.h"
#include <vector>
#include "../Controller/ControllerBackground/ControllerBackground.h"
#include "../../utils/TeamManager/TeamManager.h"
#include "../Controller/BackgroundsCotroller/BackgroundsController.h"
#include "../../utils/FlipManager/FlipManager.h"


class ViewController {

public:

    ViewController(SDL_Renderer* renderer_);
    ~ViewController();
    void updateView();
    void handleEvent();
    void addFlipManager(FlipManager* flipManager_);
    void addBackground(ControllerBackground* controller);
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


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
