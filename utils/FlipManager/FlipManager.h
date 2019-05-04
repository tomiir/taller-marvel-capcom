//
// Created by fer on 10/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_FLIPMANAGER_H
#define TALLER_MARVEL_CAPCOM_FLIPMANAGER_H


#include "../TeamManager/TeamManager.h"
#include "../../controllers/Controller/BackgroundsCotroller/BackgroundsController.h"
#include <vector>

class FlipManager {

public:

    FlipManager();
    FlipManager(TeamManager* teamManager1_, TeamManager* teamManager2_, vector< ControllerBackground*> backgrounds_);

    FlipManager(TeamManager* teamManager1_, TeamManager* teamManager2_, BackgroundsController* backgroundsController_);
    ~FlipManager() = default;

    void update();

    void create();


    //AGREGAR ESTO EN VIEWCONTROLLERFACTORY

private:

    TeamManager* teamManager1;
    TeamManager* teamManager2;

    BackgroundsController* backgroundsController;
    vector< ControllerBackground*> backgrounds;

    ControllerCharacter* characterOnLeft;
    ControllerCharacter* characterOnRight;

    vector<int> characterOnLeftInfo;
    vector<int> characterOnRightInfo;

};


#endif //TALLER_MARVEL_CAPCOM_FLIPMANAGER_H
