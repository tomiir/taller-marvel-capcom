//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
#define TALLER_MARVEL_CAPCOM_TEAMMANAGER_H

#include "../../controllers/Controller/ControllerCharacter/ControllerCharacter.h"
#include "../EventToValueMapper/EventToValueMapper_player/EventToValueMapper.h"
#include "../../controllers/Controller/ControllerBackground/ControllerBackground.h"
#include <vector>
#include "../../controllers/Controller/Renderable.h"


class TeamManager: virtual public Renderable{
public:
    TeamManager(SDL_RendererFlip initialFlip);

    void handleEvent(SDL_Event event, std::vector<ControllerBackground*> backgrounds);
    void render() override;
    ControllerCharacter* getCurrentCharacter();
    void addEnemyTeam(TeamManager* enemyTeam_);

    void flipCurrentCharacter();
    int getZIndex() override;
    void setCharacters(std::vector<ControllerCharacter*> characters);

private:


    ControllerCharacter* currentCharacter;
    ControllerCharacter* supportCharacter;
    TeamManager* enemyTeam;
    EventToValueMapper* mapper; //para solucionar el tema de las teclas, conoce el mapper que comparte su team
    SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

    void changeCharacter();
};

#endif //TALLER_MARVEL_CAPCOM_TEAMMANAGER_H
