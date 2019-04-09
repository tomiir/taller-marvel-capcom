//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
#define TALLER_MARVEL_CAPCOM_TEAMMANAGER_H

#include "../../controllers/Controller/ControllerCharacter/ControllerCharacter.h"
#include "../EventToValueMapper/EventToValueMapper.h"
#include "../../controllers/Controller/ControllerBackground/ControllerBackground.h"
#include <list>


class TeamManager {
public:
    TeamManager(ControllerCharacter* character_1, ControllerCharacter* character_2);

    void handleEvent(SDL_Event event, std::list<ControllerBackground*> backgrounds);
    void render();

private:
    ControllerCharacter* currentCharacter;
    ControllerCharacter* supportCharacter;
    EventToValueMapper* mapper; //para solucionar el tema de las teclas, conoce el mapper que comparte su team
    void changeCharacter();
};


#endif //TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
