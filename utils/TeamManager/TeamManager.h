//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
#define TALLER_MARVEL_CAPCOM_TEAMMANAGER_H

#include "../../controllers/Controller/ControllerCharacter/ControllerCharacter.h"
#include "../EventToValueMapper/EventToValueMapper.h"

class TeamManager {
public:
    TeamManager(ControllerCharacter* character_1, ControllerCharacter* character_2);

    void handleEvent(SDL_Event event);

private:
    ControllerCharacter* currentCharacter;
    ControllerCharacter* supportCharacter;
    void changeCharacter();
};


#endif //TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
