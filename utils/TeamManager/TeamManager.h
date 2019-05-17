//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
#define TALLER_MARVEL_CAPCOM_TEAMMANAGER_H

#include "../../controllers/Controller/ControllerCharacter/ControllerCharacter.h"
#include "../Mapper/Mapper_fight/Mapper_fight.h"
#include "../../controllers/Controller/ControllerBackground/ControllerBackground.h"
#include <vector>
#include "../../controllers/Controller/Renderable.h"


class TeamManager{

public:
    TeamManager(SDL_RendererFlip initialFlip);

    void handleEvent(string event, std::vector<ControllerBackground*> backgrounds);
    ControllerCharacter* getCurrentCharacter();
    void addEnemyTeam(TeamManager* enemyTeam_);

    void flipCurrentCharacter();
    void setCharacters(std::vector<ControllerCharacter*> characters);
    void setInitialPos(bool left);


private:


    ControllerCharacter* currentCharacter;
    ControllerCharacter* supportCharacter;
    TeamManager* enemyTeam;
    SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

    void changeCharacter();
};

#endif //TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
