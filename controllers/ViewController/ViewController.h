//
// Created by trocchi on 3/31/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
#define TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H

#include "../../views/View/View.h"
#include "../Controller/Controller.h"
#include <list>
#include "../Controller/ControllerBackground/ControllerBackground.h"
#include "../../utils/TeamManager/TeamManager.h"


class ViewController {

public:
    ViewController(SDL_Renderer* renderer_);
    ~ViewController();
    void updateView();
    void handleEvent();
    void addBackground(ControllerBackground* controller);
    void addTeamManager(TeamManager* teamManager);
private:
    View* view;
    SDL_Renderer* renderer;
    std::list<ControllerBackground*> backgrounds;
    std::list<TeamManager*> teams;
};


#endif //TALLER_MARVEL_CAPCOM_VIEWCONTROLLER_H
