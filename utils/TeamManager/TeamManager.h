//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
#define TALLER_MARVEL_CAPCOM_TEAMMANAGER_H

#include "../../controllers/Controller/ControllerCharacter/ControllerCharacter.h"
#include "../EventToValueMapper/EventToValueMapper.h"

class TeamManager {
public:
    TeamManager(ControllerCharacter* character_1, ControllerCharacter* character_2, EventToValueMapper* mapper_);

    void handleEvent(SDL_Event event);

private:
    ControllerCharacter* currentCharacter;
    ControllerCharacter* postCharacter;
    EventToValueMapper* mapper; //para solucionar el tema de las teclas, conoce el mapper que comparte su team
    void changeCharacter();
};


#endif //TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
