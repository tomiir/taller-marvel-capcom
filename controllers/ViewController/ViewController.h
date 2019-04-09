//
// Created by trocchi on 3/31/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H

#include "../../views/View/View.h"
#include "../Controller/Controller.h"
#include "../BackgroundsController/BackgroundsController.h"
#include <list>
#include "../../utils/TeamManager/TeamManager.h"

using namespace std;

class ViewController {

public:
    ViewController(SDL_Renderer* renderer_);
    ~ViewController();
    void updateView();
    void handleEvent();
    void addTeamsManager(TeamManager* team1, TeamManager* team2);


private:
    View* view;
    SDL_Renderer* renderer;
    TeamManager* team1;
    TeamManager* team2;



};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
