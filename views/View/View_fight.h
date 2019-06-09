//
// Created by arielpm on 16/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEW_FIGHT_H
#define TALLER_MARVEL_CAPCOM_VIEW_FIGHT_H


#include <vector>
#include "../../controllers/ViewController/ViewController.h"
#include "../../utils/LifeManager/LifeManager.h"
#include "../../utils/TimeManager/TimeManager.h"


class View_fight: public View {

public:

    View_fight(SDL_Renderer* renderer_);
    ~View_fight();
    void updateView() override;
    void addBackground(Background* background);
    void addLifeManagers(LifeManager* team1, LifeManager* team2);
    void addTimeManager(TimeManager* timeManager);
    bool end()override;
    string getNextView() override;
    void addCharacter(Character *pCharacter);
    void updateBackgrounds(char* posFloor_x, char* posFloor_y, char* posMoon_x, char* posMoon_y, char* posGalaxy_x, char* posGalaxy_y);
    void updateCharacters(char *posT1_x, char *posT1_y, char stateT1, char flip1, char currentCharT1, char *posT2_x, char *posT2_y, char stateT2,
                          char flip2, char currentCharT2);


    void setTeams(Character* characterT1_1, Character* characterT1_2, Character* characterT2_1, Character* characterT2_2);

    void renderDisconnected() override;

    void addDisconnected(GameObject *disconnected_s);

    void updateTime(char ten, char unity, char round);

    //void updateLife(char )

private:
    vector <Character*> team1;
    vector <Character*> team2;

    LifeManager* lifeManagerTeam1;
    LifeManager* lifeManagerTeam2;

    TimeManager* timeManager;



    Character* getCharacter(string name);

    int currentChar1;
    int currentChar2;

    GameObject* disconnected;
};


#endif //TALLER_MARVEL_CAPCOM_VIEW_FIGHT_H
