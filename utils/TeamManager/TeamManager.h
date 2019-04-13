//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
#define TALLER_MARVEL_CAPCOM_TEAMMANAGER_H

#include "../../controllers/Controller/ControllerCharacter/ControllerCharacter.h"
#include "../EventToValueMapper/EventToValueMapper.h"
#include "../../controllers/Controller/ControllerBackground/ControllerBackground.h"
#include <vector>


class TeamManager {
public:
    TeamManager(ControllerCharacter* character_1, ControllerCharacter* character_2, SDL_RendererFlip initialFlip);

    void handleEvent(SDL_Event event, std::vector<ControllerBackground*> backgrounds);
    void render();
    ControllerCharacter* getCurrentCharacter();
    void addEnemyTeam(TeamManager* enemyTeam_);

    void flipCurrentCharacter();

private:
    ControllerCharacter* currentCharacter;
    ControllerCharacter* supportCharacter;
    TeamManager* enemyTeam;
    EventToValueMapper* mapper; //para solucionar el tema de las teclas, conoce el mapper que comparte su team
    SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

    void changeCharacter();
};

#endif //TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
