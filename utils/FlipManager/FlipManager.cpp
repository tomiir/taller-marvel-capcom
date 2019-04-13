//
// Created by fer on 10/04/19.
//

#include "FlipManager.h"

FlipManager::FlipManager(TeamManager *teamManager1_, TeamManager *teamManager2_, BackgroundsController* backgroundsController_) {

    teamManager1 = teamManager1_;
    teamManager2 = teamManager2_;
    backgroundsController = backgroundsController_;

}

void FlipManager::update() {

    ControllerCharacter* currentCharacterTeam1 = teamManager1->getCurrentCharacter();
    ControllerCharacter* currentCharacterTeam2 = teamManager2->getCurrentCharacter();

    vector<int> infoCharacter1 = currentCharacterTeam1->getInfo();
    vector<int> infoCharacter2 = currentCharacterTeam2->getInfo();

    ControllerCharacter* auxLeft = characterOnLeft;
    ControllerCharacter* auxRight = characterOnRight;

    if(infoCharacter1[0] <= infoCharacter2[0]){

        characterOnLeft = currentCharacterTeam1;
        characterOnRight = currentCharacterTeam2;
        characterOnLeftInfo = infoCharacter1;
        characterOnRightInfo = infoCharacter2;

    }
    else if (infoCharacter2[0] <= infoCharacter1[0]){
        characterOnLeft = currentCharacterTeam2;
        characterOnRight = currentCharacterTeam1;
        characterOnLeftInfo = infoCharacter2;
        characterOnRightInfo = infoCharacter1;
    }

    if(auxLeft != characterOnLeft and auxRight != characterOnRight){

        teamManager1->flipCurrentCharacter();
        teamManager2->flipCurrentCharacter();
    }


    //backgroundsController->update(characterOnLeft, characterOnLeftInfo, characterOnRight, characterOnRightInfo);

    vector<ControllerBackground*>::iterator itr = backgrounds.begin();

    for (itr; itr != backgrounds.end(); ++itr) {
        (*itr)->update(characterOnLeft, characterOnLeftInfo, characterOnRight, characterOnRightInfo);
    }
    itr = backgrounds.begin();

}

FlipManager::FlipManager(TeamManager* teamManager1_, TeamManager* teamManager2_, vector< ControllerBackground*> backgrounds_) {

    teamManager1 = teamManager1_;
    teamManager2 = teamManager2_;
    backgrounds = backgrounds_;

    this->update();

    vector<ControllerBackground*>::iterator itr = backgrounds.begin();
    for (itr; itr != backgrounds.end(); ++itr) {
        (*itr)->update(characterOnLeft, characterOnLeftInfo, characterOnRight, characterOnRightInfo);
    }
    itr = backgrounds.begin();


}

